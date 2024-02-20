/*
Alunos: Alexsandro Paixao - Yuri 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
		
		//Entrada de dados
int constante( int k){
		int resp;
		printf("\nA equacao tem constante? \n\t------- \n\t1- Sim\n\t0-Nao \n\t------ \n");
		scanf("%d",&resp);
		if(resp==1){
			printf("\nInforme o valor da constante: \n");
			scanf("%d",&k);
			return k;
		}
		else{
			return 1;
		}
	
}

int termo_potencia(float variavel, int *potencia){
	printf("o valor do termo %.1f \n",variavel);
	printf("Se nao houver potencia indique (1)\n  ");
	scanf("%d",potencia);
}

int Dados(int termos){
		printf("Informe quantos termos tem funcao que limitam a area.\n");
		scanf("%d",&termos);
		return termos;
	
}

float Intervaloa(float x){
		printf("Informe o intervalo da area.\n");
		scanf("%f",&x);
		return x;
}

			//Calculos
int calculo(float x, int potencia){
	return pow(x,potencia);
	}

int integracaopolinomio(float valor, int potencia){
		 int potencianova=potencia+1;
		return potencianova;
}

void simplificando(float resposta, int base, int divisor ){
	float final;
	int end;
	
	if(fmod(resposta,divisor)==0 && base%divisor==0){
		final=(resposta/divisor);
		end=(base/divisor);
		printf("\nSimplificando...\n");
		printf("....................................\n");
		printf("\nResposta simplificada=((%.0f)/%d) Unidade de area\n ",final,end);
		printf("....................................\n");
		return;
	}
	else if(resposta==1 || divisor>resposta){
		return;
	}
	else{
	simplificando(resposta,base,divisor+1 );
	}
	
	
	
}

void calculandointegral1(int base,int base1,int base2,int x1,int x2,int x3, char sinal[], int y1,int y2,int y3,char sinal1[], int con){
	int calcul, resultado, resultado1,calcul1;
	int a1,a2,a3,p,b1,b2,b3;
	float resposta_final;
	int m1,m2,m3,f,g;
	switch(sinal[0]){
		
		
		case '+':
			p=base*base1*base2;
			a1=(p/base);
			a2=(p/base1);
			a3=(p/base2);
			b1=a1*y1;
			b2=a2*y2;
			b3=a3*y3;
			m1=a1*x1;
			m2=a2*x3;
			m3=a3*x2;
			calcul= m1+m2;
			resultado=calcul/p;
			calcul1= b1+b2;
			resultado1=calcul1/p;
				
				if(sinal1[0]=='-'){
				f=calcul-m3;
				g=calcul1-b3;
				resposta_final=((f-g)*con);
				}
				else if(sinal1[0]=='+'){
				f=calcul+m3;
				g=calcul1+b3;
				resposta_final=((f-g)*con);
				}
				else if(sinal1[0]=='*'){
				f=calcul*m3;
				g=calcul1*b3;
				resposta_final=((f-g)*con);
				}
		break;
		
		case '-':
		p=base*base1*base2;
		a1=(p/base);
		a2=(p/base1);
		a1=(p/base2);
		b1=a1*y1;
		b2=a2*y2;
		b3=a3*y3;
		m1=a1*x1;
		m2=a2*x3;
		m3=a3*x2;
		
		calcul= m1-m2;
		resultado=calcul/p;
		calcul1= b1-b2;
		resultado1=calcul1/p;
		
		if(sinal1[0]=='-'){
			f=calcul-m3;
			g=calcul1-b3;
			resposta_final=((f-g)*con);
			}
			else if(sinal1[0]=='+'){
			f=calcul+m3;
			g=calcul1+b3;
			resposta_final=((f-g)*con);
			}
			else if(sinal1[0]=='*'){
			f=calcul*m3;
			g=calcul1*b3;
			resposta_final=((f-g)*con);
			}
			
		break;
		
		default:
		printf("ERRO!!...\n");
		break;
		
		}
		
	 if(fmod(resposta_final,p)==0){
	  	printf("Resultado: %f unidade de area\n", resposta_final/p);
	  }
	  else{
	  	printf("Resultado: ((%.0f)/%d) unidade de area\n", resposta_final,p);
	  	if(resposta_final>1 && p>1){
	  		simplificando(resposta_final,p,2);
		  }
	  }		
	
}

void calculandointegral(int base1, int base2, int res1, int res2, char sinal[], int rs, int rs1, int con) {
    float resultado_float,calculo;
    if (base1 == base2) {
        switch (sinal[0]) {
            case '0':
                calculo = ((res1 - res2) - (rs-rs1))* con;
                resultado_float = calculo / (float) base1;
                break;
            case '+':
                calculo = ((res1 + res2) -(rs+rs1))* con;
                resultado_float = calculo / (float) base1;
                break;
            case '-':
                calculo = ((res1 - res2) - (rs-rs1))* con;
                resultado_float = calculo / (float) base1;
                break;
            default:
                printf("ERRO!!...\n");
                return; // Retorna após o erro
        }

        if (fmod(resultado_float, base1) == 0) {
            printf("Resultado: %f unidade de area\n", resultado_float/base1);
        } else {
            printf("Resultado: ((%.0f)/%d) unidade de area\n", calculo, base1);
            if(calculo>1 && base1>1){
            simplificando(calculo,base1,2);
			}
        }
    } else {
        int m, p, a, q, r, j, k;

        switch (sinal[0]) {
            
			case '+':
                p = (base1 * base2);
                m = (p) / base1;
                a = m * res1;
                j = m * rs;
                q = p / base2;
                k = q * rs1;
                r = q * res2;
                resultado_float = (((a + r) - (j + k)) * con);
                break;
                
            	case '-':
                p = (base1 * base2);
                m = (p) / base1;
                a = m * res1;
                j = m * rs;
                q = p / base2;
                k = q * rs1;
                r = q * res2;
                resultado_float = (((a - r) - (j- k)) * con);
				break;
				
            default:
                printf("ERRO!!...\n");
                return; // Retorna após o erro
        }

        if (fmod(resultado_float, p) == 0) {
            printf("Resultado: %.1f unidade de area\n", resultado_float/p);
        } else {
            printf("Resultado: ((%.0f)/%d) unidade de area\n", resultado_float, p);
            if(resultado_float>1 && p>1){
            simplificando(resultado_float,p,2);
			}
        }
    }
}

void Numero_termos(int escolha, int funcao1, int funcao2, int funcao3, float x, float y, int resp){
 	int potencia,temp,potencia1,potencia2,qnt_termos,n, resultado,resultado1, resultado2,temp2,k;
 	float z;
 	char sinal[2],sinal1[2];
	 if(escolha>0){
 	 
			switch(escolha){
		 	 	case 1:
		 	 		//capta o expoente
				termo_potencia(x,&potencia);
				temp=potencia;
					//realiza a integracao do polinomio
				potencia=integracaopolinomio(x,temp);
				potencia1=integracaopolinomio(y,temp);
					//realiza o calculo exponencial dos demais termos				
				funcao1=calculo(x,potencia);
				funcao2=calculo(y,potencia1);
				
				sinal[0]='0';
					//capta a constante
				k=constante(k);
					//calculo de integral
				calculandointegral(potencia, potencia1,funcao1,funcao2,sinal,0,0,k);
		 	 	break;
		 	 	
		 	 	case 2:
		 	 	//capta o expoente
				termo_potencia(x,&potencia); 
				temp=potencia;//copia para uma variavel temporaria
				
				do{
				printf("Qual o sinal da operacao (+),(-)\n ");
				scanf("%s",sinal);//capta o sinal da equação
				}while(sinal[0]!='+' && sinal[0]!='-');
				
				termo_potencia(x,&potencia1);
				temp2=potencia1;
				
				//realiza a integracao do polinomio
				potencia=integracaopolinomio(x,temp);
				potencia1=integracaopolinomio(y,temp2);
				
				//realiza o calculo exponencial dos demais termos
				funcao1=calculo(x,potencia);
				funcao2=calculo(x,potencia1);
				resultado=calculo(y,potencia);
				resultado1=calculo(y,potencia1);
				
				//capta a constante
				k=constante(k);
				
				//calcula a integral
				calculandointegral(potencia, potencia1,funcao1,funcao2,sinal,resultado, resultado1,k);
				
		 	 	break;
		 	 	case 3:
		 	 		//capta o expoente
		 	 	termo_potencia(x,&potencia);
		 	 	temp=potencia;//copia para uma variavel temporaria
		 	 	//integra o polinomio
		 	 	potencia=integracaopolinomio(x,temp);//integra o termo 1
		 	 	
				do{
				printf("Qual o sinal da operacao (+),(-)\n ");
				scanf("%s",sinal);
				}while(sinal[0]!='+' && sinal[0]!='-');
					//capta o expoente
				termo_potencia(y,&potencia1);
				temp2=potencia1;
					//integra o polinomio
				potencia1=integracaopolinomio(y,temp2);
				
				do{
				printf("Qual o sinal da operacao (+),(-)\n ");
				scanf("%s",sinal1);
				}while(sinal1[0]!='+' && sinal1[0]!='-');
				
					//capta o expoente
				termo_potencia(x,&potencia2);
				int temp3=potencia2;
					//integra o polinomio
				potencia2=integracaopolinomio(y,temp3);
				 	//calculo de expoente
				funcao1=calculo(x,potencia);
				resultado2=calculo(y,potencia);
				resultado=calculo(x,potencia1);
				funcao2=calculo(y,potencia1);
				resultado1=calculo(x,potencia2);
				funcao3=calculo(y,potencia2);
					//capta a constante
				k=constante(k);
					//calcula a integral
				calculandointegral1(potencia,potencia1,potencia2,funcao1,resultado1, resultado, sinal, funcao2,funcao3,resultado2,sinal1,k);
		 	 	break;
		 	 	
		 	 	default:
		 	 	printf("Opcao invalida");
		 	 	break;
	  		}
		}
 }

int main(){
	int qnt_termos,n,funcao1,funcao2,funcao3,resp=3;
	float x, y,a,b;
	
	n=Dados(qnt_termos);
	x=Intervaloa(a);
	y=Intervaloa(b);
	Numero_termos(n,funcao1,funcao2, funcao3,x,y,resp);
	return 0;
}
