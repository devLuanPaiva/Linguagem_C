# include <stdio.h>
# define N 19

/*Aluno: Luan Alves de Paiva
  Matricula: 2020022483
  Turma: 1
*/
int main (){
	int i;
int numeros [ N ] = {76, 117, 97, 110, 32, 65, 108, 118, 101,
                     115, 32, 100, 101, 32, 80, 97, 105, 118, 97};
/* Na linha anterior, estou declarando um vetor com os numeros da tabela ASCII,
 onde cada um representa uma letra do meu nome. */
char * p ;
// Na linha anterior, estou declarado um ponteiro do tipo char.
p = ( char *) numeros ;
 /*O ponteiro ira conter as informaçoes presentes no vetor numeros.
 Essas informacooes sao basicamente o endereco de cada numero tal que representam um
 caractere */
for (i = 0; i < N*4; ++ i ) {
printf( "%c" , *( p ++) ) ;
}
/*Dentro desse for, o i percorrerá todo o vetor numeros em busca das informaçoes contidas
no mesmo, isso por meio do ponteiro de caracteres. Conforme vai lendo, vai imprimindo as letras
afim de que forme uma palavra.
*/
printf("\n");
return 0;
}