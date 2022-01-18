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
	printf("|4 - Pesquisar                          |\n");
	printf("|5 - Inserir apos                       |\n");
	printf("|6 - Sair                               |\n");
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
struct No* inserir_apos(Lista *plista, estudante dado, int mat){
  struct No* pi;
  for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
  if(pi == NULL){
	  return pi;
  }
  else {
	  struct No *novo = (struct No*) malloc(sizeof (struct No));
	  novo->dado = dado;
	  novo->prox = pi->prox;
	  pi->prox = novo;
	  return pi;
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
struct No* pesquisar(Lista lista, int mat){
	struct No* pi;
	for(pi = lista.inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
		return pi;
}

int main(){
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 6){
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
		else if(op == 4){
			int mat;
			printf("Informe a matricula\n");
			scanf("%d", &mat);
			struct No * pi = pesquisar(lista, mat);
			if(pi != NULL){
				printf("|Nome: %s| Matricula %d|\n", pi->dado.nome, pi->dado.mat);
			}
			else{
				printf("Estudante nao encontrado\n");
			}
		}
		else if(op == 5){
			estudante e;
			ler(&e);
			int mat;
			printf("Informe a matricula para inserir apos\n");
			scanf("%d", &mat);
			struct No * pi = inserir_apos(&lista, e, mat);
			if(pi == NULL){
				printf("Nao foi possivel inserir o estudante\n");
			}
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}
 