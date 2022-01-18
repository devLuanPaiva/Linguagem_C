#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int mat;
	char nome[10];
} estudante;

struct no{
	estudante dado;
	struct no * prox;
};
typedef struct no No;
typedef struct{
	No* inicio;
	No* fim;
}Fila;

void ler(estudante *pe){
	printf("Insira o nome e a matricula\n");
	scanf("%s %d", pe->nome, &pe->mat);
}
void inserir(Fila *pfila, estudante dado){
	No* novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->prox = NULL;
	if(pfila->inicio == NULL){
		pfila->inicio = novo;
		pfila->fim = novo; 
	}
	else {
		pfila->fim->prox = novo;
		pfila->fim = novo;
	}
}
void mostrar(Fila fila){
	No *pi;
	for(pi = fila.inicio; pi != NULL; pi = pi->prox){
		printf("|Nome: %s| Matricula: %d|\n", pi->dado.nome, pi->dado.mat);
	}
} 
void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Mostrar fila                       |\n");
	printf("|3 - Sair                               |\n");
	printf("|=======================================|\n");
}
int main(){
	Fila fila;
	fila.inicio = NULL;
	fila.fim = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 3){
		if(op == 1){
			estudante e;
			ler(&e);
			inserir(&fila, e);
		}
		if(op == 2){
			mostrar(fila);
			printf("\n");
		}
		menu();
		scanf("%d", &op);
	}
	return 0;	
}