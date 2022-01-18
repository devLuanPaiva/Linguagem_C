#include <stdio.h>
#include <math.h>

int main() {
    int a[4][4], i, j;
    int  soma, maior, produto;
    printf("Digite os numeros dessa matriz!");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%d", &a[i][j]);
        }
    }
  
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){  
            printf("%d ", a[i][j]);
        }   
        putchar('\n');
    }
	soma = 0;
	maior = 0;
	produto = 0;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(i==j){
                if(a[i][j] > maior){
				    maior = a[i][j];	
				}
            }
			else if(i > j){
				soma += a[i][j];
			}
			else if(i < j){
				produto *= a[i][j];
			}
        }
    }
	printf("\n O maior numero da diagonal e: %d", maior);
	printf("\n a soma dos numeros abaixo da diagonal e: %d", soma);
	printf("\n O produto dos numeros acima da diagonal e: %d", produto);
    return 0;
}