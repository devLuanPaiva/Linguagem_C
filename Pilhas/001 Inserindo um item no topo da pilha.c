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

void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Sair                               |\n");
	printf("|=======================================|\n");
}
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

int main(){
	Pilha pilha;
	pilha.topo = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 2){
		if(op == 1){
			estudante e;
			printf("Informe o nome e a matricula\n");
			ler(&e);
			inserir(&pilha, e);
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}