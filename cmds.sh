#!/bin/sh

export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH

filename=merged_2_7
data_dir="./data/${filename}"
mkdir -p $data_dir

#echo 'encode ply to octree'
#time bin/ply2octree  "${data_dir}/${filename}.ply"  "${data_dir}/${filename}.ot"
#echo /opt/ros/noetic/bin/octovis ${data_dir}/${filename}.ot 

#echo 
#echo 'decode ColorOctree to colored ply'
#time bin/coloroctree2pointcloud "${data_dir}/${filename}.ot" "${data_dir}/${filename}_ot.ply"

#echo
#echo "scoring ${data_dir}/${filename}_ot.ply against ${data_dir}/${filename}.ply"
#time bin/pc_error_d -a "${data_dir}/${filename}.ply" -b "${data_dir}/${filename}_ot.ply" --hausdorff=1 --resolution=1024 --color=1 >"${data_dir}/${filename}_ot_ply_pcerror.txt"

echo
echo 'encode ply to colbinary octree'
time bin/ply2octree "${data_dir}/${filename}.ply"  "${data_dir}/${filename}_colbinary.ot" binary

echo 
echo 'decode binary octree to ply'
time bin/colbinaryoctomap2ply "${data_dir}/${filename}_colbinary.ot" "${data_dir}/${filename}_colbinary_ot.ply"

echo
echo "scoring ${data_dir}/${filename}_colbinary_ot.ply against ${data_dir}/${filename}.ply"
time bin/pc_error_d -a "${data_dir}/${filename}.ply" -b "${data_dir}/${filename}_colbinary_ot.ply" --hausdorff=1 --resolution=1024  --color=1 >"${data_dir}/${filename}_colbinary_ot_ply_pcerror.txt"

