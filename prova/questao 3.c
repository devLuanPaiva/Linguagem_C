#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, maior;
	int x[100];
	
	for(i = 0; i < 100; i++){
		scanf("%d", &x[i]);
	}
    maior = 0;
	for(i = 0; i < 100; i++){
		if( x[i] <= 0){
            x[i] = 1; 
		} printf("X[%i] = %d\n",i, x[i]);
	}
	return(0);
}