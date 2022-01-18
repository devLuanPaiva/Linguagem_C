#include <stdio.h>
#include <stdlib.h>

int main(){
	//! showMemory(start=327)
	int pares = 0;
	int impares = 0;
	int *pa = (int *) malloc(sizeof(int));
	printf("Informe o valor de A\n");
	scanf("%d", pa);
	if(*pa %2 == 0){
		pares++;
	}
	else impares++;
	free(pa);
	
	int *pb = (int *) malloc(sizeof(int));
	printf("Informe o valor de B\n");
	scanf("%d", pb);
	if(*pb %2 == 0){
		pares++;
	}
	else impares++;
	free(pb);
	int *pc = (int *) malloc(sizeof(int));
	printf("Informe o valor de C\n");
	scanf("%d", pc);
	if(*pc %2 == 0){
		pares++;
	}
	else impares++;
	free(pc);
	
	if(pares > impares){
		printf("Teve mais numeros pares!\n");
	}
	else printf("Teve main numeros impares!\n");
	
	printf("Pares: %d\n", pares);
	printf("Impares: %d\n", impares);
	return 0;
}	