%{
	#include <stdlib.h>
	#include <stdio.h>
	
	int cont_error = 0 ;

%}

numero			\-?[0-9]+(\.[0-9]+)?
operadorA		(\+|\-|\*|\/)
operadorL 		((\!\=)|(\<\=)|(\>\=)|(\=\=)|\<|\>)
espaco			[ \t]+
whitespace 		[ \t\r\n]+
dado			([a-zA-Z]+|(\-?[0-9]+(\.[0-9]+)?))+

%%

(PROGRAM){espaco}{dado}									                     	            {}
(INTEGER|REAL){espaco}{dado}										                        {}
{dado}{espaco}\={espaco}{dado}{espaco}{operadorA}{espaco}{dado}				             	{}
{dado}{espaco}\={espaco}{dado}								                   	            {}
(READ){espaco}\*\,{espaco}{dado}								             		        {}
(PRINT){espaco}\*\,{espaco}.*								               		            {} 
(IF)\({espaco}{dado}{espaco}{operadorL}{espaco}{dado}{espaco}\){espaco}(THEN)	            {}
(ENDIF)												                                        {}
(ELSE)												                                      	{}
(DO){espaco}(WHILE)\({espaco}{dado}{espaco}{operadorL}{espaco}{dado}{espaco}\)		        {}
(ENDDO)											                                            {}
(DO){espaco}{dado}{espaco}\={espaco}{dado}\,{espaco}{dado}					             	{}
(END){espaco}(PROGRAM){espaco}{dado}									        	        {}
{whitespace}											                         	        {}
.			                                										        {cont_error++;}


%%	

int main (){

	//Definindo entrada padrão (arquivo txt)
	yyin = fopen("io/executar.f", "r");
	//Executando analisar léxico
	yylex();

	if (cont_error > 0){
		return 1;
	}
	
	return 0;
}		
