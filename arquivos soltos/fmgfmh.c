#include <stdio.h>

int main() {

    int quantidade;
    int vet[quantidade];
    int i, maior, menor, soma ;
        printf("Quantos numeros voce deseja colocar? \n");
        scanf("%d", &quantidade);
        printf("\nEntao digite os numeros: ");
        for(i=0; i<quantidade; i++){
            scanf("%d", &vet[i]);
        }
        for(i=0; i<quantidade; i++){
	        soma += vet[i];
        }
        printf("\nA media e: %d", soma/quantidade);
        for(i=0; i<quantidade; i++){
            if(vet[i] > maior){
                (maior=vet[i]);
            }
            if(vet[i] < menor){
                (menor=vet[i]);
            }
        }
		printf("\nO maior numero e: %d", maior);
		printf("\nO menor numero e: %d", menor);

    return 0;
}
