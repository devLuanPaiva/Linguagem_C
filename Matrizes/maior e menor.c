#include <stdio.h>
#include <math.h>

int main() {
    int a[3][3], i, j;
    int maior, menor;
  
    printf("Digite os numeros da primeira matriz! ");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%i", &a[i][j]);
        }
    }
    maior = 0;
    menor = 0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(a[i][j] > maior){
                maior = a[i][j];
               
            }
            if(a[i][j] < menor){
                menor = a[i][j];
               
            }
        }
    }   
	    printf("\nAs coordenadas %d sao as maiores", a[i][j]);
        printf("\nAs coordenada %d sao as menores!", a[i][j]);
    return 0;
}
 