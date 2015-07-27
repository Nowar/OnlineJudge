#!/bin/bash
echo '### Run on input.sample ###'
./a.out input.sample > output 2> error
if [ $? -ne 0 ]; then
  exit 1
fi
diff -Naur output.sample output

if [ -f input.udebug -a -f output.udebug ]; then
  echo '### Run on input.udebug ###'
  ./a.out input.udebug > output 2> error
  if [ $? -ne 0 ]; then
    exit 1
  fi
  diff -Naur output.udebug output
fi
