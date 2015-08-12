#!/bin/bash
clang++ -O0 -g3 -std=c++11 -Wall -W -lm -lcrypto $@ src/*.cpp -o a.out
