#!/bin/bash


cd ../

flex lexico.l

gcc -o exe include/funcoes.h src/funcoes.c lex.yy.c -lfl

./exe
echo $?


