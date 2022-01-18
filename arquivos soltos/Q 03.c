#include <stdio.h>
#include <math.h>
float media_ariti(float n1, float n2, float n3, float n4, float n5){
    float ari;
    ari = ((n1 + n2 + n3 + n4 + n5)/ 5);
    return ari;
}

float media_ponderada(float n1, float n2, float n3, float n4, float n5, float p1, float p2, float p3, float p4, float p5){
    float ponde;
    ponde = ((n1 * p1) + (n2 * p2) + (n3 * p3) + (n4 * p4) + (n5 * p5))/(p1 + p2 + p3 + p4 + p5);
    return ponde;
}
int main() {
    float n1, n2, n3, n4, n5, p1, p2, p3, p4, p5, result;
    int nume;
        printf("Digite cinco numeros: ");
        scanf("%f \n %f \n %f \n %f \n %f", &n1, &n2, &n3, &n4, &n5);
        printf("Qual media voce quer utilizar para calcular?/");
        printf("\n(1)ARITIMETICA  (2) PONDERADA"  );
        scanf("%d", &nume);

        if(nume == 1){
            result = media_ariti(n1, n2, n3, n4, n5);
            printf("\n O resultado da media aritimetica eh:  %f", result);
        }
  
        else if(nume == 2){
            printf("\n Digite 5 pesos para continuar: ");
            scanf("%f \n %f \n %f \n %f \n %f", &p1, &p2, &p3, &p4, &p5);
            result = media_ponderada(n1, n2, n3, n4, n5, p1, p2, p3, p4, p5);
            printf("\nO resultado da media ponderada eh: %f", result);
        }
  
        else printf("Opcao invalida!");
	return 0;
}