#include <stdio.h>

int main{
    //! shoMemory(start=65520)
	float e1[2];
	float e1[2];
	float e1[2];
	float *estudantes[3];
	estudantes[0] = e1;
	estudantes[1] = e2;
	estudantes[2] = e3;
	int i;
	for(i=0; i<3; i++){
		scanf("%f %f", &estudantes[i][0], &estudantes[i][0]);
	}
	for(i=0; i<3; i++){
		float media = (estudantes[i][0] + estudantes[i][1])/2;
		printf("%.1f", media);
	}
	return 0;
	
}