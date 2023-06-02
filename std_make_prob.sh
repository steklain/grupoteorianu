#!/bin/bash
g++ -Wall -c ProbStd.cc
g++ -Wall ProbStd.o -lglobes -lgsl -lgslcblas -O3 -o ProbabilityStd
./ProbabilityStd 
rm *.o