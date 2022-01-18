typedef struct Funcionario funcionario;
typedef struct no No ;
typedef struct lista Lista;
/*
NOME:Luan Alves de Paiva
MATRICULA: 2020022483
*/

void ler(funcionario *pe);
void incerir_inicio(Lista *plista, funcionario dado);
Lista cria_lista(int n);
void deletar_valor(Lista *plista, int mat);
void deletar_lista(Lista *plista);
No* pesquisar(Lista lista, int mat);
void impprimir_lista(Lista lista);
void mostrar(Lista lista, char s1[]);
void folha_pagamento(Lista lista, char s1[]);
void menu();
void main_empresa();

/*Aqui nao tem muito segredo, e so a parte de definicoes de funcoes que serao 
chamadas terao suas tarefas definidas no arquivo.c*/