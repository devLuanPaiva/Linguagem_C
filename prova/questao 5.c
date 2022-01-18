#include <stdio.h>

int main(){
    int i, maior;
	float x[100];
	for(i = 0; i < 100; i++){
		scanf("%f", &x[i]);
	}
    maior = 0;
	for(i = 0; i < 100; i++){
		if( x[i] <=10){
            printf("A[%i] = %0.1f\n",i, x[i]);
		}
	}   
 
	return(0);
}