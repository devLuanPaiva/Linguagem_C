#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int particao(int e, int d, int v[]){
	srand(time(NULL));
	int idx = e + (rand() % (d - e));
	int temp = v[idx];
	v[idx] = v[d];
	v[d] = temp;
	int j = e - 1;
	int i;
	int pivo = v[d];
	for(i = e; i<d; i++){
		if(v[i] <= pivo){
			j++;
			int temp = v[j];
			v[j] = v[i];
			v[i] = temp;
		}
	}
	temp = v[j + 1];
	v[j + 1] = v[d];
	v[d] = temp;
	return j + 1;
}
int quicksort(int i, int f, int v[]){
	if(i < f){
		int p = particao(i, f, v);
		quicksort(i, p -1, v);
		quicksort(p+1, f, v);
	}
}
int main(){
	int n, i;
	printf("Informe o valor do vetor\n");
	scanf("%d", &n);
	int v[n];
	for(i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	quicksort(0, n -1, v);
	printf("Imprimindo o resultado\n");
	for(i=0; i<n; i++){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}