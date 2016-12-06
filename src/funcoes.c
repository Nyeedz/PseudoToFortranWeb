#include "../include/funcoes.h"


//FUNÇÃO LIMPAR SAÍDA
void limparSaida(){
	FILE *arquivo = fopen("io/executar.f","w");
	fclose(arquivo);
}

//FUNÇÃO GRAVAR SAÍDA
void gravarSaida(char * texto){
	FILE *arquivo = fopen("io/executar.f","a");
	fprintf (arquivo,"%s",texto);
	fclose(arquivo);


}

//FUNÇÃO SPLIT
int split (char * entrada,Palavras* saida,char * divisor){
	int tam = 0; // quantidade de palavras separadas 
	char *palavra; //palavra recebida pelo metodo strtok(split)
	char out[MAX_FRASE]; //saida

	palavra = strtok (entrada,divisor);
  	while (palavra != NULL)
 	{
    	strcpy(saida[tam++].p,palavra);
   		palavra = strtok (NULL,divisor);
  	}
	
	return tam;
}

//FUNÇÃO INSTACIAR VARIÁVEL 
void instanciarVariavel (char * entrada){
	Palavras palavras[4]; //Array de palavras para split
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");

	//SPLIT
	split(entrada,palavras," ");
	
	
	//Verificando tipo de variável
	if (strncmp(palavras[3].p,"INTEIRO",strlen("INTEIRO")) == 0){
		strcat(out,"INTEGER ");
	}else if (strncmp(palavras[3].p,"REAL",strlen("REAL"))==0){
		strcat(out,"REAL ");
	}

	//Concatenando nome
	strcat(out,palavras[1].p);
	strcat(out,"\n");
		
	gravarSaida(out);
	
}

//FUNÇÃO PARA ATRIBUIÇÃO SIMPLES
void atribuicaoSimples(char * entrada){
	Palavras palavras[4]; //Array de palavras para split
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");
	//SPLIT
	split(entrada,palavras,"<-");
	
	//Concatenando nome
	strcat(out,palavras[0].p);
	strcat(out," = ");
	strcat(out,palavras[1].p);
	strcat(out,"\n");

	gravarSaida(out);

}

//FUNÇÃO PARA OPERAÇÕES ARITMÉTICAS
void operacaoAritmetica (char *entrada){
	Palavras palavras[2]; //Array para armazenar o split feito em <-
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");

	//SPLIT
	split(entrada,palavras,"<-");

	//Concatenações
	strcat (out,palavras[0].p);
	strcat (out," = ");
	strcat (out,palavras[1].p);
	strcat (out,"\n");
	
	gravarSaida(out);	
}

//FUNÇÃO CRIAR ESTRUTURA DO SE
void criarSe(char * entrada){
	Palavras palavras[5]; //Array para armazenar o split feito em ' '
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");
	
	
	//SPLIT
	split(entrada,palavras," ");
	
	//Concatenações	
	strcat (out,"IF( ");
	strcat (out,palavras[1].p);
	strcat (out," ");
	strcat (out,palavras[2].p);	
	strcat (out," ");
	strcat (out,palavras[3].p);
	strcat (out," ) THEN\n");

	gravarSaida(out);

}

//FUNÇÃO CRIAR ESTRUTURA DO LEIA
void criarLeia(char *entrada){
	Palavras palavras[2]; //Array para armazenar o split feito em ' '
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");
	
	//SPLIT
	split(entrada,palavras," ");
	
	//Concatenações
	strcat (out,"READ *, ");
	strcat (out,palavras[1].p);
	strcat (out,"\n");

	gravarSaida(out);
}

//FUNÇÃO CRIAR ESTRUTURA DO ESCREVA
void criarEscreva(char *entrada){
        
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");
	int i;
	int iniAspas = 8, fimAspas = strlen(entrada-1);	
	int has_aspas = 0;
    
    for (i = 0 ; i < strlen(entrada) ; i++){
        if (entrada[i] == '\"')
            has_aspas = 1;        
    }
    
    if (has_aspas == 1){
      	//Concatenações
        strcat (out,"PRINT *, ");
        i = strlen("PRINT *, ")+1;
        for (iniAspas ; iniAspas <= fimAspas ; iniAspas++){
            out[i++] = entrada[iniAspas];
        }         
    }else{
        Palavras palavras[2]; //Array para armazenar o split feito em ' '
        //SPLIT
        split(entrada,palavras," ");
        strcat (out,"PRINT *, ");
        strcat (out,palavras[1].p);
    }
    
	strcat (out,"\n");
	
	gravarSaida(out);

}

//FUNÇÃO PARA CRIAR ESTRUTURA DO ENQUANTO
void criarEnquanto(char * entrada){
	Palavras palavras[5]; //Array para armazenar o split feito em ' '
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");
	
	
	//SPLIT
	split(entrada,palavras," ");
	
	//Concatenações	
	strcat (out,"DO WHILE( ");
	strcat (out,palavras[1].p);
	strcat (out," ");
	strcat (out,palavras[2].p);	
	strcat (out," ");
	strcat (out,palavras[3].p);
	strcat (out," )\n");

	gravarSaida(out);
	

}

//FUNÇÃO PARA CRIAR ESTRUTURA DO PARA
void criarPara(char * entrada){
	Palavras palavras[8]; //Array para armazenar o split feito em ' '
	char out[MAX_FRASE]; //saida
	strcpy(out,"\n");
	
	//SPLIT
	split(entrada,palavras," ");
	
	//contaneções
	strcat (out,"DO ");
	strcat (out,palavras[1].p);
	strcat (out," ");
	strcat (out,palavras[2].p);	
	strcat (out," ");
	strcat (out,palavras[3].p);
	strcat (out,", ");
	strcat (out,palavras[5].p);
	strcat (out, "\n");
	
	gravarSaida(out);
		

}



