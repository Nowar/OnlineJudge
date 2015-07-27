#!/bin/bash
echo '### Run on input.sample ###'
time ./a.out < input.sample > output 2> error
diff -Naur output.sample output

if [ -f input.udebug -a -f output.udebug ]; then
  echo '### Run on input.udebug ###'
  time ./a.out < input.udebug > output 2> error
  diff -Naur output.udebug output
fi
