#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct{
    No *raiz;
}ArvB;

No* inserirNovaVersao(No *raiz, int valor){
    if(raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }else{
        if(valor < raiz->conteudo){
            raiz->esquerda = inserirNovaVersao(raiz->esquerda, valor);
        }
        if(valor > raiz->conteudo){
            raiz->direita =inserirNovaVersao(raiz->direita, valor);
        }
      return raiz;
    }
}
void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz->esquerda);
        printf(" %d ", raiz->conteudo);
        imprimir(raiz->direita);
      
    }
}
int main(){
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n");
        scanf("%d", &op);

        switch(op){
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                arv.raiz = inserirNovaVersao(arv.raiz, valor);
                //inserir(&arv, valor);
                break;
            case 2:
                printf("\nImprimindo a arvore:\n");
                imprimir(arv.raiz);
                printf("\n");
                break;
            default:
                printf("\nOpção inválida..\n");
                break;
        }
    }while(op != 0);
    return 0;
}