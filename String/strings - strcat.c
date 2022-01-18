#include <stdio.h>
#include <string.h>

int main() {
	char s1[50];
	char s2[50];
    printf("Digite duas palavras\n ");
	scanf("%s %s", s1, s2);
	// strcat serve para concatenar as duas strings
	strcat(s1, s2);
	printf("\n\n %s", s1);
    return 0;
}
  