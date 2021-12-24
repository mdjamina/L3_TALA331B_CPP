#!/bin/sh
chemin=$(dirname $0)

INCLUDE_L=$chemin/src/include
SOURCE_L=$chemin/src/sources

g++ -std=c++11 -Wall -pedantic -o $2 -I$INCLUDE_L $SOURCE_L/classecar.cpp $1
