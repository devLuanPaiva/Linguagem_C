#include <stdio.h>

int main() {
    int distancia;
    float velocidade, tempo;
        printf("Qual a distancia entre os radares? ");
        scanf("%d", &distancia);
        printf("\nQuanto tempo o condutor levou para percorrer a distancia?");
        scanf("%f", &tempo);

    velocidade = (distancia/ tempo); 
    if(velocidade <= 80){
        printf("\n O motorista nao vai levar multas!");
    }
    else{
        printf("\n O motorista vai levar multas!");
    }
        printf("\n A velocidade do motorista foi de: %f", velocidade);
    return 0;
}
 