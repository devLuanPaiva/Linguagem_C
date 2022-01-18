#include <stdio.h>
#include <stdlib.h>

int main(){
	//! showMemory(start=312)
	void *pn = malloc(sizeof(int));
	printf("Informe o valor de N \n");
	scanf("%d", (int *) pn);
	int i;
	int positivos = 0;
	for (i=0; i< *(int *) pn); i++){
		void *pv = malloc(sizeof(float));
		scanf("%f", (float *) pv);
		if(*((float *)pv) > 0){
			positivos++;
		}
	}
	printf("Positivos: %d\n", positivos);
	return 0;
}