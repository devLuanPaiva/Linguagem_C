#include <stdio.h>
int main(){
	FILE *file = fopen("naoexiste.b", "rb");
	if(file == NULL){
		printf("Ocorreu um erro ao abrir o aquivo\n");
		perror(file);
		system("pause");
		exit(1);
	}
}