#include <stdio.h>

void particao(int n, int v[]){
	int s[n];
	int i;
	int e = 0;
	int d = n -1;
	int pivo = v[n - 1];
	for(i=0; i < n; i++){
		if(v[i] <= pivo){
			s[e] = v[i];
			e++;
		}
		else{
			s[d] = v[i];
			d--;
		}
	}
	for(i=0; i < n; i++){
		v[i] = s[i];
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
	particao(n, v);
	printf("Imprimindo o vetor particionado\n");
	for(i=0; i<n; i++){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}