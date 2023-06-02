#!/bin/bash
g++ -Wall -c FluxStd.cc
g++ -Wall FluxStd.o -lglobes -lgsl -lgslcblas -O3 -o FluxStd
./FluxStd 
rm *.o