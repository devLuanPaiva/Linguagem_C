#include <stdio.h>

int main() {
    int numero = 0, i;
    float soma, media, nota;
        printf("Insira a quantidade de notas\n ");
        scanf("%d", &numero);

    for(i = 1; i <= numero; i++){
        printf("Digite a nota: %d", i);
        scanf("%f", &nota);
    soma += nota;
    }

    media =(soma)/ nota;
        printf("\n a media é: %f", media);
    return 0;

}  