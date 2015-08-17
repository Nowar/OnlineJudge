#!/bin/bash
DIR=`pwd`
CurNum=${DIR##*/}
cp -a ../../WorkInProgress.list ../../WorkInProgress.list2
rm -f ../../WorkInProgress.list
Written=0
cat ../../WorkInProgress.list2 | while read LINE; do
  LINE=`echo ${LINE} | tr '\t' ' '`
  NUM=${LINE##* }
  TYPE=${LINE%% *}
  if [ "$TYPE" != "UVa" ]; then
    echo -e "${TYPE}\t${NUM}" >> ../../WorkInProgress.list
    continue
  fi

  if [ $NUM -gt $CurNum ] && [ $Written -eq 0 ]; then
    echo -e "UVa\t${CurNum}" >> ../../WorkInProgress.list
    Written=1
  fi

  if [ $NUM -ne $CurNum ]; then
    echo -e "${TYPE}\t${NUM}" >> ../../WorkInProgress.list
  fi
done

rm -f ../../WorkInProgress.list2
