#!/usr/bin/env bash
echo "gcc $1.cpp -o $1"
g++ $1.cpp -o $1
./$1
