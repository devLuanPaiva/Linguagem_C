#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Q5.h"

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

}

float fila_retira(Fila* f){
  if (f->inicio == NULL){
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
}

int fila_vazia(Fila* f){
  return (f->inicio == NULL);
}

void fila_imprime(Fila* f){
  No* pi;
  for(pi = f->inicio; pi != NULL; pi = pi->prox){
    printf("%.2f ",pi->v);
  }
  printf("\n");
}

void fila_libera(Fila* f){
  if(!fila_vazia(f)){
    No *proxNode, *atual;

    atual = f->inicio;
    while(atual != NULL){
      proxNode = atual->prox;
      free(atual);
      atual = proxNode;
    }
  }
}

void combina(Fila* copy, Fila* f1, Fila* f2){
  if(fila_vazia(copy)){
  	No*pi;
    if(f1->inicio == NULL && f2->inicio != NULL){
      for( pi = f2->inicio; pi != NULL; pi =
      pi->prox){
        No* novo = (No*) malloc(sizeof(No));
        novo->v = pi->v;
        novo->prox = NULL;

        if(copy->inicio == NULL){
          copy->inicio = novo;
          copy->fim = novo;
        }else{
          copy->fim->prox = novo;
          copy->fim = novo;
        }
      }
    }
	else if(f1->inicio != NULL && f2->inicio == NULL){
		No*pi;
      for( pi = f1->inicio; pi != NULL; pi =
      pi->prox){
        No* novo = (No*) malloc(sizeof(No));
        novo->v = pi->v;
        novo->prox = NULL;

        if(copy->inicio == NULL){
          copy->inicio = novo;
          copy->fim = novo;
        }else{
          copy->fim->prox = novo;
          copy->fim = novo;
        }
      }

    }else{
      No* p = f2->inicio;
      No* pi;
      for( pi = f1->inicio; pi != NULL;pi = pi->prox){
        No* novo = (No*) malloc(sizeof(No));
        novo->v = pi->v;
        novo->prox = NULL;

        if(copy->inicio == NULL){
           copy->inicio = novo;
           copy->fim = novo;
        }
        if(copy->inicio != NULL){
          if(p != NULL){
            No* novo = (No*) malloc(sizeof(No));
            novo->v = p->v;
            novo->prox = NULL;

            copy->fim->prox = novo;
            copy->fim = novo;
          }

          No* ppi = pi->prox;
          if(pi != NULL && ppi != NULL){
            No* novo = (No*) malloc(sizeof(No));
            novo->v = ppi->v;
            novo->prox = NULL;

            copy->fim->prox = novo;
            copy->fim = novo;
          }
          if(pi->prox != NULL && ppi == NULL){
            No* novo = (No*) malloc(sizeof(No));
            novo->v = pi->v;
            novo->prox = NULL;

            copy->fim->prox = novo;
            copy->fim = novo;
          }
          if(pi != NULL && p == NULL){
            No* novo = (No*) malloc(sizeof(No));
            novo->v = p->v;
            novo->prox = NULL;

            copy->fim->prox = novo;
            copy->fim = novo;
          }
        }
      }
    }
  }
}