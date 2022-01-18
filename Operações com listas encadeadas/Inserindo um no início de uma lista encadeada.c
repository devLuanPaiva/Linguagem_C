#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int mat;
	char nome[10];
}estudante;

struct No {
	estudante dado;
	struct No *prox;
	
};
typedef struct {
	struct No *  inicio;
} Lista;
void ler(estudante *pe){
	scanf("%s %d", pe->nome, &pe->mat);
}
void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Sair                               |\n");
	printf("|=======================================|\n");
}
void incerir_inicio(Lista *lista, estudante  dado){
	struct No * novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = lista->inicio;
	lista->inicio = novo;
}

int main(){
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 2){
		if(op == 1){
			estudante e;
			ler(&e);
			incerir_inicio(&lista, e);
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}
