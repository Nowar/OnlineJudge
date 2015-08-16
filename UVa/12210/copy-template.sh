#!/bin/bash
echo "### Sure? This will reset all files under your src/ ... ###"
sleep 3

rm -f src/*.h
rm -f src/*.cpp
cp -a ../template/UVa.h src/
cp -a ../template/UVa.cpp src/
cp -a ../template/main.cpp src/
