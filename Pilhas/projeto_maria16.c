#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Campeonato Brasileiro
// Luan Alves de Paiva
typedef struct {
	float altura;
	float peso;
	float medida;
	char nome[100];
}imc;
struct no{
	imc dado;
	struct no *prox;
};
typedef struct no No;
typedef struct{
	No * topo;
}Pilha;

void menu(){
	printf("|================ MENU =================|\n");
	printf("|1 - Inserir nova pessoa               	|\n");
	printf("|2 - Mostrar pessoas                    |\n");
	printf("|3 - Remover a primeira pessoa          |\n");
	printf("|4 - Verificar se esta vazia            |\n");
	printf("|5 - Pegar a pessoa do topo             |\n");
	printf("|6 - Sair                               |\n");
	printf("|=======================================|\n");
}

void ler(imc *pimc){
	printf("Diite o nome, altura e peso\n");
	scanf("%s %f %f", pimc->nome, &pimc->altura, &pimc->peso);
	pimc->medida = pimc->peso +( pimc->altura * pimc->altura);
	
}
void inserir(Pilha *pimc, imc dado){
	No * novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo-> prox = pimc->topo;
	pimc->topo = novo;
}

void mostrar(Pilha pilha){
	No *pi;
     for(pi = pilha.topo; pi != NULL; pi = pi->prox){
		printf("|Nome: %s | IMC: %2.f|\n", pi->dado.nome, pi->dado.medida);
	}
}
//POP
void remover(Pilha *pimc){
	if(pimc->topo == NULL){
		printf("A pilha esta vazia\n");
	}
	else{
		No* pi = pimc->topo;
    	pimc->topo = pi->prox;
	    free(pi);
	    printf("Excluido\n");
	}
	
}
//isEmpty
int vazia(Pilha pilha){
	if(pilha.topo == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
No *topo(Pilha pilha){
	return pilha.topo;
}
int main(){
	Pilha pilha;
	pilha.topo = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 6){
		if(op == 1){
			imc pimc;
			ler(&pimc);
			inserir(&pilha, pimc);
			printf("\n");
		}
		else if(op == 2){
			mostrar(pilha);
			printf("\n");
		}
		else if(op == 3){
			remover(&pilha);
			printf("\n");
		}
		else if(op == 4){
			int idx = vazia(pilha);
			if(idx == 1){
				printf("A pilha esta vazia\n");
			}
			else{
				printf("A pilha contem imc\n");
			}
			printf("\n");
		}
		else if(op == 5){
			No* pi = topo(pilha);
			if(pi == NULL){
				printf("A pilha esta vazia\n");
			}
			else{
				printf("Nome %s| Altura %2.f| Peso %2.f| Media %2.f", pi->dado.nome, pi->dado.altura,
				 pi->dado.peso, pi->dado.medida);
			}
			printf("\n");
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}