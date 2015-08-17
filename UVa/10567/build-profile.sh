#!/bin/bash
g++ -O2 -g -fno-omit-frame-pointer -pg --coverage -std=c++11 -Wall -W -DONLINE_JUDGE -lm -lcrypto $@ src/*.cpp -o a.out
