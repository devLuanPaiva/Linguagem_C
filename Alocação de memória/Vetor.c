#include <stdio.h>
#include <stdlib.h>

int main(){
	//! showMemory(start=322)
	int n;
	printf("Informe a quantidade de valores\n");
	scanf("%d", &n);
	int *v = (int *) malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}
	int maior = v[0];
	for(i=1; i<n; i++){
		if(v[i] > maior){
			maior = v[i];
		}
	}
	printf("Maior: %d\n", maior);
}	