#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define primeiros 16
#define inici 0
/*Alexsandro Paixao
Com base na seguinte tabela do brasileirão série A, construa os seguintes algoritmos recursivos
Retornar o Nome e Posição do Time com base na quantidade de pontos
Exibir os 5 primeiros colocados
Exibir os 5 últimos colocados
Exibir a diferença de pontos entre os 5 primeiros
Exibir a diferença de pontos entre os 5 últimos
Reordenar a tabela para exibir apenas metade dos times com base na quantidade de pontos
*/

typedef struct {
	char nome[30];
	int pontos,posicao,x;
}clube;

void dados(){
	printf("\n\t--------------------------------------\n");
	printf("\n\t0-SAIR\n\t1-Busca por pontos\n\t2-Exibir 5 primeiros\n\t3-Exibir 5 ultimos\n\t4-Diferenca de pontos 5 primeiros\n\t5-Diferenca de pontos 5 ultimos\n\t");
	printf("6-Reordena por pontos e exibe metade\n\t");
	printf("--------------------------------------\n");
}

int Diferencag5(clube times[], int id, int tamtotal){
	if(id>tamtotal){
		return times[id].pontos- times[id+1].pontos;
	}
	
	Diferencag5(times,id+1,tamtotal);
}

int Diferencazona(clube times[], int id, int tamtotal){
	if(id<tamtotal){
		return times[tamtotal].pontos- times[id].pontos;
	}
	
	Diferencazona(times,id+1,tamtotal);
}


void exibirg5(clube times[], int id, int tamtotal){
	if(id>tamtotal){
		return;
	}
	else{
	printf("Posicao|%d|-(%s) = | %d |\n",times[id].posicao+1,times[id].nome, times[id].pontos);		
	 }
	 
	 exibirg5(times, id+1,tamtotal);
}

void exibirzona(clube times[], int id, int tamtotal){
	if(id>tamtotal){
		return;
	}
	else{
	printf("Posicao|%d|-(%s) = | %d |\n",times[id].posicao+1,times[id].nome, times[id].pontos);		
	 }
	 
	 exibirzona(times, id+1,tamtotal);
}

void trocarTimes(clube *a, clube *b) {
    clube temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(clube times[], int inicio, int fim) {
    int pivo = times[fim].pontos;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (times[j].pontos >= pivo) {
            i++;
            trocarTimes(&times[i], &times[j]);
        }
    }

    trocarTimes(&times[i + 1], &times[fim]);
    return i + 1;
}

void quicksort(clube times[], int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particionar(times, inicio, fim);

        quicksort(times, inicio, indicePivo - 1);
        quicksort(times, indicePivo + 1, fim);
    }
}

void reordenat(clube times[], int id, int tamtotal){
    quicksort(times, id, tamtotal - 1);
}

void exibirMetadeDosTimes(clube times[], int tamtotal) {
    int metade = tamtotal / 2;
    for (int i = 0; i < metade; i++) {
        printf("Posicao|%d|-(%s) = | %d |\n", times[i].posicao+1, times[i].nome, times[i].pontos);
    }
}

void buscaporpontos(clube times[],int id, int pontuacao, int tamtotal, int x){
	if(times[id].pontos==pontuacao && id<=tamtotal){	
		printf("Posicao|%d|-(%s)\n",times[id].posicao+1,times[id].nome);
		x=1;
	}
	if(id>tamtotal){
		printf("teste boolean %d",x);
		 if(x==0){
		printf(" Time nao encontrado pela pontuacao |%d|", pontuacao);
	}
		return ;
	}
	
	buscaporpontos(times,id+1,pontuacao,tamtotal,x);
}
int main(){
		int qntdtimes, gfive, res, res1,op,pontos;
		clube tabela[]={ {"Palmeiras,",63,0},{"Flamengo",63,1},{"Botafogo",62,2},{"Atletico Mineiro",60,3},{"Gremio",59,4},
		{"Bragantino",59,5},{"Fluminense",53,6},{"Atletico-PR",52,7},{"Cuiaba",48,8},{"Sao Paulo",47,9},
		{"Internacional",46,10},{"Fortaleza",45,11},{"Cruzeiro",44,12},{"Corinthians",44,13},{"Santos",43,14},
		{"Vasco",42,15},{"Bahia",41,16},{"Goias",35,17},{"Coritiba",29,18},{"America MG",21,19}
		};
		
		 
		 qntdtimes=sizeof(tabela)/sizeof(clube);
		 gfive=qntdtimes- primeiros;
		do{
		dados();
		scanf("%d", &op);
		
		switch(op){
			
			case 0:
			printf("Saindo...");
			break;
			
			case 1:
			printf("Informe a pontuacao");
			scanf("%d",&pontos);
			buscaporpontos(tabela,inici ,pontos,qntdtimes,inici );
			break;
			case 2:
			exibirg5(tabela,inici,gfive);
				
			break;
			case 3:
			exibirzona(tabela,primeiros-1,qntdtimes-1);
			break;
			case 4:
			res=Diferencag5(tabela,inici,gfive);
			if(res>-1){
				printf("A diferenca entre os 5 primeiros colocados e de (%d) pontos\n", res);
			}
				
			break;
			case 5:
			res1=Diferencazona(tabela,primeiros-1,qntdtimes-1);		
			if(res1<-1){
				printf("A diferenca entre os 5 ultimos colocados e de (%d) pontos\n", res1*(-1));
			}
			break;
			case 6:
			reordenat(tabela, inici, qntdtimes);
			exibirMetadeDosTimes(tabela,qntdtimes);
				
			break;
			default:
			printf("Opcao invalida!");
			break;
			
		}
		
		}while(op!=0);
			
	
}
