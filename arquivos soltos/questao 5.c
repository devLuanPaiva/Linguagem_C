#include <stdio.h>

int main() {
  int numero1, numero2,  inverso;
  printf("Digite um numero:");
  scanf("%d", &numero1);
  numero2 = numero1;
  inverso = 0;
  while(numero2 != 0){
    inverso = inverso * 10 + numero2 % 10;
    numero2 = numero2/10;
  }
  if(inverso == numero1){
    printf("\n %d Eh um numero eh polindrome\n", numero1);
  }
  else{
    printf("\n %d nao e um polindrome", numero1);
  }
    return 0;

}