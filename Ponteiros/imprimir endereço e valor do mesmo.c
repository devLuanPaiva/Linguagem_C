#include <stdio.h>
int main(void){
	int x;
	x = 10;
	
	//Imprimir o valor do endereço de memoria
	printf("%i \n", x);
	
	//Imprimir o endereço de memoria
	printf("%i \n", &x);
	
	getchar ();
	return 0;
	
}