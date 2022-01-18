#include <stdio.h>
#include <stdlib.h>
#include "Q5_pasta/Q5.h"

int main() {
  Fila* f1 = fila_cria();

  fila_insere(f1,10);
  fila_insere(f1,12);
  fila_insere(f1,14);

  Fila* f2 = fila_cria();
  fila_insere(f2,11);
  fila_insere(f2,13);
  fila_insere(f2,15);

  Fila* copy = fila_cria();

  combina(copy, f1,f2);

  fila_imprime(copy);

  fila_libera(f1);
  fila_libera(f2);
  fila_libera(copy);
  return 0;
}