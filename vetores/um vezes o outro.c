#include <stdio.h>

int main() {
    int a[10], i, b[10], mult;
  
    printf("Digite os 10 numeros do primeiro vetor! ");
    for(i=0; i<10; i++){
        scanf("%i", &a[i]);
    }
    printf("\nDigite os 10 numeros do segundo vetor! ");
    for(i=0; i<10; i++){
        scanf("%i", &b[i]);
    }
    for(i=0; i<10; i++){
        mult = a[i] * b[i];
        printf("\n Na posicao %d o resultado foi: %d\n", i, mult);
    }
    return 0;
}