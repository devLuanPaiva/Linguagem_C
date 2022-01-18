#include <stdio.h>
#include <stdlib.h>

int main(){
	//! showMemory(start=290)
	int *m = (int *) malloc(3 * 2 * sizeof(int));
	printf("Informe os valores\n");
	int i, j;
    for(i=0; i<3; i++){
		for(j=0; j<2; j++){
			scanf("%d", m + (i * 2) + j);
		}
	}
	int positivo = 0;
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
		    if(*(m + (i * 2) + j)>0){	
			positivo++;
		    }	
		}
	}
	int negativo = 0;
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
		    if(*(m + (i * 2) + j)< 0){	
			negativo++;
		    }	
		}
	}
	if (positivo > negativo){
		printf("Tem mais numeros positivos\n");
	}
	else if(negativo > positivo){
		printf("Tem mais numeros negativos\n");
	}
	printf("Tem %d numeros positivos e %d negativos!\n", positivo, negativo);
	for(i=0; i<3; i++){
		for(j=0; j<2; j++){
			printf("\n %d",* (m + (i * 2) + j));
		}
	}
	
	return 0;
}