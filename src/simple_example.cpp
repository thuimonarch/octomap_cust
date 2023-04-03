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
    if (argc < 2){
      inputFilename = "merged_2.ot";
    }else{
      inputFilename = argv[1];
    }

    AbstractOcTree* tree = octomap::AbstractOcTree::read(inputFilename);
    //cout << "Loaded tree of type " << tree->getTreeType() << "\n";
    if (tree->getTreeType() != "ColorOcTree") {
        cout << "Not ColorOcTree. Exiting" << "\n"; 
        exit(1);
    } 

    cout << "tree read succesfully" << endl;
    
    /*
    ColorOcTree* octree = dynamic_cast<ColorOcTree*>(tree);
    if(octree == nullptr){
        cout << "Dynamic cast failed, octree is nullptr, expect crash" << "\n";
        exit(1);
    }
    cout << "Cast to coloroctree success" <<endl;
    */

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

    // vector<ColorOcTreeNode::Color> rgb;
    // for (ColorOcTree::iterator it = octree->begin(); it != octree->end(); ++it)  {
    //     if(octree->isNodeOccupied(*it)){
    //       //pcl.push_back(it.getCoordinate());
    //       //rgb.push_back(it->getColor());
    //       ColorOcTreeNode* n = octree->search(it.getCoordinate() );
    //       cout << "color: " << n->getColor() << n->getValue()<< endl;
    //     }
    // }
    std::bitset<8> r;
    std::bitset<8> g;
    std::bitset<8> b;

    octree->updateInnerOccupancy();
    ColorOcTreeNode* node = octree->getRoot();
    cout << "root color: " << node->getColor() << endl;
    cout << "avg color: " << node->getAverageChildColor() << endl;
    // ColorOcTreeNode::Color node_color = node->getColor();
    // r = node_color.r;
    // g = node_color.g;
    // b = node_color.b; 
    // char r_char = (char) r.to_ulong();
    // char g_char = (char) g.to_ulong();
    // char b_char = (char) b.to_ulong();
    // cout << "r c: " << r_char << endl;
    // cout << "g c: " << g_char << endl;
    // cout << "b c: " << b_char << endl;

    cout << octree->writeBinary("sample_file.ot") << endl;

  return 0;

}
