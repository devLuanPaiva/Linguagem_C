#include <stdio.h>
int main(void){
	int x = 10;
	int *ponteiro;
	ponteiro = &x;
	//Imprimir o valor do endereço de memoria
	printf("%i \n", ponteiro);
	
	//Imprimir o endereço de memoria
	printf("%i \n", *ponteiro);
	
	getchar ();
	return 0;
	
}