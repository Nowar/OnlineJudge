#!/bin/bash
rm -f merge.cpp
for FILE in `ls src/*.h`; do
  cat $FILE >> merge.cpp
done

echo >> merge.cpp
echo '/* ...................... */' >> merge.cpp
echo '/* ... Implementation ... */' >> merge.cpp
echo '/* ...................... */' >> merge.cpp
echo >> merge.cpp

for FILE in `ls src/*.cpp`; do
  cat $FILE | grep -v '^#include' >> merge.cpp
done
