#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	printf("Informe a quantidade de valores");
	scanf("%d", &n);
	int *v = (int *) calloc(n, sizeof(int));
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &v[i]);
	}
	for(i=0; i<n; i++){
		if(v[i] < 0){
			v[i] = 2;
		}
	}
	for(i=0; i<n; i++){
		printf("%d", v[i]);
	}
	printf("\n";)
}