#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int mat;
	char nome[10];
}estudante;

struct no{
	estudante dado;
	struct no* prox;
};
typedef struct no No;
typedef struct{
	No * topo;
}Pilha;


void ler(estudante *pe){

	scanf("%s %d", pe->nome, &pe->mat);
}
//push
void inserir(Pilha *ppilha, estudante dado){
	No * novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo-> prox = ppilha->topo;
	ppilha->topo = novo;
}
void mostrar(Pilha pilha){
	No *pi;
	for(pi = pilha.topo; pi != NULL; pi = pi->prox){
		printf("|Nome: %s| Matricula: %d|\n", pi->dado.nome, pi->dado.mat);
	}
}
void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Mostrar pilha                      |\n");
	printf("|3 - Sair                               |\n");
	printf("|=======================================|\n");
}
int main(){
	Pilha pilha;
	pilha.topo = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 3){
		if(op == 1){
			estudante e;
			printf("Informe o nome e a matricula\n");
			ler(&e);
			inserir(&pilha, e);
			printf("\n");
		}
		else if(op == 2){
			mostrar(pilha);
			printf("\n");
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}