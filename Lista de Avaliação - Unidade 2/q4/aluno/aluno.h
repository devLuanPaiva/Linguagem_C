typedef struct aluno Aluno;

Aluno* aluno_cria(int n);

void ler(int n, Aluno *v);

void aluno_imprime(int n, Aluno* a);

void aluno_ordena(int n, Aluno* a);

void aluno_salva(int n, Aluno *v);

void aluno_libera(Aluno* a);
/*Vemos que o aluno.h e um local utilizado para declarar as funcoes que
serao chamadas no aluno.c e la, cada funcao tera suas tarefas definidas */