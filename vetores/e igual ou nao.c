#include <stdio.h>
#include <math.h>

int main() {
    int a[10], i, b[10];
  
    printf("Digite os 10 numeros do primeiro vetor! ");
    for(i=0; i<10; i++){
        scanf("%i", &a[i]);
    }
    printf("\nDigite os 10 numeros do segundo vetor! ");
    for(i=0; i<10; i++){
        scanf("%i", &b[i]);
    }
    for(i=0; i<10; i++){
        if(a[i] == b[i]){
            printf("\n Na posicao %d o numero %d esta presente nos dois vetores\n", i, a[i]);
        } 
        else printf("\n Na posicao %d nao ha nenhum numero igual\n", i);
    }
    return 0;
}