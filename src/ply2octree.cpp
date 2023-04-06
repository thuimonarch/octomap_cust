/*
 * OctoMap - An Efficient Probabilistic 3D Mapping Framework Based on Octrees
 * http://octomap.github.com/
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
#include <octomap/ColorOcTree.h>
#include <octomap/OcTree.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <regex>
#include <iterator>
#include <cassert>
#include <vector>

using namespace std;
using namespace octomap;


void print_query_info(point3d query, OcTreeNode* node) {
  if (node != NULL) {
    cout << "occupancy probability at " << query << ":\t " << node->getOccupancy() << endl;
  }
  else 
    cout << "occupancy probability at " << query << ":\t is unknown" << endl;    
}

void printUsage(char* self){
  cerr << "USAGE: " << self << " <InputFile.ply> <OutputFile.ot> optional<binary>\n";
  exit(0);
}


int main(int argc, char* argv[]) {
  if (argc < 3)
    printUsage(argv[0]);
    
  string inputfilename;
  string outputfilename;
  
  bool binary = false;
  
  if (argc == 3){
     inputfilename = argv[1];
     outputfilename = argv[2];
  }else if (string(argv[3])=="binary") {
     binary = true;
     inputfilename = argv[1];
     outputfilename = argv[2];
  }
  
  
  //cout << endl;
  //cout << "input file: " << inputfilename << endl;
  //cout << "output file: " << outputfilename << endl;
  
  //cout << " tree" << endl;
  ColorOcTree tree (0.01);  // create empty tree with resolution 0.01

  char neg_sign = '-';
  fstream fin(inputfilename);
  string line;
  
  // assuming ply in SFM output where propeties are  "x y z nx ny nz r g b class"
  while(getline(fin, line)) 
  {
    line.erase(line.begin(), find_if(line.begin(), line.end(), not1(ptr_fun<int, int>(isspace)))); 
    char first = line[0];
    if (!isdigit(first) && !(first==neg_sign)) continue;

    istringstream ss(line);
    istream_iterator<std::string> begin(ss), end;
    vector<std::string> values(begin, end); 

    // assuming ply in SFM output where propeties are  "x y z nx ny nz r g b class"
    assert(values.size() == 10); 
    
    float x = stof(values[0]);
    float y = stof(values[1]);
    float z = stof(values[2]);
    float r = stoi(values[6]);
    float g = stoi(values[7]);
    float b = stoi(values[8]);
    
    point3d endpoint ((float) x, (float) y, (float) z);
    ColorOcTreeNode* n = tree.updateNode(endpoint, true); // integrate 'occupied' measurement
    n->setColor(r,g,b);
    //cout << n->getColor() << endl;
  }      


  //cout << "writing files" << endl;
  if (binary){
    tree.writeBinary(outputfilename);
    cout << "wrote binary file: " << outputfilename << endl;
  }else{
    tree.write(outputfilename);
    cout << "wrote file " << outputfilename << endl;
  }
  
}
