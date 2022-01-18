#include <stdio.h>
#include <stdlib.h>
#include "Q2_pasta/Q2.h"
/*
Nome: Luan Alves de Paiva
Mat: 2020022483
*/
int main(){
	 int n;
	 printf("Digite o numero de caracteres ");
	 scanf("%d", &n);
	 
	 printf("Agora digite eles \n"); 
	 Pilha* p = pilha_criar();
	 char* c = (char*) malloc (n * sizeof(char));
     /*A funcao acima vai rezervar espaço na memoria para os n elementos*/
    int i;
    for(i = 0; i < n; i++){
      scanf(" %c",c);
      fila_insere(p, *c);
    } 
	/*O for acima é responsavel por adicionar os n elementos na pilha 
	de caracteres*/
	
    int idx = pilha_vazia(p);
    if(idx == -1){
		printf("A pilha esta vazia \n");
	}
	else {
		printf("A pilha ja contem elementos\n");
	}
    /*O if acima foi para dizer se a pilha continha elementos*/
    
    char result = pilha_pop(p);
    printf("O caractere retirado do topo eh: %c\n",result);
    /*A funcao acima foi para apresentar o caractere que foi 
	retirado do topo */
	
    pilha_libera(p);
    printf("Ja tem espaco liberado na pilha\n");
    /*A funcao acima limpou a pilha*/

	return 0;
}

