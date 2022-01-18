#include<stdio.h>
#include<stdlib.h>

int main(){
	//! showMemory(start=290)
	int i, j;
	int **m = (int **) malloc(3 * sizeof(int *));
	for(i = 0; i < 3; i++){
		m[i] = (int *) malloc(2 * sizeof(int));	
	}
	printf("Informe os valores \n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			scanf("%d", &m[i][j]);
		}
	}
	int impar = 0;
	int par = 0;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			if(m[i][j] % 2 == 0){
				par++;
			}
			else {
				impar++;
			}
		}
	}
	printf("Impares: %d\nPares: %d", impar, par);
	return 0;
}