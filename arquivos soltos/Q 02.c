#include <stdio.h>
#include <math.h>
float media_notas(float n1, float n2, float n3){
    float calculo;
    calculo = (n1 + n2 + n3)/3;
    return calculo;
}

int main(){
    float n1, n2, n3, media, result, i ;
    int alunos;
        printf("Quantos alunos tem na sala? \n");
        scanf("%d", &alunos);
        for(i=1; i<=alunos; i++){
            printf("Digite a primeira nota: ");
            scanf("%f", &n1);
            printf("Digite a segunda nota: ");
            scanf("%f", &n2);
            printf("Digite a terceira nota: ");
            scanf("%f", &n3);
            result = media_notas(n1, n2, n3);
            if(result >= 7){
                printf("Voce foi aprovado, sua media foi: %f\n", result);
            }
            else if(result < 3.5){
               printf("Voce foi reprovado, sua media foi: %f\n", result);
            }
            else  printf("Voce foi para a recuperacao, sua media foi: %f\n", result);
        }

    return 0;
}  
  