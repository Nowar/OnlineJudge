#!/bin/bash
OUTFILE=merged.cpp
rm -f $OUTFILE
for FILE in `ls src/*.h`; do
  cat $FILE >> $OUTFILE
done

echo >> $OUTFILE
echo '/* ...................... */' >> $OUTFILE
echo '/* ... Implementation ... */' >> $OUTFILE
echo '/* ...................... */' >> $OUTFILE
echo >> $OUTFILE

for FILE in `ls src/*.cpp`; do
  echo '/* .................................... */' >> $OUTFILE
  echo '/* ... Copied from '$FILE' ... */' >> $OUTFILE
  echo '/* .................................... */' >> $OUTFILE
  cat $FILE | grep -v '^#include' >> $OUTFILE
  echo '' >> $OUTFILE
  echo '' >> $OUTFILE
  echo '' >> $OUTFILE
done
