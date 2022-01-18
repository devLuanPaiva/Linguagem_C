#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	float altura;
	float peso;
	float medida;
	char nome[100];
}imc;

struct No {
	imc dado;
	struct No *prox;
	
};
typedef struct {
	struct No *  inicio;
} Lista;
void ler(imc *pimc){
	printf("Diite o nome, altura e peso\n");
	scanf("%s %f %f", pimc->nome, &pimc->altura, &pimc->peso);
	pimc->medida = pimc->peso +( pimc->altura * pimc->altura);
	
}

void incerir_inicio(Lista *lista, imc  dado){
	struct No * novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = dado;
	novo->prox = lista->inicio;
	lista->inicio = novo;
}
struct No* pesquisar(Lista lista, char s1[]){
	struct No* pi;
	for(pi = lista.inicio; pi != NULL && strcmp(s1, pi->dado.nome) != 0; pi = pi->prox);
	return pi;
}
void ordena_imcs(Lista *pimc){
	struct No* pi;
	struct No* pj;
	struct No* pfim = NULL;
	if(pimc->inicio == NULL){
		return;
	}
	for(pi = pimc->inicio; pi->prox != NULL ; pi = pi->prox){
		for(pj = pimc->inicio; pj->prox != pfim; pj = pj->prox ){
			if(pj->dado.medida < pj->prox->dado.medida){
				imc temp = pj->dado;
				pj->dado = pj->prox->dado;
				pj->prox->dado = temp;
			}
		}
		pfim = pj;
	}
	for(pi = pimc->inicio; pi != NULL ; pi = pi->prox){
	    printf("|IMC: %f |Nome: %s|\n", pi->dado.medida, pi->dado.nome);
	}
	
}
struct No* inserir_apos(Lista *plista, imc dado, char nome2[]){
  struct No* pi;
  for(pi = plista->inicio; pi != NULL && strcmp(nome2, pi->dado.nome) != 0; pi = pi->prox);
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
struct No* inserir_antes(Lista *plista, imc dado, char nome2[]){
	if(plista->inicio == NULL){
		return NULL;
	}
	else if(strcmp(plista->inicio->dado.nome, nome2) == 0){
		struct No* novo = (struct No*) malloc(sizeof (struct No));
		novo->dado = dado;
		novo->prox = plista->inicio;
		plista->inicio = novo;
	}
	else{
		struct No* pi;
        for(pi = plista->inicio; pi->prox != NULL && strcmp(nome2, pi->dado.nome) != 0; pi = pi->prox);
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
void inserir_fim(Lista *plista, imc dado){
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
void mostrar(Lista plista){
	struct No * pi;
	for(pi = plista.inicio; pi != NULL ; pi = pi->prox){
		printf("|Nome: %s | IMC: %2.f|\n", pi->dado.nome, pi->dado.medida);
	}
	
} 
void deletar_inicio(Lista *pplista){
	if(pplista->inicio == NULL){
		printf("A lista esta vazia\n");
	}
	else{
		struct No* pi = pplista->inicio;
		pplista->inicio = pi->prox;
		free(pi);
		printf("Excluido\n");
	}
}
void deletar_fim(Lista *pplista){
	if(pplista->inicio == NULL){
		printf("A pessoa nao pode ser deletada\n");
	}
	else if(pplista->inicio->prox == NULL){
		struct No* pi = pplista->inicio;
		pplista->inicio = NULL;
		free(pi);
		printf("Agora a lista esta vazia\n");
	}
	else{
		struct No* pi;
		struct No* pa;
		for(pi = pplista->inicio; pi->prox != NULL; pi = pi->prox){
			pa = pi;
		}
		pa->prox = NULL;
		free(pi);
		printf("Excluido\n");
		
	}
}
void deletar_valor(Lista *pplista, char s1[]){
   //Inicio == null;
	if(pplista->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No se localiza no inicio;
	else if(strcmp(pplista->inicio->dado.nome, s1) ==0 ){
		struct No* pi = pplista->inicio;
		pplista->inicio = pi->prox;
		free(pi);
		printf("Time excluido\n");
	}
	//Lista tem um unico No. Nome nao existe
	else if(pplista->inicio->prox == NULL){
		if((strcmp(pplista->inicio->dado.nome, s1) != 0)){
			printf("O time nao pode ser removido\n");
		}
	}
	//Lista com multiplos Nos. Valor nao existe
	//Lista com multiplos Nos. Valor existe
	else{
		struct No* pa;
		struct No* pi;
		for(pi = pplista->inicio; pi != NULL && (strcmp(pi->dado.nome ,s1) != 0); pi = pi->prox){
			pa = pi;
		}
		if(pi == NULL){
			printf("O time nao pode ser removido\n");
		}
		else{
			pa->prox = pi->prox;
			free(pi);
			printf("Time escluido\n");
		}
	}
}
void deletat_apos(Lista *pplista, char s1[]){
	struct No* pa;
	struct No* pi;
	for(pa = pplista->inicio; pa != NULL && (strcmp(pa->dado.nome ,s1) != 0); pa = pa->prox);
	if(pa == NULL){
		printf("A pessoa nao pode ser removida\n");
	}
	else if(pa->prox == NULL){
		printf("A pessoa nao pode ser removida\n");
	}
	else{
		pi = pa->prox;
		pa->prox = pi->prox;
		free(pi);
		printf("Excluido\n");
	}
}
void deletar_antes(Lista *pplista, char s1[]){
	
	//Lista vazia
	if(pplista->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No inicial igual ao no pesquisado
	else{
		
	    struct No* paa = NULL;
	    struct No* pa = NULL;
        struct No* pi = NULL;
        for(pi = pplista->inicio; pi != NULL && (strcmp(pi->dado.nome ,s1) != 0); pi = pi->prox){
			paa = pa;
			pa = pi;
		}
		//O segundo no e igual ao valor pesquisado
		if (pa == NULL){
			printf("A pessoa nao pode ser removida\n");
		}
	    //Multiplos itens: No existe
	    if(paa == NULL){
			pplista->inicio = pi;
			free(pa);
			printf("Excluido\n");
		}
	    //Multiplos itens: No nao existe
	    else if(pi == NULL){
			printf("A pessoa nao pode ser removida\n");
		}
		else{
			paa->prox = pi;
			free(pa);
			printf("Excluido\n");
		}
	}
	
}
void deletar_lista(Lista *pplista){
	struct No* pi;
	while(pplista->inicio != NULL){
		pi = pplista->inicio;
		pplista->inicio = pi->prox;
		free(pi);
	}
}
void menu(){
	printf("|=================MENU==================|\n");
	printf("|1 - Inserir novo                   	|\n");
	printf("|2 - Imprimir IMCs ordenados            |\n");
	printf("|3 - Buscar pessoa                      |\n");
	printf("|4 - Inserir apos uma pessoa            |\n");
	printf("|5 - inserir antes de uma pessoa        |\n");
	printf("|6 - Inserir no fim                     |\n");
	printf("|7 - imprimir pessoas                   |\n");
	printf("|8  - Deletar a primeira pessoa         |\n");
	printf("|9  - Deletar a ultima pessoa           |\n");
	printf("|10 - Deletar uma pessoa especifica     |\n");
	printf("|11 - Deletetar uma pessoa apos outra   |\n");
	printf("|12 - Deletar uma pessoa antes de outra |\n");
	printf("|13 - Deletar lita completa             |\n");
	printf("|14 - Sair                              |\n");
	printf("|=======================================|\n");
}
int main(){
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 14){
		if(op == 1){
			imc pimc;
			ler(&pimc);
			incerir_inicio(&lista, pimc);
		}
		else if(op == 2){
			ordena_imcs(&lista);
			printf("\n");
		}
		else if(op == 3){
			char s1[100];
		    printf("Digite o nome da pessoa \n");
	  		scanf("%s", s1);
		    struct No * pi = pesquisar(lista, s1);			    
			if(pi !=  NULL){
		        printf("Nome: %s\n", pi->dado.nome);
                printf("Altura: %2.f\n",pi->dado.altura);
			    printf("Peso: %2.f\n", pi->dado.peso);
                printf("IMC: %2.f\n", pi->dado.medida);
            }
            else{
                printf("Pessoa nao encontrada\n");
            }
            printf("\n");
		}
		else if(op == 4){
            imc pimc;
			ler(&pimc);
			char nome2[100];
			printf("Informe o nome de quem vc deseja inserir apos\n");
			scanf("%s", nome2);
			struct No * pi = inserir_apos(&lista, pimc, nome2);
			if(pi == NULL){
				printf("Nao foi possivel inserir \n");
			}
			printf("\n");
		}
		else if(op == 5){
			imc pimc;
			ler(&pimc);
			char nome2[100];
			printf("Informe o nome de quem vc deseja inserir antes\n");
			scanf("%s", nome2);
			struct No * pi = inserir_antes(&lista, pimc, nome2);
			if(pi == NULL){
				printf("Nao foi possivel inserir \n");
			}
			printf("\n");	
		}
		else if(op == 6){
		    imc pimc;
			ler(&pimc);
			inserir_fim(&lista, pimc);
			printf("\n");	
		}
		else if(op == 7){
			mostrar(lista);
			printf("\n");
		}
		else if(op == 8){
			deletar_inicio(&lista);
			printf("\n");
		}
		else if(op == 9){
			deletar_fim(&lista);
			printf("\n");
		}
		else if(op == 10){
		    char nome2[100];
			printf("Informe a pessoa para ser deletada\n");
			scanf("%s", nome2);
			deletar_valor(&lista, nome2);
			printf("\n");
		}
        else if(op == 11){
			char nome2[100];
			printf("Informe a pessoa para ser deletada apos \n");
			scanf("%s", nome2);
			deletat_apos(&lista, nome2);
			printf("\n");
		}
		else if(op == 12){
			char nome2[100];
			printf("Informe a pessoa para ser deletada antes\n");
			scanf("%s", nome2);
			deletar_antes(&lista, nome2);
			printf("\n");
		}
		else if(op == 13){
			deletar_lista(&lista);
			printf("Lista deletada\n");
			printf("\n");
		}				
		menu();
		scanf("%d", &op);
	}
	return 0;
}
