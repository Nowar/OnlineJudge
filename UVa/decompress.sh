#!/bin/bash
FILES=`find . -maxdepth 1 -type f | egrep '[0-9]{5}.tar.xz'`
for FILE in $FILES; do
  FILE=${FILE#./}
  DIR=${FILE%.tar.xz}
  echo '### Decompress file '$FILE' ###'
  rm -rf $DIR > /dev/null
  tar Jxf $FILE
done
