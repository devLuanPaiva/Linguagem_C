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
	printf("|=========== MENU DO ESCOLAR ============|\n");
	printf("|1  - Inserir novo                     	 |\n");
	printf("|2  - Imprimir lista                     |\n");
	printf("|3  - Inserir fim                        |\n");
	printf("|4  - Pesquisar                          |\n");
	printf("|5  - Inserir apos                       |\n");
	printf("|6  - Inserir antes do no                |\n");
	printf("|7  - Deletar o primeiro no              |\n");
	printf("|8  - Deletar o ultimo item              |\n");
	printf("|9  - Deletar por matricula              |\n");
	printf("|10 - Deletar apos um no                 |\n");
	printf("|11 - Deletar antes do no                |\n");
	printf("|12 - Sair                               |\n");
	printf("|========================================|\n");
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
struct No* inserir_antes(Lista *plista, estudante dado, int mat){
	if(plista->inicio == NULL){
		return NULL;
	}
	else if(plista->inicio->dado.mat == mat){
		struct No* novo = (struct No*) malloc(sizeof (struct No));
		novo->dado = dado;
		novo->prox = plista->inicio;
		plista->inicio = novo;
	}
	else{
		struct No* pi;
        for(pi = plista->inicio; pi->prox != NULL && pi->prox->dado.mat == mat; pi = pi->prox);
        if(pi->prox == NULL){
			return NULL;	
		}
		else {
			struct No *novo = (struct No*) malloc(sizeof (struct No));
			novo->dado = dado;
			novo->prox = pi->prox;
			pi->prox = novo;
			return pi;
		}
	}
}
void deletar_inicio(Lista *plista){
	if(plista->inicio == NULL){
		printf("A lista esta vazia\n");
	}
	else{
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		printf("Excluido\n");
	}
}
void deletar_fim(Lista *plista){
	if(plista->inicio == NULL){
		printf("O estudante nao pode ser deletado\n");
	}
	else if(plista->inicio->prox == NULL){
		struct No* pi = plista->inicio;
		plista->inicio = NULL;
		free(pi);
		printf("Agora a lista esta vazia\n");
	}
	else{
		struct No* pi;
		struct No* pa;
		for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
			pa = pi;
		}
		pa->prox = NULL;
		free(pi);
		printf("Excluido\n");
		
	}
}
void deletar_valor(Lista *plista, int mat){
   //Inicio == null;
	if(plista->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No se localiza no inicio;
	else if(plista->inicio->dado.mat == mat){
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		printf("Excluido\n");
	}
	//Lista tem um unico No. Matricula nao existe
	else if(plista->inicio->prox == NULL){
		if(plista->inicio->dado.mat != mat){
			printf("O estudante nao pode ser removido\n");
		}
	}
	//Lista com multiplos Nos. Valor nao existe
	//Lista com multiplos Nos. Valor existe
	else{
		struct No* pa;
		struct No* pi;
		for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
			pa = pi;
		}
		if(pi == NULL){
			printf("O estudante nao pode ser removido\n");
		}
		else{
			pa->prox = pi->prox;
			free(pi);
			printf("Escluido\n");
		}
	}
}
void deletat_apos(Lista *plista, int mat){
	struct No* pa;
	struct No* pi;
	for(pa = plista->inicio; pa != NULL && pa->dado.mat != mat; pa = pa->prox);
	if(pa == NULL){
		printf("O estudante nao pode ser removido\n");
	}
	else if(pa->prox == NULL){
		printf("Estudante nao pode ser removido\n");
	}
	else{
		pi = pa->prox;
		pa->prox = pi->prox;
		free(pi);
		printf("Excluido\n");
	}
}
void deletar_antes(Lista *plista, int mat){
	//Lista vazia
	if(plista->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No inicial igual ao no pesquisado
	else{
		
	    struct No* paa = NULL;
	    struct No* pa = NULL;
        struct No* pi = NULL;
        for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
			paa = pa;
			pa = pi;
		}
		//O segundo no e igual ao valor pesquisado
		if (pa == NULL){
			printf("Estudante nao pode ser removido\n");
		}
	    //Multiplos itens: No existe
	    if(paa == NULL){
			plista->inicio = pi;
			free(pa);
			printf("Excluido\n");
		}
	    //Multiplos itens: No nao existe
	    else if(pi == NULL){
			printf("Estudante nao pode ser removido\n");
		}
		else{
			paa->prox = pi;
			free(pa);
			printf("Excluido\n");
		}
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
	while(op != 12){
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
			printf("\n");
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
			printf("\n");
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
			printf("\n");
		}
		else if(op == 6){
			estudante e;
			ler(&e);
			int mat;
			printf("Informe a matricula para inserir antes\n");
			scanf("%d", &mat);
			struct No * pi = inserir_antes(&lista, e, mat);
			if(pi == NULL){
				printf("Nao foi possivel inserir o estudante\n");
			}
			printf("\n");	
		}
		else if(op == 7){
			deletar_inicio(&lista);
			printf("\n");
		}
		else if(op == 8){
			deletar_fim(&lista);
			printf("\n");
		}
		else if(op == 9){
			int mat;
			printf("Informe a matricula para ser deletada\n");
			scanf("%d", &mat);
			deletar_valor(&lista, mat);
			printf("\n");
		}
		else if(op == 10){
			int mat;
			printf("Informe a matricula para a proxima ser deletada\n");
			scanf("%d", &mat);
			deletat_apos(&lista, mat);
			printf("\n");
		}
		else if(op == 11){
			int mat;
			printf("Informe a matricula para a anterior ser deletada\n");
			scanf("%d", &mat);
			deletar_antes(&lista, mat);
			printf("\n");
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}