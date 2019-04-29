/* Isso aqui vai ser uma área de testes e estudos que usaremos pra resolver QUALQUER tipo de problema
relacionado a ED */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10

//Começo de fila

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

//Final de fila

//Começo de hashing

//listas de colisões
typedef struct Colision {
	int obj;
	struct Colision *prox;
}link;

//Estrutura da tabela
typedef struct Tabela {
	struct Colision* v[MAX];
}Tabela;

Tabela *tab;

//inicialização da tabela hashing
void initTabela () {
	int h;
	for (h=0; h<MAX; ++h)
	{
		tab->v[h] = NULL;
	}
}

int hashGenerator (int valor) {
	int h=0, soma=0, i;
	for (i=0; valor!=0; i++) {
		soma += (valor%10)*(i+1);
		valor/=10;
	}
	h = soma%MAX;
	return h;
}

void hashInsertion (int valor) {
	int index;
	index = hashGenerator(valor);
	link* novo = (link*)malloc(sizeof(link));
	novo->obj = valor;
	novo->prox = NULL;
	
	if(tab->v[index] != NULL){
		
		if(valor >= tab->v[index]->obj){
			
			link* x = tab->v[index];
			link* aux;
			while((valor >= x->obj) && (x != NULL)){
				
				aux = x;
				x = x->prox;
				
			}
			aux->prox = novo;
			novo->prox = x;
			return;
			
		}
		novo->prox = tab->v[index];
		tab->v[index] = novo;
		return;
		
	}
	tab->v[index] = novo;
}


void hashing (void) {
	initTabela();
	hashGenerator(30);


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
			filas();
			break;

			case 2:
			hashing();
			break;

			default:
			printf("Opção inválida!!!\n");
			break;
		}
		system("pause");		
	}while(option != 0);
}
