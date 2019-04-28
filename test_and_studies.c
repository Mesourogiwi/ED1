/* Isso aqui vai ser uma área de testes e estudos que usaremos pra resolver QUALQUER tipo de problema
relacionado a ED */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//estrutura de dados de um elemento simples
typedef struct Elemento {
	int dado;
	struct Elemento *prox;
}Elem;

//estrutura de ponteiros que vão apontar para o inicio e o fim da fila
typedef struct Fila {
	struct Elemento *ini;
	struct Elemento *fim;
}Fila;

//vamos definir as funções e operações a serem aplicadas às nossas filas
Fila* InicializaFila () {
	Fila *fi = (Fila*) malloc(sizeof(Fila));
	fi->fim = NULL;
	fi->ini = NULL;
	return fi;
}

void inserirElemento (Fila *fi, int dado) {
	Elem *elemento = (Elem*)malloc(sizeof(Elem));
	elemento->dado = dado;
	if (fi->ini == NULL) {
		fi->ini = elemento;
	}
	else {
		fi->fim->prox = elemento;
	}
	fi->fim = elemento;
	elemento->prox = NULL;
	return;
}

void imprimirFila (Fila *fi) {
	Elem *aux = fi->ini;
	while (aux != NULL) {
		printf("%d   \n", aux->dado);
		aux = aux->prox;
	}
	return;
}

void remover (Fila *fi) {
	if (fi->ini != NULL) {
		Elem *aux;
		aux = fi->ini;
		fi->ini = fi->ini->prox;
		free(aux);
	}
}

void filas (void) {
	int dado=0, option=0;
	Fila* fi = InicializaFila();
	do {
		system("cls");
		printf("*****************************************************************************\n");
		printf("*                                                                           *\n");
		printf("*                                    Filas                                  *\n");
		printf("*                                                                           *\n");
		printf("*                                Menu Principal                             *\n");
		printf("*                                                                           *\n");
		printf("*****************************************************************************\n\n\n");

		printf("Digite uma das seguintes op?es: ");
		printf("\n0-Sair do programa");
		printf("\n1-Inserir um elemento");
		printf("\n2-Imprimir toda a fila");
		printf("\n3-Remo?o de um elemento na fila");
		printf("\n4-Remo?o de todos os elementos da lista\n");
		scanf("%d", &option);

		switch(option) {
			case 0:
			break;

			case 1:
			printf("Digite o dado a ser inserido na fila: ");
			scanf("%d", &dado);
			inserirElemento(fi, dado);
			break;

			case 2:
			imprimirFila(fi);
			break;
			
			case 3:
			remover(fi);
			break;

			default:
			printf("Op?o inv?ida!!!\n");
			break;
		}
		system("pause");
	}while(option);
	return;
}

int main (void) {
	setlocale(LC_ALL, "Portuguese");
	int option=0;
	do {
		printf("Seja bem vindo a área de estudo\n");
		printf("Escolha uma das opções a seguir para ser redirecionado a algum dos problemas resolvidos\n");
		printf("1- Filas e suas implementações\n");
		scanf("%d", &option);

		switch (option) {
			case 1:
			fila();
			break;

			default:
			printf("Opção inválida!!!\n");
			break;
		}
		system("pause");		
	}while(option != 0);
}
