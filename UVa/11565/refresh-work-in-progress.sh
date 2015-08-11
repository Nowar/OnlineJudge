#!/bin/bash
DIR=`pwd`
CurNum=${DIR##*/}
cp -a ../../WorkInProgress.list ../../WorkInProgress.list2
rm -f ../../WorkInProgress.list
First=1
Written=0
cat ../../WorkInProgress.list2 | while read LINE; do
  LINE=`echo ${LINE} | tr '\t' ' '`
  NUM=${LINE##* }
  TYPE=${LINE%% *}
  if [ "$TYPE" != "UVa" ]; then
    echo -e "${TYPE}\t${NUM}" >> ../../WorkInProgress.list
    continue
  fi

  if [ $NUM -gt $CurNum ] && [ $First -eq 1 ]; then
    echo -e "UVa\t${CurNum}" >> ../../WorkInProgress.list
    Written=1
    First=0
  fi

  if [ $NUM -ne $CurNum ]; then
    echo -e "${TYPE}\t${NUM}" >> ../../WorkInProgress.list
  fi
done
if [ $Written -eq 0 ]; then
    echo -e "UVa\t${CurNum}" >> ../../WorkInProgress.list
fi
rm -f ../../WorkInProgress.list2
