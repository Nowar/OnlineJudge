#!/bin/bash
DIRS=`find . -maxdepth 1 -type d | grep uva`
for DIR in $DIRS; do
  DIR=${DIR#./}
  echo '### Cleanup directory '$DIR' ###'
  cd $DIR > /dev/null
  ./cleanup.sh
  cd - > /dev/null
done
