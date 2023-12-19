#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 100
#define codigo 3
#define divisor 3
#define resto 3

typedef struct no {
    char nome[tam];
    int chave[3][3];
    int identificador;
    struct no *proximo;
} no;

void dados() {
    printf("\nInforme uma informacao a ser criptografada\n");
}

void dados1() {
    printf("\n--------------------------------------------------------------------------\n");
    printf("\n\tDigite 1 para Criptografar \n\tDigite 2 Para descriptografar \n\t0 Sair \n");
    printf("\n--------------------------------------------------------------------------\n");
}

int produtodechaves(int novom, int novon) {
    return novom * novon;
}

int encontraprimo(int a) {
    while (a > 1) {
        int d, x = 0;

        for (d = 2; d <= a / 2; d++) {
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
int encontranumero(int a){
	return a+1;
}
double medirDesempenho(int (*funcao)(int), int argumento) {
    clock_t inicio, fim;
    double tempo_execucao;
    int resultado = funcao(argumento);
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

int calculodiferenca(int valora, int valorb) {
    int res;
    res = (valora - valorb);
    return res;
}

/*char *bruteForceDecrypt(char cripto[tam], int chavecodigo[codigo], int chavedivisor[divisor], int chaveresto[resto]) {
    int tentativa = 0; // Iniciando tentativa com o primeiro número primo
    
    

    while(1) {
        int chave_correta = 1;

        
        for (int i = 0; i < divisor; i++) {
        printf("tentativa (%d)\n",tentativa);
            if (encontranumero(tentativa) && tentativa % chavedivisor[i] == chaveresto[i]) {
                chave_correta = 0;
                break; // Se um não corresponder, não é a chave correta, então interrompe o loop
            }
        }
        if (chave_correta) {
            printf("\n+++++++++++++++++++++++++\n\nMensagem Descriptografada\n\n\t%s\n\n+++++++++++++++++++++++++\n", cripto);
            return cripto; // Retorna a mensagem descriptografada
        }

        tentativa++;
    }

    return NULL; // Retorna NULL se a descriptografia falhar
}*/
void bruteForceDecrypt(char cripto[tam], int chave, int diviso, int rest) {
    int tentativa = 2; // Iniciando tentativa com o primeiro número primo

    while (1) {
        int chave_correta = 1;

        for (int i = 0; i < diviso; i++) {
            if (encontranumero(tentativa) && tentativa % diviso != rest) {
                chave_correta = 0;
                break; // Se um não corresponder, não é a chave correta, então interrompe o loop
            }
        }
        if (chave_correta) {
            printf("\n+++++++++++++++++++++++++\n\nMensagem Descriptografada\n\n\t%s\n\n+++++++++++++++++++++++++\n", cripto);
            return; // Retorna, pois a mensagem foi descriptografada
        }

        tentativa++;
    }
}


void descriptografar(char msg[tam], int x, int chaveb, int res) {
    if (x % chaveb == res) {
        printf("\n+++++++++++++++++++++++++\n\nMensagem Descriptografada\n\n\t%s\n\n+++++++++++++++++++++++++\n", msg);
    } else {
        printf("Chave incorreta\n");
    }
}

/*void imprimevetor(char nm[][tam], int a[resto], int b[resto], int c[resto], int id) {
	//imprimevetor(nome, chavecodigo, chavedivisor, chaveresto, id)
    for (int i = 0; i < id; i++) {
        if (nm[i][0] != '\0') {
            printf("(nome...)%s-(posicao)%d-(numero a ser encontrado)%d-(divisor)%d(resto)%d\n",nm[i], i,a[i],b[i],c[i]);
        }
    }
}*/
void imprimevetor(char nm[][tam], int a[resto], int b[resto], int c[resto], int id) {
    // imprimevetor(nome, chavecodigo, chavedivisor, chaveresto, id)
    for (int i = 0; i < id; i++) {
        if (nm[i][0] != '\0') {
            printf("(nome...)%s-(posicao)%d-(numero a ser encontrado)%d-(divisor)%d(resto)%d\n", nm[i], i, a[i], b[i], c[i]);
        }
    }
}


void exibe(char nm[][tam], int a[resto], int b[resto], int c[resto], int id) {
    printf(" %s --- %d---%d---%d\n", nm[id], a[id], b[id], c[id]);
}

void ordena(int x[resto]) {
    // bubleshort
    int i = 0, j, aux;
    for (i; i < resto; i++) {
        for (j = i + 1; j <= resto; j++) {
            if (x[j] < x[i]) {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
                printf("\nordenou\n");
            }
            printf("\nnao precisou ordenar\n");
        }
    }
}

int main() {
    int res, sorteio, primoa, primob, multij, multia, multiz, difere, resDecrypt, teste, id = 0;
    char cripto[tam], nome[resto][tam];

    int chavecodigo[codigo];
    int chavedivisor[divisor];
    int chaveresto[resto];

    double a, b, b1, b2, b3, c;

    dados1();
    scanf("%d", &res);
    getchar();

    do {
        switch (res) {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            dados();
            scanf("%[^\n]s", cripto);
            srand(time(NULL));
            sorteio = rand() % tam + 1;
            a = medirDesempenho(encontraprimo, sorteio);

            primoa = encontraprimo(sorteio);
            primob = encontraprimo(primoa + 1);
            multia = produtodechaves(primoa, primob);
            multiz = produtodechaves(primoa - 1, primob - 1);
            difere = calculodiferenca(multia, multiz);
            multij = produtodechaves(primoa, difere);

            b = medirDesempenhoa(produtodechaves, primoa, primob);
            b1 = medirDesempenhoa(produtodechaves, primoa - 1, primob - 1);
            b2 = medirDesempenhoa(produtodechaves, primoa, difere);
            b3 = medirDesempenhoa(calculodiferenca, multia, multiz);

            teste = multij % primob;
            strcpy(nome[id], cripto);
            chavecodigo[id] = multij;
            chavedivisor[id] = primob;
            chaveresto[id] = teste;
            
			printf("\nValor das chaves publicas chave(1)=%d chave(2)= %d\n", primob, teste);
            printf("(multij)%d\n", multij);

            id++;
            //imprimevetor(nome, chavecodigo, chavedivisor, chaveresto, id);

            break;
            case 2:
    printf("Informe as chaves publicas geradas\n");
    ordena(chavedivisor);
    imprimevetor(nome, chavecodigo, chavedivisor, chaveresto, id);
    printf("primo b-%d\n", primob);

    int posicao;
    printf("Informe a posição\n");
    scanf("%d", &posicao);

    if (posicao >= 0 && posicao < id) {
        bruteForceDecrypt(nome[posicao], chavecodigo[posicao], chavedivisor[posicao], chaveresto[posicao]);
    } else {
        printf("Posição inválida.\n");
    }

    break;
/*        case 2:
            printf("Informe as chaves publicas geradas\n");
            ordena(chavedivisor);
            imprimevetor(nome, chavecodigo, chavedivisor, chaveresto, id);
            printf("primo b-%d\n",primob);

            int ex;
            //scanf("%d", &ex);
            ex=0;
            printf("(multij)%d\n", multij);
            printf("Usando Força Bruta%d \n",chavecodigo[ex]);

            bruteForceDecrypt(nome[ex], chavecodigo, chavedivisor, chaveresto);

            break;*/
        default:
            printf("Opcao Invalida!\n");
            break;
        }

        dados1();
        scanf("%d", &res);
        printf("\n");
        getchar();

    } while (res != 0);

    return 0;
}
