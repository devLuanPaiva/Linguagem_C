#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, contpar, contimpar;
	int x[10];
	
	// Responsável por inicializar o vetor
    printf("Digite 10 numeros reais! ");
	for(i = 0; i < 10; i++){
		scanf("%d", &x[i]);
	}
	contpar = 0;
	for(i = 0; i < 10; i++){
		if(x[i] %4 == 0){
            contpar += 1; 
		}
      
	}  
 
    printf("\n O vetor tem %i numeros multiplos de 4", contpar);
  
	printf("\n\n");
	system("pause");
	return(0);
  }
