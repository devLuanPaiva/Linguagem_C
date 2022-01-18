#include <stdio.h>
#include <string.h>

int main() {
	char s1[50];
	char s2[50];
	printf("Digite duas palavras!\n ");
	scanf("%s %s", s1, s2);
	
	// strcmp serve para comparar string
	if(strcmp(s1, s2) == 0){
		printf("As duas sao identicas\n");
	}
	else if (strcmp(s1, s2) < 0){
		printf("A primeira palavra e maior\n ");
	}
	else printf("A segunda palavra e maior\n ");
    return 0;
}