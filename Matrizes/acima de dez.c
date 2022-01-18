#include <stdio.h>
#include <math.h>

int main() {
    int a[5][5], i, j;
    int maior;
    printf("Digite os numeros da matriz");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            scanf("%d", &a[i][j]);
        }
    }
	maior = 0;
	for(i=0; i<5; i++){
        for(j=0; j<5; j++){  
        if(a[i][j] > 10)
            maior++;		
        }
         
    }  
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){  
            printf("%d ", a[i][j]);
        }
         putchar('\n');
    }  
	printf("Nessa matriz tem %d acima de 10", maior);
   
    return 0;
}
 