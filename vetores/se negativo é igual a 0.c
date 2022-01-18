#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
	float x[5];
	
	// Responsável por inicializar o vetor
    printf("Digite 5 numeros reais! ");
	for(i = 0; i < 5; i++){
		scanf("%f", &x[i]);
	}
	
	for(i = 0; i < 5; i++){
		if(x[i] < 0){
           x[i ]= 0.00; 
		}
	}  
    for(i = 0; i < 5; i++){
        printf("x[%i] = %.2f\n", i, x[i]);;
    }
	printf("\n\n");
	system("pause");
	return(0);
  }
