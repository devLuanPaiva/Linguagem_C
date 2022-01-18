#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q2.h"
/*
NOME:Luan Alves de Paiva
MATRICULA: 2020022483
*/

typedef struct no No;
struct no {
  char nome;
	No *prox;	
};

struct pilha{
  No* topo;
};


Pilha* pilha_criar(void){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
  /*Essa funcao aq vai criar uma pilha e vai reservar espaço na memoria para
  cada elemento da mesma. */
}

void fila_insere(Pilha* p, char c){
  No* novo = (No*) malloc(sizeof(No));
  novo->nome = c;
  novo->prox = p->topo;
  p->topo = novo;
  /*Essa funcao aqui vai reservar espaço na memoria para cada item inserido
   na pilha e vai por esse elemento no topo. */
}

char pilha_pop(Pilha* p){
  if(p->topo == NULL){
    return 'x';
  }
  else {
      char letra;
      No* pop = p->topo;
      p->topo = pop->prox;
	  letra = pop->nome;
	  free(pop);
	  return letra;
  }
  /*Essa funcao vai remover o elemento que esta no topo da lista caso a mesma nao
  esteja vazia*/
  
}

void pilha_libera(Pilha* p){
   No* pi  = p->topo;
   p->topo = pi->prox;
   free(pi);
    /*Essa funcao vai esvaziar a lista para liberar espaço na memoria.*/
}
int pilha_vazia(Pilha* p){
  if(p->topo == NULL){
	  return -1;
  }
  else{
	  return 0;
  }
  /*Essa funcao vai retornar se a pilha esta vazia */
}