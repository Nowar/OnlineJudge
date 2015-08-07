#!/bin/bash
DIRS=`find . -maxdepth 1 -type d | egrep [0-9]{5}`
for DIR in $DIRS; do
  DIR=${DIR#./}
  echo '### Cleanup directory '$DIR' ###'
  cd $DIR > /dev/null
  ./cleanup-binaries.sh
  cd - > /dev/null
done
