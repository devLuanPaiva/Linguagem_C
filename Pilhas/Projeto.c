#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Campeonato Brasileiro
// Luan Alves de Paiva
typedef struct {
	char nome[10];
	int vitorias;
	int empates;
	int pontos;
	int saldoGol;	
} Times;
struct no{
	Times dado;
	struct no *prox;
};
typedef struct no No;
typedef struct{
	No * topo;
}Pilha;

void menu(){
	printf("|========== MENU DO ESCOLAR ============|\n");
	printf("|1 - Inserir novo time               	|\n");
	printf("|2 - Mostrar times                      |\n");
	printf("|3 - Remover o primeiro time            |\n");
	printf("|4 - Verificar se esta vazia            |\n");
	printf("|5 - Pegar o time do topo               |\n");
	printf("|6 - Sair                               |\n");
	printf("|=======================================|\n");
}

void lerTime(Times *ptimes){
	printf("Digite o nome do time \n");
	scanf("%s", ptimes->nome);
	printf("Digite o numero de vitorias e empates\n");
	scanf("%d %d", &ptimes->vitorias, &ptimes->empates);
	printf("Digite o saldo de gols\n");
	scanf("%d", &ptimes->saldoGol);
	ptimes->pontos = (ptimes->vitorias * 3) + ptimes->empates;
}
void inserir(Pilha *ptimes, Times dado){
	No * novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo-> prox = ptimes->topo;
	ptimes->topo = novo;
}

void mostrar(Pilha pilha){
	No *pi;
	for(pi = pilha.topo; pi != NULL; pi = pi->prox){
		printf("|Nome: %s| Pontos %d| Vitorias %d| Empates %d| Saldo de Gols %d|\n", 
		pi->dado.nome, pi->dado.pontos, pi->dado.vitorias, pi->dado.empates, pi->dado.saldoGol);
	}
}
//POP
void remover(Pilha *ptimes){
	if(ptimes->topo == NULL){
		printf("A pilha esta vazia\n");
	}
	else{
		No* pi = ptimes->topo;
    	ptimes->topo = pi->prox;
	    free(pi);
	    printf("Time excluido\n");
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
			Times ptimes;
			lerTime(&ptimes);
			inserir(&pilha, ptimes);
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
				printf("A pilha contem times\n");
			}
			printf("\n");
		}
		else if(op == 5){
			No* pi = topo(pilha);
			if(pi == NULL){
				printf("A pilha esta vazia\n");
			}
			else{
				printf("|Nome: %s| Pontos %d| Vitorias %d| Empates %d| Saldo de Gols %d|\n", 
                pi->dado.nome, pi->dado.pontos, pi->dado.vitorias, pi->dado.empates, pi->dado.saldoGol);
			}
			printf("\n");
		}
		menu();
		scanf("%d", &op);
	}
	return 0;
}