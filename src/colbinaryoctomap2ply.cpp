#include <octomap/octomap.h>
#include <octomap/ColorOcTree.h>
#include <sstream>

using namespace std;
using namespace octomap;


void printUsage(char* self){
  cerr << "USAGE: " << self << " <InputColoredBinaryFile.ot> <OutputPointCloudFile.ply>\n";
  cerr << "This tool creates a point cloud (.ply) of the occupied cells\n";
  cerr << "note that the input file needs to be non binary containing a ColorOcTree object.\n";
  exit(0);
}


int main(int argc, char** argv) {
    
    if (argc != 3)
    printUsage(argv[0]);

    string inputFilename = argv[1];
    string outputFilename = argv[2];
    bool outputIsPly = outputFilename.substr(outputFilename.find_last_of(".") + 1) == "ply"; 
    
    // check if valid output file extension
    if (!outputIsPly){
        cerr << "Invalid output file type. Only .ply\n";
        exit(0);
    }


    ColorOcTree* octree  = new ColorOcTree(0.01);

    if(!octree->readBinary(inputFilename)){
      cout << "binary read failed" << "\n";
      exit(1);
    }
    
    //cout << "file read success " << inputFilename << endl;
    
    unsigned int maxDepth = octree->getTreeDepth();
    // expand collapsed occupied nodes until all occupied leaves are at maximum depth
    vector<ColorOcTreeNode*> collapsed_occ_nodes;
    do {
        collapsed_occ_nodes.clear();
        for (ColorOcTree::iterator it = octree->begin(); it != octree->end(); ++it)  { 
            if(octree->isNodeOccupied(*it) && it.getDepth() < maxDepth){
                collapsed_occ_nodes.push_back(&(*it));
            }
        }//end for loop of each node
        for (vector<ColorOcTreeNode*>::iterator it = collapsed_occ_nodes.begin(); it != collapsed_occ_nodes.end(); ++it) {
            octree->expandNode(*it);
        }
        //cout << "expanded " << collapsed_occ_nodes.size() << " nodes" << "\n";
    } while(collapsed_occ_nodes.size() > 0);
    
    
    // get points and colors
    vector<point3d> pcl;
    vector<ColorOcTreeNode::Color> rgb;
    for (ColorOcTree::iterator it = octree->begin(); it != octree->end(); ++it)  {
        if(octree->isNodeOccupied(*it)){
          pcl.push_back(it.getCoordinate());
          rgb.push_back(it->getColor());
        }
    }

    delete octree;


    //Writing to file 
    //ofstream f(outputFilename.c_str(), ofstream::out);
    //faster than ofstream but need to make sure all the data can fit. 
    // Should not be an issue for the current use case 
    //if need to work around the the size limit, can write to a buffer first then flush to file when limit is reached.     
    stringstream f(stringstream::out); 
    
    f << "ply"  << "\n"
    << "format ascii 1.0"  << "\n"
    << "comment"  << "\n"
    << "element vertex " << pcl.size() << "\n" //pcl.size()
    << "property float x" << "\n"
    << "property float y" << "\n"
    << "property float z" << "\n"
    << "property uchar red"  << "\n"
    << "property uchar green"  << "\n"
    << "property uchar blue" << "\n"
    << "end_header" << "\n";


    for (size_t i = 0; i < pcl.size(); i++){
        f << pcl[i].x() << " " << pcl[i].y() << " " << pcl[i].z() << " " <<  to_string(rgb[i].r) << " " <<  to_string(rgb[i].g) << " " <<  to_string(rgb[i].b) << "\n";
    }
    //f.close();
    
    ofstream outfile;
    outfile.open(outputFilename,ofstream::out);
    outfile.write(f.str().c_str(), f.str().length());
    outfile.close();
    cout << "wrote file " << outputFilename << endl;

    return 0;
}