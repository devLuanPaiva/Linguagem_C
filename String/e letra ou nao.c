#include <stdio.h>
#include <string.h>
int main(void){
	void alfabetico(char variavel);
	char nome[20];
	
	printf("Digite uma palavra: \n");
	scanf("%s", nome);
	
	int i = 0;
	while(nome[i] != '\0'){
		alfabetico(nome[i]);
		i++;
	}
	return 0;
}
void alfabetico(char variavel){
	if((variavel >= 'a' && variavel <='z') ||
	   (variavel >= 'A' && variavel <='Z')){
		   printf("E uma letra! \n");
	   }
	else printf("Nao chega nem perto de ser uma letra!\n");   
}
