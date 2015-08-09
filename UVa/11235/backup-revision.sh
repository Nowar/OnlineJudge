#!/bin/bash
if [ ! -d src/rev ]; then
  mkdir -p src/rev
fi

NUM=`ls src/rev/ | sort -n | tail -n 1`
NUM=${NUM##0}
if [ -z "$NUM" ]; then
  NUM="01"
else
  NUM=$(( $NUM + 1 ))
  if [ $NUM -lt 10 ]; then
    NUM=`printf '%d' 0`$NUM
  fi
fi

mkdir -p src/rev/$NUM
cp -a src/*.cpp src/rev/$NUM/
cp -a src/*.h src/rev/$NUM/

echo "Backup current source files to src/rev/$NUM"
