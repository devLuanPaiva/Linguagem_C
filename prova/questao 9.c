#include<stdio.h>
#include <math.h>

int main() {
    int soma, i, j, M[12][12];
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
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(J==5){
				soma += a[i][j];
			}
		}	
    }
	printf("\n a soma dos numeros abaixo da diagonal e: %d", soma);
    return 0;
} 