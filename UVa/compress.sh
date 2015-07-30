#!/bin/bash
DIRS=`find . -maxdepth 1 -type d | egrep '[0-9]{5}'`
for DIR in $DIRS; do
  DIR=${DIR#./}
  echo '### Compress directory '$DIR' ###'
  cd $DIR > /dev/null
  ./cleanup.sh > /dev/null
  cd - > /dev/null
  tar Jcf ${DIR}.tar.xz $DIR
done
