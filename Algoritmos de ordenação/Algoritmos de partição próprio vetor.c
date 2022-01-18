#include <stdio.h>

void particao(int n, int v[]){
	int pivo = v[n - 1];
	int i, j = -1;
	for(i=0; i < n -1; i++){
		if(v[i] < pivo){
			j++;
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	int temp = v[j + 1];
	v[j + 1] = v[n - 1];
	v[n - 1] = temp;
}
int main(){
	int n, i;
	printf("Informe o valor do vetor\n");
	scanf("%d", &n);
	int v[n];
	for(i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	particao(n, v);
	printf("Imprimindo o vetor particionado\n");
	for(i=0; i<n; i++){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}