#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Informe a quantidade de valores");
	scanf("%d", &n);
	int *v = (int *) malloc(n * sizeof(int));
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	v = (int *) realloc(v, 2 * n * sizeof(int));
	int k = 1;
	for(i=n; i< 2 * n; i++){
		v[i] = k;
		k++;
	}
	for(i=n; i< 2 * n; i++){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}	