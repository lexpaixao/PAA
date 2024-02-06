#include <stdio.h>
#include <string.h>
#include<stdbool.h>

int main() {
    FILE *arquivo;
    char linha[1000];

    arquivo = fopen("algoritmo.c", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numeroDeLoopsFor = 0, numeroDeLoopsWhile = 0, numeroDeelseif = 0;
    int dentroDeMain = 0, numeroDeprintscanf = 0, numerovariaveis = 0,numeroatribuicoes = 0, passos = 0;
    int chavesAbertas = 0, resultado = 0;
    int linhaAtual = 0, dentroDeloop=0;
    bool aninhados=false, log=false;
	
	printf("\n------------------------------------------\n");
	
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linhaAtual++;
		
        printf("%s", linha);
        

        if (strstr(linha, "int main(") != NULL) {
            dentroDeMain = 1;
        }

        if ((strstr(linha, "printf(") != NULL) || (strstr(linha, "scanf(") != NULL)|| (strstr(linha, "fgets( ") != NULL) || (strstr(linha, "gets( ") != NULL)
		|| (strstr(linha, "puts( ") != NULL)|| (strstr(linha, "putchar( ") != NULL)) {
            numeroDeprintscanf++;
        }

        if (strstr(linha, "for(") != NULL) {
            numeroDeLoopsFor++;
            dentroDeloop=1;
            chavesAbertas++;
        }

        if ((strstr(linha, "do{ ") != NULL) || (strstr(linha, "while(") != NULL)) {
            numeroDeLoopsWhile++;
            dentroDeloop=1;
            chavesAbertas++;
        }

        if ((strstr(linha, "if(") != NULL) || (strstr(linha, "else(") != NULL)) {
            numeroDeelseif++;
            chavesAbertas++;
        }

        if ((strstr(linha, "float ") != NULL) || (strstr(linha, "char ") != NULL) || (strstr(linha, "int ") != NULL)|| (strstr(linha, "double ") != NULL)
		|| (strstr(linha, "double ") != NULL)|| (strstr(linha, "bool ") != NULL)) {
            numerovariaveis++;
        }
        
        if ((strstr(linha, "++") != NULL) || (strstr(linha, "--") != NULL) || (strstr(linha, "=") != NULL)) {
            numeroatribuicoes++;
        }
        
		if((strstr(linha, "*= ") != NULL) || (strstr(linha, "-= ") != NULL) ||(strstr(linha, "+= ") != NULL)||(strstr(linha, "/= ") != NULL)){
			numeroatribuicoes++;
		}

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '{') {
                chavesAbertas++;
            }

            if (linha[i] == '}') {
            	printf("%d  ",chavesAbertas);
               if (chavesAbertas <= 0) {
            printf("Erro: Chave de fechamento sem correspondência com chave de abertura na linha %d.\n", linhaAtual);
            fclose(arquivo);
            return 1;
        }
        chavesAbertas--;
            }
        }
        if(dentroDeloop==1 &&  strstr(linha, "/2") != NULL){
		log=true;
		}
        
        if(dentroDeloop==1 &&  strstr(linha, "{") != NULL){
        	if(strstr(linha, "for(") != NULL || strstr(linha, "do{") != NULL || strstr(linha, "while(") != NULL){
        	//aninhados
        	aninhados=true;
			}
        	if (dentroDeloop && strstr(linha, "}") != NULL) {
            // Se está dentro de um loop e encontra uma chave fechando, sai do modo de dentro de loop
            dentroDeloop = 0;
        }
		}
    }

    fclose(arquivo);
    
	printf("\n------------------------------------------\n");
	
   if (chavesAbertas != 0) {
   	passos=numeroDeelseif+numeroDeprintscanf+(numerovariaveis-dentroDeMain)+numeroatribuicoes;
    resultado=(numeroDeLoopsFor+numeroDeLoopsWhile);
    
    printf("\n%d loops for aninhados.\n", numeroDeLoopsFor);
    printf("%d loops while/dowhile encontrados.\n", numeroDeLoopsWhile);
    printf("%d blocos if/else encontrados.\n", numeroDeelseif);
    printf("%d variáveis declaradas.\n", numerovariaveis-dentroDeMain );
    printf("%d print/scanf encontrados.\n", numeroDeprintscanf);
    printf("%d atribuicoes encontrados.\n", numeroatribuicoes);
    printf("%d Passos.\n",passos );
    
	
    if(aninhados==true){
    	printf("resposta.\n\nBigO(n^)\nBigO= (n^%d)+%d \n",resultado,passos);
	}
	else if(log==true){
		printf("resposta.\n\nBigOLog(n)\nBigO= Log(%d)+%d \n",resultado,passos);
	}
	else if(aninhados==false && log==aninhados){
	printf("resposta.\n\nBigO(n)\nBigO= (%d)+%d \n",resultado,passos);
	}
    
    
} else {
    printf("Erro: Algumas estruturas não têm correspondência com suas chaves de fechamento. Chaves em aberto.  %d\n",chavesAbertas);
    return 1;
}

    return 0;
}
