#include <stdio.h>
#include <stdlib.h>
#include "Q4_pasta/Q4.h"
/*
Aluno: Luan Alves de Paiva
Matricula: 2020022483
*/
int main(){
    Fila* f = fila_cria();
    //A chamada anterior, se refere a criação de uma nova fila
    fila_insere(f,10);
    fila_insere(f,12);
    fila_insere(f,14);
    /*As tres chamadas ateriores, sao referentes aos numeros que serao 
	adicionados na fila*/
    float resultado = fila_retira(f);
    printf("O numero retirado foi: %.2f\n",resultado);
    //A chamada anterior, é referente ao primeiro item da fila que foi removido
    if(fila_vazia(f)){
      printf("esta vazia!!\n");
    }else{
      fila_imprime(f);
    }
    /*Se a fila tiver vazia, sera impressa a menssagem de vazia. Se nao tiver,
	sera impresso os itens restantes da fila*/
    
    fila_libera(f);
    //Apos essa funcao, a fila nao tera mais nada.
    return 0;
}