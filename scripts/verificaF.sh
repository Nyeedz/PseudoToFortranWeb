#!/bin/bash


cd ../

flex lexicoF.l

gcc -o exe lex.yy.c -lfl

./exe
echo $?


