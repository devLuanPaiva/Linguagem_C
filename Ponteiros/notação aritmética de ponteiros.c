#include <stdio.h>

int main(){
	//!showMemory(start=65520)
	float e1[2];
	float e1[2];
	float e1[2];
	float *notas[3];
	notas[0] = e1;
	notas[1] = e2;
	notas[2] = e3;
	int i;
	    for(i=0; i<3; i++){
			scanf("%f %f", (notas[i]+0), (notas[i]+1));
		}
		for(i=0; i<3; i++){
			if(*(notas[i]+0) > *(notas[i]+1)){
				printf("Sua nota e: %.1f", notas[i]+0);
			}
			else printf("Sua nota e: %.1f", notas[i]+1);
		}
	return 0;	
}