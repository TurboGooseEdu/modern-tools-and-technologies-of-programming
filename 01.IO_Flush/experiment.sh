#!/bin/bash

clang bufferization.c

# console
./a.out 1 1
./a.out 0 0
./a.out 1 0
./a.out 0 1

# file
./a.out 0 0 &> 00.txt
./a.out 1 0 &> 10.txt
./a.out 0 1 &> 01.txt
./a.out 1 1 &> 11.txt


