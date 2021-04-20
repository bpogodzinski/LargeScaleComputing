#!/bin/bash

for file in $(find . -iname "prime-numbers-*.cpp")
do
exe_name=$(basename ${file} .cpp)
g++ -O3 -fopenmp ${file} -o ${exe_name}
done