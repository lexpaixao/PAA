/* Autor: Alexsandro  Paixão*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define tam 100
#define intervalo 1000
void dados(){
	printf("\nInforme uma informacao a ser criptografada\n");
}
void dados1(){
	printf("\n--------------------------------------------------------------------------\n");
	printf("\n\tDigite 1 para Criptografar \n\tDigite 2 Para descriptografar \n\t0 Sair \n");
	printf("\n--------------------------------------------------------------------------\n");
}
 
 int produtodechaves(int novom, int novon){
 	return novom*novon;
 }
 
 int encontraprimo(int a) {
    while (a > 1) {
        int d, x = 0;

        for (d = 2; d <= a/2; d++) {
            if (a % d == 0) {
                x++;
            }
        }

        if (x == 0) {
            return a;
        }

        a++;
    }
    return -1;
}

 double medirDesempenho(int (*funcao)(int), int argumento) {
    clock_t inicio, fim;
    double tempo_execucao;
	int resultado=funcao(argumento); 
    tempo_execucao = ((double)(resultado)) / CLOCKS_PER_SEC;
    
    return tempo_execucao;
}

double medirDesempenhoa(int (*funcao)(int, int), int argumentoa, int argumentob) {
    clock_t inicio, fim;
    double tempo_execucao;
	
	int resultado = funcao(argumentoa, argumentob);
	tempo_execucao = ((double)(resultado)) / CLOCKS_PER_SEC;
	
    return tempo_execucao;
}
 int calculodiferenca(int valora , int valorb ){
 	int res;
 	res=(valora-valorb);
 	return res;
 }
 
 void descriptografar(char msg[tam], int x,int chaveb, int res){
 	if(x%chaveb==res){
 		printf("\n+++++++++++++++++++++++++\n\nMensagem Descriptografada\n\n\t%s\n\n+++++++++++++++++++++++++\n",msg);
	 }
	 else{
	 	printf("Chave incorreta\n");
	 }
	 return;
 }
 
int main(){
	int sorteio,primoa,primob,multij,multia,multiz,difere,res,key,key1,teste;
	char cripto[tam];
	double a,b,b1,b2,b3,c;
	dados1();
	scanf("%d",&res);
	getchar();
	
	do{
		switch(res){
		case 0:
		printf("Saindo...\n");
		break;
		case 1:
		dados();
		scanf("%[^\n]s",cripto);
	    srand(time(NULL));
		sorteio = rand() % intervalo + 1;
		a= medirDesempenho(encontraprimo,sorteio);
		
		
		primoa=encontraprimo(sorteio);
		primob=encontraprimo(primoa+1);
		multia=produtodechaves(primoa,primob);
		multiz=produtodechaves(primoa-1,primob-1);
		difere=calculodiferenca(multia,multiz);
		multij=produtodechaves(primoa,difere);
		
		b=medirDesempenhoa(produtodechaves,primoa,primob);
		b1=medirDesempenhoa(produtodechaves,primoa-1,primob-1);
		b2=medirDesempenhoa(produtodechaves,primoa,difere);
		b3=medirDesempenhoa(calculodiferenca,multia,multiz);
		printf("\n%.2f= milisegundos\n",a+b+b1+b2+b3);
		
		teste=multij%primob;
	   	printf("\nValor das chaves publicas chave(1)=%d chave(2)= %d\n",primob,teste);
	   
		break;
		case 2:
		printf("Informe as chaves publicas geradas\n");
		scanf("%d %d",&key1,&key);
		descriptografar(cripto,multij,key1,key);
		break;
		default:
		printf("Opcao Invalida!\n");
		break;	
		
		}
		
		 dados1();  
        scanf("%d", &res);
		printf("\n");
        getchar();
		
	}while(res!=0);
	

	
	return 0;
	
}

