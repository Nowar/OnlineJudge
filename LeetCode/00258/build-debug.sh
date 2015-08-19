#!/bin/bash
clang++ -O0 -g3 -std=c++98 -pedantic -Wall -W -lm -lcrypto $@ src/*.cpp -o a.out
