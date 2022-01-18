#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char voto[6];
	
	// Local de retorno do comando goto
	corrige:
	printf("Digite seu voto: ");
	scanf(" %[^\n]s", voto);
	
	if(strcmp(voto, "CORRIGE") == 0){
		printf("\n\tVoto CORRIGIDO!\n\n");
		system("pause");
		system("cls");
		goto corrige; // Ao usar goto, o fluxo retorna para o local especificado
	}
	
	system("pause");
	return(0);
}