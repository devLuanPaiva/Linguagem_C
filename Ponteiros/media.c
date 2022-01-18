#include  <stdio.h>
int main(){
    //! showMemory(start=65520)
    float a, b, media;
    float *pA, *pB, *pM;
    pA = &a;
    pB = &b;
    pM = &media;
        printf("Informe os valores de A e B\n");
        scanf("%f %f", pA, pB);
        *pM = (*pA*3.5 + *pB*7.5)/11;
        printf("Media: %.5f \n", *pM);
        printf("Endereco da media: %p \n", pM);
	
	return 0;
}