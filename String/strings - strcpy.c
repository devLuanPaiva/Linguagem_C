#include <stdio.h>
#include <string.h>

int main() {
	char s1[50];
	char s2[50];
	printf("Digite duas palavras!\n ");
	scanf("%s", s1);
	//strcpy serve para copiar string!
	strcpy(s2, s1);
	printf("%s", s1);	
    return 0;
}
 