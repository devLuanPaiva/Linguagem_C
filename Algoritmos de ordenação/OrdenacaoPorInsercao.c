#include <stdio.h>
int main(){
	int n;
	printf("Informe o valor de n\n");
	scanf("%d", &n);
	int i, j;
	int v[n];
	for(i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	for( i = 1;i<n;i++){
        int x =	v[i];
	    for(j= i-1; j >= 0 && x <v[j]; j--){
		    v[j + 1] = v[j];
	    }
 	    v[j + 1] = x;
	}
	printf("Imprimindo o vetor ordenado\n");
	for(i=0; i < n; i++){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}