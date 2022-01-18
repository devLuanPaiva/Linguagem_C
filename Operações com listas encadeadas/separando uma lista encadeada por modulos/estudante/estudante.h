#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estudante estudante;
typedef struct no No ;
typedef struct lista Lista;

void menu();
void ler(estudante *pe);
void incerir_inicio(Lista *plista, estudante  dado);
void inserir_fim(Lista *plista, estudante dado); 
No* inserir_apos(Lista *plista, estudante dado, int mat);
No* inserir_antes(Lista *plista, estudante dado, int mat);
void deletar_inicio(Lista *plista);
void deletar_fim(Lista *plista);
void deletar_valor(Lista *plista, int mat);
void deletat_apos(Lista *plista, int mat);
void deletar_antes(Lista *plista, int mat);
void deletar_lista(Lista *plista);
void mostrar(Lista lista);
No* pesquisar(Lista lista, int mat);
void alterar(Lista *plista, int mat, char nome[]);
int tamanho(Lista lista);
Lista cria_lista(int n);
void ordenar(Lista *plista);
Lista ler_arquivo();
void salvar_arquivo(Lista lista);

void main_estudante();