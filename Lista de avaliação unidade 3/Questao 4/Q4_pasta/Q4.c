#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q4.h"
/*
Aluno: Luan Alves de Paiva
Matricula: 2020022483
*/
typedef struct no No;
struct no {
  float v;
	No *prox;	
};

struct fila{
  No* inicio;
  No* fim;
};

Fila* fila_cria(void){
  Fila* f = (Fila*) malloc(sizeof(Fila));
  f->inicio = NULL;
  f->fim = NULL;
  return f;
  
  /*Essa funcao vai alocar espaço na memoria suficiente para
  os tres elementos da pilha declarados no int main*/
}

void fila_insere(Fila* f, float v){
  No* novo = (No*) malloc(sizeof(No));
  novo->v = v;
  novo->prox = NULL;

  if(f->inicio == NULL){
    f->inicio = novo;
    f->fim = novo;
  }else{
    f->fim->prox = novo;
    f->fim = novo;
  }
  /*Essa funcao vai inserir aqueles tres numeros na fila, de modo que o 
  primeiro fique no inicio da fila e os demais fiquem no final. Assim como em
  uma fila na vida real organizada por ordem de chegada.*/
}

float fila_retira(Fila* f){
  if(f->inicio == NULL){
    return -1;
  }else if(f->inicio->prox == NULL){
    float numero = f->inicio->v;
    f->inicio = NULL;
    f->fim = NULL;
    return numero;
  }else{
    float numero = f->inicio->v;
    No* pi = f->inicio;
    f->inicio = pi->prox;
    free(pi);
    return numero;
  }
  /*Essa funcao vai retirar o primeiro item da fila*/
}

int fila_vazia(Fila* f){
  return (f->inicio == NULL);
  /*Essa funcao so vai retornar se a pila esta vazia, se a condiçao acima
  for verdadeira*/
}

void fila_imprime(Fila* f){
  No* pi;
  for(pi = f->inicio; pi != NULL; pi = pi->prox){
    printf("Os numeros restantes da fila: %.2f \n",pi->v);
  }
  /*Essa funcao vai imprimir todos os elementos da fila que ficaram apos a 
  retirada do item inicial*/
}

void fila_libera(Fila* f){
 if(!fila_vazia(f)){
  No *proxNode, *atual;

  atual = f->fim;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
   /*Esse while ta dizendo que enquanto a posição atual da fila for 
   diferente de null, podia excluir ela.*/
  }
  /*Essa funcao vai limpar a fila toda*/
 }
}
