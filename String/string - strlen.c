#include <stdio.h>
#include <string.h>

int main() {
	char s[500];
	printf("Digite qualquer coisa!\n ");
	scanf("%[^\n]s", s);
	// strlen serve para ler string
	    if(strlen(s) > 80){
		    printf("Tem mais de 80 caracteres \n");
	    }
	    else printf("Tem menos de 80 caracteres\n ");
    return 0;
}
  