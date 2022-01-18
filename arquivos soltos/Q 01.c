#include <stdio.h>
#include <math.h>
float diametro (float raio){
    return (2 * raio);
} 
float perimetro(float raio){
  return(2* 3.14 * raio);
}
float area(float raio){
  return(2* 3.14 * (raio * raio));
}

int main() {
    float raio, result; 
        printf("Digite o valor de um raio: ");
        scanf("%f", &raio);
        result = diametro(raio);
        printf("Diametro =  %f ", result);
        result = perimetro(raio);
        printf("\n Perimetro =  %f", result);
        result = area(raio);
        printf("\n Area =  %f", result);
  
    return 0;
}