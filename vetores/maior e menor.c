#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, maior, menor;
	int x[10];
	
	// Responsável por inicializar o vetor
    printf("Digite 10 numeros reais! ");
	for(i = 0; i < 10; i++){
		scanf("%d", &x[i]);
	}
    maior = 0;
    menor = 0;
	for(i = 0; i < 10; i++){
		if( x[i] > maior){
            maior = x[i]; 
		}
        if(x[i] < menor){
            menor = x[i];
        }
      
	}  
 
    printf("\n O numero %i e o maior de todos", maior);
    printf("\n O numero %i e o menor de todos", menor);
  
	printf("\n\n");
	system("pause");
	return(0);
}