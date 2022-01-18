#include <stdio.h>

int main() {

    int qtd, x, y;
    float vet1[qtd];
	float vet2[qtd];
    float  maior, menor, soma ;
        printf("Digite a quantidade de numero desejada \n");
        scanf("%d", &qtd);
        printf("\n digite os numeros do vetor 1\n ");
        for(x=0; x<qtd; x++){
            scanf("%f", &vet1[x]);
        }
        for(x=0; x<qtd; x++){
	        soma += vet1[x];
        }
        printf("\nA media e: %f", soma/qtd);

		x=0;
        for(x=0; x<qtd; x++){
			maior = vet1[x];
            if( vet1[x] > maior){
                maior = vet1[x];
            }
			menor = vet1[x];
            if( vet1[x] < menor){
                menor = vet1[x];
            }
        }
		printf("\nO maior numero e: %f \nO menor numero e: %f", menor, maior);


        printf("\ndigite os numeros do vetor 2: ");
        for(y=0; y<qtd; y++){
            scanf("%f", &vet2[y]);
        }
        for(y=0; y<qtd; y++){

        }if(vet2[y] == vet1[x]){
				printf("\n Sao iguais!");
			}
			else printf("\nSao diferentes!");

    return 0;
}
