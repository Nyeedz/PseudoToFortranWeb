%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "include/funcoes.h"
	
	int cont_error = 0 ;
    
      

%}

numero			\-?[0-9]+(\.[0-9]+)?
operadorA		(\+|\-|\*|\/)
operadorL 		((\!\=)|(\<\=)|(\>\=)|(\=\=)|\<|\>)
espaco			[ \t]+
whitespace 		[ \t\r\n]+
dado			([a-zA-Z]+|(\-?[0-9]+(\.[0-9]+)?))+

%%

(INICIO)									  			                                        {gravarSaida("PROGRAM INTER\n");}
(var){espaco}{dado}{espaco}\:{espaco}(INTEIRO|REAL)							                    {instanciarVariavel(yytext);}
{dado}{espaco}\<\-{espaco}({dado}{espaco}{operadorA}{espaco}{dado})		       	                {operacaoAritmetica(yytext);}
{dado}{espaco}\<\-{espaco}{dado}									                            {atribuicaoSimples(yytext);}
(LEIA){espaco}{dado}										                   	                {criarLeia(yytext);}
(ESCREVA){espaco}.*											                                    {criarEscreva(yytext);} 
(SE){espaco}{dado}{espaco}{operadorL}{espaco}{dado}{espaco}(ENTAO)  			                {criarSe(yytext);}
(FIM_SENAO)												                                        {}
(FIM_SE)												                                        {gravarSaida("\nENDIF\n");}
(SENAO)													                                        {gravarSaida("\nELSE\n");}
(ENQUANTO){espaco}{dado}{espaco}{operadorL}{espaco}{dado}{espaco}(FACA)			                {criarEnquanto(yytext);}
(FIM_ENQUANTO)												                                    {gravarSaida("ENDDO");}
(PARA){espaco}{dado}{espaco}\={espaco}{dado}{espaco}(ATE){espaco}{dado}{espaco}(FACA)   		{criarPara(yytext);}
(FIM_PARA)												                                        {gravarSaida("ENDDO");}
(FIM)													                                        {gravarSaida("\nEND PROGRAM INTER\n");}
{whitespace}												                                    {}
.													                                            {cont_error++;}


%%	



int main (){

	//Limpando saída de arquivos
	limparSaida();
	//Definindo entrada padrão (arquivo txt)
	yyin = fopen("io/in.txt", "r");
	//Executando analisar léxico
	yylex();

	if (cont_error > 0){
		return 1;
	}
	
	return 0;
}		
	
