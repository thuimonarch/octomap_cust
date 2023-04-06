/*
 * OctoMap - An Efficient Probabilistic 3D Mapping Framework Based on Octrees
 * https://octomap.github.io/
 *
 * Copyright (c) 2009-2013, K.M. Wurm and A. Hornung, University of Freiburg
 * All rights reserved.
 * License: New BSD
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of Freiburg nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <octomap/octomap.h>
#include <octomap/OcTree.h>
#include <octomap/ColorOcTree.h>

#include <bitset>

using namespace std;
using namespace octomap;


int main(int argc, char** argv) {

    string inputFilename;
    string outputfilename;

    if (argc == 2){
      cout <<  "colored .ot to coloured binary .ot  : " << argv[1] << endl;
      inputFilename = argv[1];
      AbstractOcTree* tree = octomap::AbstractOcTree::read(inputFilename);
      //cout << "Loaded tree of type " << tree->getTreeType() << "\n";
      if (tree->getTreeType() != "ColorOcTree") {
          cout << "Not ColorOcTree. Exiting" << "\n"; 
          exit(1);
      } 
      cout << "tree read succesfully" << endl;
      

      AbstractOccupancyOcTree* abtree = dynamic_cast<AbstractOccupancyOcTree*>(tree);
      if(abtree == nullptr){
          cout << "Dynamic cast failed, octree is nullptr, expect crash" << "\n";
          exit(1);
      }
      cout << "Cast to AbstractOccupancyOcTree success" <<endl;

      //abtree->toMaxLikelihood();
      //abtree->prune();

      ColorOcTree* octree = dynamic_cast<ColorOcTree*>(abtree);
      if(octree == nullptr){
          cout << "Dynamic cast failed, octree is nullptr, expect crash" << "\n";
          exit(1);
      }
      cout << "Cast to coloroctree success" <<endl;


      octree->updateInnerOccupancy();
      ColorOcTreeNode* node = octree->getRoot();
      cout << "root color: " << node->getColor() << endl;
      cout << "avg color: " << node->getAverageChildColor() << endl;

      cout << octree->writeBinary("color_binary.ot") << endl;
  
    }else if (argc == 3){

      cout <<  "coloured binary .ot to  colored .ot " << endl;
      inputFilename = argv[1];  
      outputfilename = argv[2];
      ColorOcTree* octree  = new ColorOcTree(0.01);

      if(!octree->readBinary(inputFilename)){
        cout << "binary read failed" << "\n";
        exit(1);
      }
      cout << "file read success " << inputFilename << endl;
      octree->write(outputfilename);
      cout << "wrote file " << outputfilename << endl;
    

    }else{

      cout << "col binary conversion scratch" << endl;

      string filename = "scratch_col.txt";

      uint8_t r = 201;
      uint8_t g = 202;
      uint8_t b = 203;
      vector<uint8_t> col = {r,g,b};

      cout << "uint8_t input colors" << endl;
      cout << to_string(col[0]) << endl;
      cout << to_string(col[1]) << endl;
      cout << to_string(col[2]) << endl;

      std::bitset<8> rb(r);
      std::bitset<8> gb(g);
      std::bitset<8> bb(b);

      std::bitset<8> child1to4;
      std::bitset<8> child5to8;
      for (unsigned int i=0; i<4; i++) {
        child1to4[i*2] = 1; child1to4[i*2+1] = 0;
        child5to8[i*2] = 0; child5to8[i*2+1] = 1;
      }

      cout << "bitset" << endl;
      cout << child1to4 << endl;
      cout << child5to8 << endl;
      cout << (rb) << endl;
      cout << (gb) << endl;
      cout << (bb) << endl;

      char child1to4n_char = (char) child1to4.to_ulong();
      char child5to8n_char = (char) child5to8.to_ulong();
      char rn_char = (char) rb.to_ulong();
      char gn_char = (char) gb.to_ulong();
      char bn_char = (char) bb.to_ulong();
      cout << "writing char" << endl;
      cout << child1to4n_char << endl;
      cout << child5to8n_char << endl;
      cout << (rn_char) << endl;
      cout << (gn_char) << endl;
      cout << (bn_char) << endl;
      
      std::ofstream binary_outfile( filename.c_str(), std::ios_base::binary);
      if (!binary_outfile.is_open()){
        cout << "Filestream to "<< filename << " not open, nothing written." << endl;
        return false;
      }
      binary_outfile << "# Octomap ColorOcTree binary file"  <<"\n# (feel free to add / change comments, but leave the first line as it is!)\n#\n";
      binary_outfile << "id " << "ColorOcTree" << std::endl;
      binary_outfile << "size "<< "3" << std::endl;
      binary_outfile << "res " << "0.01" << std::endl;
      binary_outfile << "data" << std::endl;
      binary_outfile.write((char*)&child1to4n_char, sizeof(char));
      binary_outfile.write((char*)&child5to8n_char, sizeof(char));
      binary_outfile.write((char*)&rn_char, sizeof(char));
      binary_outfile.write((char*)&gn_char, sizeof(char));
      binary_outfile.write((char*)&bn_char, sizeof(char));
      if (binary_outfile.good()){
        //binary_outfile.close();
        binary_outfile.flush();
        cout << "write done" << endl;

      } else {
        cout << "Output stream not \"good\" after writing tree" << endl;
        return false;
      }

      std::ifstream binary_infile( filename.c_str(), std::ios_base::binary);
      if (!binary_infile.is_open()){
        cout << "Filestream to "<< filename << " not open, nothing read." << endl;
        return false;
      }
      unsigned size;
      double res;
      std::string id;
      
      std::string token;
      bool headerRead = false;
      while(binary_infile.good() && !headerRead) {
        binary_infile >> token;
        if (token == "data"){
          headerRead = true;
          // skip forward until end of line:
          char c;
          do {
            c = binary_infile.get();
          } while(binary_infile.good() && (c != '\n'));
        }
        else if (token.compare(0,1,"#") == 0){
          // comment line, skip forward until end of line:
          char c;
          do {
            c = binary_infile.get();
          } while(binary_infile.good() && (c != '\n'));
        }
        else if (token == "id")
          binary_infile >> id;
        else if (token == "res")
          binary_infile >> res;
        else if (token == "size")
          binary_infile >> size;
        else{
          cout << "Unknown keyword in OcTree header, skipping: "<<token << endl;
          char c;
          do {
            c = binary_infile.get();
          } while(binary_infile.good() && (c != '\n'));
        }
      }
      cout << "header read completed: " << id  << " | "  << res << " | " << size << endl;
        
      char child1to4_char;
      char child5to8_char;
      char r_char;
      char g_char;
      char b_char;    

      binary_infile.read((char*)&child1to4_char, sizeof(char));
      binary_infile.read((char*)&child5to8_char, sizeof(char));
      binary_infile.read((char*)&r_char, sizeof(char));
      binary_infile.read((char*)&g_char, sizeof(char));
      binary_infile.read((char*)&b_char, sizeof(char));

      cout << "read char" << endl;
      cout << child1to4_char << endl;
      cout << child5to8_char << endl;
      cout << r_char << endl;
      cout << g_char << endl;
      cout << b_char << endl;
      binary_infile.close();

      std::bitset<8> child1to4c ((unsigned long long) child1to4_char);
      std::bitset<8> child5to8c ((unsigned long long) child5to8_char);
      std::bitset<8> rc ((unsigned long long) r_char);
      std::bitset<8> gc ((unsigned long long) g_char);
      std::bitset<8> bc ((unsigned long long) b_char);
      cout << "read bitset" << endl;
      cout << child1to4c << endl;
      cout << child5to8c << endl;
      cout << rc << ","  << gc << "," << bc << endl;

      uint8_t rci = rc.to_ulong();
      uint8_t gci = gc.to_ulong();
      uint8_t bci = bc.to_ulong();  

      cout << "output colors" << endl;
      cout << to_string(rci) << endl;
      cout << to_string(gci) << endl;
      cout << to_string(bci) << endl;

    }

  return 0;

}

