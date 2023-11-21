#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Autor: Alexsandro Paixâo
Projeto e Análise de Algoritmo
Considere uma situação em que você está desenvolvendo um sistema de gerenciamento de
estoque para um armazém. A lista de produtos no estoque é extensa e está ordenada pelo
nome do produto. Cada produto tem um identificador único...
*/
typedef struct no {
    char nome[25];
    int identificador;
    struct no *proximo;
} no;

typedef struct {
    no *first, *last;
    int id;
} ld;

void menu(){
	printf("\nMenu:\n");
        printf("1. Adicionar produto\n");
        printf("2. Buscar produto por nome\n");
        printf("3. Buscar produto por binario\n");
        printf("4. Listar produtos\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
}

void inicialista(ld *lista) {
    lista->first = NULL;
    lista->last = NULL;
    lista->id = 1;
}

void insereproduto(ld *lista, char produto[]) {
    no *novo = (no *)malloc(sizeof(no));
    no *anterior = NULL, *atual = lista->first;

    if (novo == NULL) {
        printf("ERRO ao alocar memoria ");
        return;
    }

    strcpy(novo->nome, produto);
    novo->identificador = lista->id++;
    novo->proximo = NULL;

    while (atual != NULL && strcmp(novo->nome, atual->nome) > 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novo->proximo = lista->first;
        lista->first = novo;
    } else {
        anterior->proximo = novo;
        novo->proximo = atual;
    }

    if (atual == NULL) {
        lista->last = novo;
    }
}

no* buscabin(ld *lista, char nome_produto[]) {
    no *inicio = lista->first;
    no *fim = lista->last;

    while (inicio <= fim) {
        no *meio_node = inicio;

        // Encontrar o nó no meio da seção atual
        for (int i = 0; i < (fim->identificador - inicio->identificador) / 2; i++) {
            meio_node = meio_node->proximo;
        } 

        int comparacao = strcmp(nome_produto, meio_node->nome);

        if (comparacao == 0) {
            // Produto encontrado, retorna o ponteiro para o nó
            return meio_node;
        } else if (comparacao < 0) {
            // Buscar na metade inferior
            fim = meio_node->proximo;
        } else {
            // Buscar na metade superior
            inicio = meio_node->proximo;
        }
    }

    // Produto não encontrado, retorna NULL
    return NULL;
}

no* buscanome(ld *lista, char produto[]){
	no *atual=lista->first;
	while(atual != NULL){
		if(strcmp(produto,atual->nome)==0){
			return atual;
		}
		atual=atual->proximo;
	}
	return NULL;
}


void imprimir(ld *lista) {
    no *novo = lista->first;
    while (novo != NULL) {
        printf("ID: %d, Nome: %s\n", novo->identificador, novo->nome);
        novo = novo->proximo;
    }
}

int main() {
    ld lista;
    no *encontrado;
    inicialista(&lista);
    char res;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1: {
        do{
				
                char produto[25];
                printf("\nDigite o nome do produto: ");
                fgets(produto, sizeof(produto), stdin);
                produto[strcspn(produto, "\n")] = '\0';
                insereproduto(&lista, produto);
                printf("\n");
                imprimir(&lista);
                printf("\n\n");
        printf("\n\nDeseja buscar mais produtos? (s/n): ");
        scanf(" %c", &res);
        getchar(); // Limpar o buffer de entrada

   		 } while (res == 's' || res == 'S');

                break;
            }
            case 2: {
       do{
				
                char produto[25];
                printf("\nDigite o nome do produto para buscar: ");
                fgets(produto, sizeof(produto), stdin);
                produto[strcspn(produto, "\n")] = '\0';
                encontrado = buscanome(&lista, produto);
                if (encontrado != NULL) {
                    printf("Produto encontrado - ID: %d, Nome: %s\n", encontrado->identificador, encontrado->nome);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                
        printf("\n\nDeseja buscar mais produtos? (s/n): ");
        scanf(" %c", &res);
        getchar(); // Limpar o buffer de entrada

    	} while (res == 's' || res == 'S');
                break;
            }
            case 3: {
            do{
			
                char produto[25];
                printf("Digite o nome do produto para buscar de forma binaria: ");
                fgets(produto, sizeof(produto), stdin);
                produto[strcspn(produto, "\n")] = '\0';
             encontrado = buscabin(&lista, produto);
                printf("%d",encontrado);
                if (encontrado != NULL) {
                    printf("Produto encontrado - ID: %d\n", encontrado->identificador);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                
            printf("\n\nDeseja buscar mais produtos? (s/n): ");
        	scanf(" %c", &res);
        	getchar(); // Limpar o buffer de entrada

    		} while (res == 's' || res == 'S');
                break;
            }
            case 4:
                imprimir(&lista);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}