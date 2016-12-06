#!/bin/bash


cd ../
cd io
if [ -f executar.f ]; then
   mv executar.f executar.f90
fi


gfortran -o exe executar.f90
echo $?

#./exe



 
