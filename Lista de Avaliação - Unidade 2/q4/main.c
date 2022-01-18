#include <stdio.h>
#include "aluno/aluno.h"

/*
NOME:Luan Alves de Paiva
TURMA: 1
MATRICULA:2020022483
*/
/*De antemao, quero deixar claro que foi preciso modificar as funcoes que
voce deixou disponivel la no Classroom para fazer essa questao. Pois, eu nao 
estava conseguindo dominar o conteudo ponteiros de ponteiros e isso estava 
dificultando bastante. Entao, eu decidi encontrar a melhor maneira para resolver
a questao. */

int main(){
    int n = 5;
    Aluno *v = aluno_cria(n);
    ler(n, v);
    aluno_imprime(n, v);
    aluno_ordena(n, v);
    aluno_salva(n, v);
    aluno_libera(v);
    return 0;
    
    /*No main, vemos que cada linha de codigo esta sendo 
	responsavel por chamar uma funcao*/
}
