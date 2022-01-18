#include <stdio.h>
int positivos(int i, int n, int v[]){
	if(i == n){
		return 0;
	}
	if(v[i] > 0){
		return 1 + positivos(i+1, n, v);
	}
	return positivos(i+1, n, v);
}
int main(){
	int n, i;
	printf("Informe o valor de n\n");
	scanf("%d", &n);
	int v[n];
	for(i=0; i<n ; i++){
		scanf("%d", &v[i]);
	}
	int r = positivos(0, n, v);
	printf("%d\n", r);
	
	return 0;
}	