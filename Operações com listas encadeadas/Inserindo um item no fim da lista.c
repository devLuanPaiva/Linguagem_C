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
	struct No *inicio;
} Lista;
void ler(estudante *pe){
	printf("Digite o nome e a matricula\n");
	scanf("%s %d", pe->nome, &pe->mat);
}
void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Imprimir lista                     |\n");
	printf("|3 - Inserir fim                        |\n");
	printf("|4 - Sair                               |\n");
	printf("|=======================================|\n");
}
void incerir_inicio(Lista *plista, estudante  dado){
	struct No * novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
}
void inserir_fim(Lista *plista, estudante dado){
	struct No *novo= (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = NULL; 
	if(plista->inicio == NULL){
		plista->inicio = novo;
	}
	else{
	    struct No *pi;
	    for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
	    pi->prox = novo;
	}
}
void mostrar(Lista lista){
	struct No * pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
	    printf("|Nome: %s| Matricula %d|\n", pi->dado.nome, pi->dado.mat);
	}
	/*Ou
	while(pi != NULL){
		printf("|Nome: %s| Matricula %d|\n", pi->dado.nome, pi->dado.mat);
		pi = pi->prox;
	}
	
	*/
}


int main(){
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 4){
		if(op == 1){
			estudante e;
			ler(&e);
			incerir_inicio(&lista, e);
			printf("\n");
		}
		else if(op == 2){
			mostrar(lista);
			printf("\n");
		}
		else if(op == 3){
			estudante e;
			ler(&e);
			inserir_fim(&lista, e);
			
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}
