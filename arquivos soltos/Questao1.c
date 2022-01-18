#include <stdio.h>

int main() {
    int idad1, idad2, salar1, salar2;
    float altu1, altu2;
        printf("Qual a altura das duas pessoas? ");
        scanf("\n %f \n %f", &altu1, &altu2);
        printf("\n Qual a idade das duas pessoas?");
        scanf("\n %d \n %d", &idad1, &idad2);
        printf("\n Qual o salario das suas pessoas? ");
        scanf("\n %d \n %d", &salar1, &salar2);

    if(altu1 > altu2){
        printf("\n A primeira pessoa eh mais alta!");
    }
        else if(altu2 > altu1){
            printf("\n A segunda pessoa eh mais alta!");
        }
        else{
            printf("\n As duas sao da mesma altura!");
        }

    if(idad1 > idad2){
        printf("\n A primeira pessoa eh mais velha!");
    }
        else if(idad2 > idad1){
            printf("\n A segunda pessoa eh mais velha!");
        }
        else{
            printf("\n As duas sao da mesma idade!");
        }

    if(salar1 > salar2){
        printf("\n A primeira pessoa ganha mais!");
    }
        else if(salar2 > salar1){
            printf("\n A segunda pessoa ganha mais!");
        }
        else{
            printf("\n As duas ganham a mesma quantia!");
        }
    return 0;
}
 