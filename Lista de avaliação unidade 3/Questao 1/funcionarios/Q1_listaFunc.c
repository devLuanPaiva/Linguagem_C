#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q1_listaFunc.h"
/*
NOME:Luan Alves de Paiva
MATRICULA: 2020022483
*/

struct Funcionario {
    char depto[10]; 
    int mat;
    char nome[81];
    float salario;
};

struct no {
	funcionario dado;
	struct no *prox;	
};

struct lista {
	No *inicio;
};

void ler(funcionario *pe){
	printf("Digite o nome do departalemto \n");
	scanf("%s", pe->depto); 
	printf("Matricula \n"); 
	scanf(" %d", &pe->mat);
	printf("Nome do funcionario\n");
	scanf(" %s", pe->nome);
	printf("Salario do mesmo \n");
	scanf(" %f", &pe->salario);
	/*Essa funcao vai ler as caracteristicas dos funcionarios*/
}

void incerir_inicio(Lista *plista, funcionario dado){
	No * novo = (No*) malloc(sizeof(No));
	novo->dado = dado;
	novo->prox = plista->inicio;
	plista->inicio = novo;
	/*Essa funcao vai alocar um espaço na memoria para cada funcionario e vai
	colocando-os no inicio da lista por ordem de chegada, digamos assim.*/
}

Lista cria_lista(int n){
	Lista lista;
	lista.inicio = NULL;
	int i;
	for(i = 0; i < n ; i++){
		funcionario e;
		ler(&e);
		incerir_inicio(&lista, e);
   }
	return lista;
	/*Essa funcao vai ler do usuario um numero de funcionarios e vai criar
	uma lista de funcionarios com base nesse numero*/
}

void deletar_valor(Lista *plista, int mat){
   //Inicio == null;
	if(plista->inicio == NULL){
		printf("Lista esta vazia\n");
	}
	//No se localiza no inicio;
	else if(plista->inicio->dado.mat == mat){
		No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		printf("Funcionario excluido\n");
	}
	//Lista tem um unico No. Matricula nao existe
	else if(plista->inicio->prox == NULL){
		if(plista->inicio->dado.mat != mat){
			printf("O funcionario nao pode ser removido\n");
		}
	}
	//Lista com multiplos Nos:
	else{
		No* pa;
		No* pi;
		for(pi = plista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox){
			pa = pi;
		}
		//Valor nao existe
		if(pi == NULL){
			printf("O funcionario nao pode ser removido\n");
		}
		//Valor existe
		else{
			pa->prox = pi->prox;
			free(pi);
			printf("Funcionario escluido\n");
		}
	}
	/*Em resumo, essa funcao vai ler uma matricula do usuario, vai buscá-la
	e removela assim que a encontrar. Caso nao a encontre, ela nao existe.*/
}

void deletar_lista(Lista *plista){
	No* pi;
	while(plista->inicio != NULL){
		pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		
	}
	/*Essa funcao vai deletar toda a lista*/
}

No* pesquisar(Lista lista, int mat){
	No* pi;
	for(pi = lista.inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox);
	return pi;
    /*Essa funcao vai ler uma matricula do usuario e vai busca-la em toda a 
	lista, caso encontre-a, ele vai retorna-la. */
}

void imprimir_lista(Lista lista){
	No * pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
	     
	        printf("|Nome: %s| Matricula %d| Salario R$ %2.f|\n", pi->dado.nome, pi->dado.mat,
			  pi->dado.salario);
	      
    }  
	/*Essa funcao vai imprimir todos os funcionarios da lista*/     
}

void mostrar(Lista lista, char s1[]){
	No * pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
	     if(strcmp(pi->dado.depto, s1) == 0){
	        printf("|Nome: %s| Matricula %d| Salario R$ %2.f|\n", pi->dado.nome, pi->dado.mat,
			 pi->dado.salario);
	      }
    } 
	/*Essa funcao vai imprimir todos os funcionarios referentes a um determinado
	departamento da empresa. Isso sera feito atravez da condição do if, que vai 
	verificar se a string definida pelo usuario é igual a alguma das que estao
	na lista. Caso seja verdade, os dados serao apresentados.*/      
}

void folha_pagamento(Lista lista, char* s1){
  float totalGasto = 0;
  No * pi;
	for(pi = lista.inicio; pi != NULL ; pi = pi->prox){
	     if(strcmp(pi->dado.depto, s1) == 0){
		      totalGasto += pi->dado.salario;
        }
	}
	printf("o gasto total do departamento %s foi de: R$ %.2f\n",s1,totalGasto);
	/*Assim como na funcao anterior, o if vai verificar se o departamento 
	declarado pelo usuario existe ou nao. Caso exista, a funcao vai somar todos
	os salarios referentes aos funcionarios daquele departamento e vai dizer
	o total.*/
}    

void menu(){
	printf("|========== MENU DO EMPRESA ============|\n");
	printf("|1 - Inserir novo                    	|\n");
	printf("|2 - Imprimir lista por departamento    |\n");
	printf("|3 - Pesuisar funcionario               |\n");
	printf("|4 - Deletar funcionario                |\n");
	printf("|5 - Deletar lista                      |\n");
	printf("|6 - Criar lista completa               |\n");
	printf("|7 - Mostrar folha de pagamento         |\n");
	printf("|8 - Mostrar toda a lista               |\n");
	printf("|9 - Sair                               |\n");
	printf("|=======================================|\n");
}

void main_empresa(){
	Lista lista;
	lista.inicio = NULL;
	int op;
	menu();
	scanf("%d", &op);
	while(op != 9){
		if(op == 1){
			funcionario e;
			ler(&e);
			incerir_inicio(&lista, e);
			printf("\n");
		}
		else if(op == 2){
			char s1[10];
			printf("Digite o departamento\n");
			scanf("%s", s1);
			mostrar(lista, s1);
			printf("\n");
		}

		else if(op == 3){
			int mat;
			printf("Informe a matricula\n");
			scanf("%d", &mat);
			No * pi = pesquisar(lista, mat);
			if(pi != NULL){
				printf("|Nome: %s| Matricula %d|\n", pi->dado.nome, pi->dado.mat);
			}
			else{
				printf("Funcionario nao encontrado\n");
			}
			printf("\n");
		}

		else if(op == 4){
			int mat;
			printf("Informe a matricula para ser deletada\n");
			scanf("%d", &mat);
			deletar_valor(&lista, mat);
			printf("\n");
		}

		else if(op == 5){
			deletar_lista(&lista);
			printf("Lista deletada\n");
			printf("\n");
		}
		else if(op == 6){
			int n;
			printf("Informe a quantidade de elementos\n");
			scanf("%d", &n);
			lista = cria_lista(n);
			printf("\n");
		}
		else if(op == 7){
			char s1[10];
			printf("Digite o departamento\n");
			scanf("%s", s1);
			//imprimir_lista(lista);
			folha_pagamento(lista, s1);
      
			printf("\n");
		}
		else if(op == 8){
			imprimir_lista(lista);
			printf("\n");
		}
		menu();
		scanf("%d", &op);
		
		/*Todas as opcoes desse menu, sao referentes as funcoes ja comentadas
		anteriormente*/
	}
	/*Como pode perceber, esse int main virou uma funcao do tipo void que sera
	chamada la no int main*/
}