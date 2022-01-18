#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, i, x;
    printf("informe o valor de n:\n");
    scanf("%d",&n);
    int *v=(int*)malloc(n*sizeof(int));

    printf("informe os valores do vetor v:\n");
    for(i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    printf("informe o valor X:\n");
    scanf("%d",&x);
    int maiores=0, iguais=0;
    for(i=0;i<n;i++){
		if(v[i] > x){
			maiores++;
		}	
        else if(v[i] == x){
			iguais++;
        }
	}	
	if(x > 0){
		printf("os valores maior ou iguais sao\n");  
    }	
    for(i=0; i<n; i++){
		if(v[i]>x || v[i]==x){
			printf("%d\n", v[i]);
		}
	}
	free(v);
	return 0;

}