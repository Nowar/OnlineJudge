#!/bin/bash
clang++ -fsanitize=address \
        -fsanitize=integer \
        -fsanitize=undefined \
        -O0 -g3 -std=c++11 -Wall -W -lm -lcrypto $@ src/*.cpp -o a.out

#        -fsanitize=thread \
#        -fsanitize=memory \
#        -fsanitize=dataflow \
#        -fsanitize=safe-stack \
