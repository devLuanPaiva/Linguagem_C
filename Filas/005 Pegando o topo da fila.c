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
void remover(Fila *pfila){
	if(pfila->inicio == NULL){
		printf("Lista vazia\n");
	}
	else if(pfila->inicio->prox == NULL){
		pfila->inicio = NULL;
		pfila->fim = NULL;
	}
	else{
	    No *pi = pfila->inicio;
	    pfila->inicio = pi->prox;
	    free(pi);
	    printf("Excluido\n");
	}
} 
int vazia(Fila fila){
	if(fila->inicio == NULL){
		retur 1;
	}
	else{
		return 0;
	}
}
No* inicio (Fila fila){
	return fila.inicio;
}
void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Mostrar fila                       |\n");
	printf("|3 - Remover o primeiro item            |\n");
	printf("|4 - Verificar se esta vazia            |\n");
	printf("|5 - Pegar inicio                       |\n");
	printf("| - Sair                               |\n");
	printf("|=======================================|\n");
}
int main(){
	Fila fila;
	fila.inicio = NULL;
	fila.fim = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 6){
		if(op == 1){
			estudante e;
			ler(&e);
			inserir(&fila, e);
		}
		else if(op == 2){
			mostrar(fila);
			printf("\n");
		}
		else if(op == 3){
			remover(&fila);
			printf("\n");
		}
		else if(op == 4){
			int r = vazia(fila);
			if(r !=0 ){
				printf("Lista vazia\n");
			}
			else{
				printf("Lista esta preenchida\n");
			}
			printf("\n");
		}
		else if(op == 5){
			No* pi = inicio(fila);
			if(pi != NULL){
				printf("|Nome: %s| Matricula: %d|\n", pi->dado.nome, pi->dado.mat);
			}
			else{
				printf("Fila vazia\n");
			}
			printf("\n");
		}
		menu();
		scanf("%d", &op);
	}
	return 0;	
}