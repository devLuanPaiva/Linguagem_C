#include <stdio.h>

int main() {
    
    char *palavra = (char *) malloc(sizeof(char) * 512);
    int flag = 0, indice = 0;

    gets(palavra);
    
    while (palavra[indice] != '\0') {
        indice++;
        
        if (indice > 80) {
            flag = 1;
            break;
        }
    }
    
    if (flag)
        printf("NO\n");
        
    else
        printf("YES\n");

    return 0;
}