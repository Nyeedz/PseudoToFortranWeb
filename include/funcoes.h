#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 25
#define MAX_FRASE 100


typedef struct Palavras{
	char p[MAX_PALAVRA];
}Palavras;


//Função para criação de instancias de variáveis
void instanciarVariavel (char *);

//Função para atribuição simples
void atribuicaoSimples(char *);


//Função split - Divisão de strings
int split (char *,Palavras*,char *);

//Função para limpar arquivo de saída
void limparSaida();

//Função gravar no arquivo de saída
void gravarSaida(char *);

//Função para operações aritméticas
void operacaoAritmetica (char *);

//Função para criar estrutura do 'se'
void criarSe(char *);

//Função para criar estrutura do leia
void criarLeia(char *);

//Função para criar a estrutura do escreva
void criarEscreva(char *);

//Função para criar a estrutura do enquanto
void criarEnquanto(char *);

//Função para criar a estrutura do para
void criarPara(char *);


#endif

