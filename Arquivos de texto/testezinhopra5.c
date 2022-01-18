#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float media;
} estudante;

void menu() {
    printf("== escolha uma opcao ==\n");
    printf("1 - adicionar estudante\n");
    printf("2 - ler todos\n");
    printf("3 - tamanho\n");
    printf("4 - atualizar estudante\n");
    printf("5 - delete\n");
    printf("0 - sair\n");
    printf("=======================\n");
}

void ler(estudante* e) {
    printf("Informe o nome:\n");
    scanf(" %[^\n]s", e->nome);
    printf("Informe a media:\n");
    scanf("%f", &e->media);
}

//CRUD = Create/Read/Update/Delete

void adicionar(estudante e) {
    FILE * f = fopen("./estudantes.bin", "ab");
    fwrite(&e, sizeof(estudante), 1, f);
    fclose(f);
}

void salvarVetor(estudante v[], int n) {
    FILE *f = fopen("./estudantes.bin", "wb");
    fwrite(v, sizeof(estudante), n, f);
    fclose(f);
}

void listar() {
    FILE* f = fopen("./estudantes.bin", "rb");
    estudante e;
    while(fread(&e, sizeof(estudante), 1, f)) {
        printf("%s: %f\n", e.nome, e.media);
    }
    fclose(f);
}

int tamanho() {
    FILE* f = fopen("./estudantes.bin", "rb");
    int i = 0;
    estudante e;
    while (fread(&e, sizeof(estudante), 1, f)) {
        i++;
    }
    fclose(f);
    return i;
}

estudante* lerVetor() {
    int t = tamanho();
    FILE* f = fopen("./estudantes.bin", "rb");
    estudante* v = (estudante*) malloc(t * sizeof(estudante));
    fread(v, sizeof(estudante), t, f);
    fclose(f);
    return v;
}

void atualizar(char nome[], float novanota) {
    int t = tamanho();
    estudante* v = lerVetor();

    FILE* f = fopen("./estudantes.bin", "wb");
    int i;
    for (i = 0; i < t; i++) {
        if (strcmp(v[i].nome, nome) == 0) {
            v[i].media = novanota;
        }
    }
    fwrite(v, sizeof(estudante), t, f);
    fclose(f);
}

void atualizarNovaVersao(char nome[], float novanota) {
    int t = tamanho();
    estudante* v = lerVetor();
    int i;
    for (i = 0; i < t; i++) {
        if (strcmp(v[i].nome, nome) == 0) {
            v[i].media = novanota;
        }
    }
    salvarVetor(v, t);
}

void delete(char nome[]) {
    estudante* v = lerVetor();
    int t = tamanho();

    FILE* f = fopen("./estudantes.bin", "wb");
    int i;
    for (i = 0; i < t; i++) {
        if (strcmp(v[i].nome, nome) != 0) {
            fwrite(&v[i], sizeof(estudante), 1, f);
        }
    }
    fclose(f);
}



int main() {
    menu();
    int op;
    scanf("%d", &op);

    while (op != 0) {
        if (op == 1) {
            estudante e;
            ler(&e);
            adicionar(e);
        }
        if (op == 2) {
            listar();
        }
        if (op == 3) {
            int t = tamanho();
            printf("Quantidade de estudantes: %d\n", t);
        }
        if (op == 4) {
            printf("Informe o nome do estudante a ser atualizado:\n");
            char nome[50];
            float novaMedia;
            scanf(" %[^\n]s", nome);
            printf("Informe a nova media\n");
            scanf("%f", &novaMedia);
            //atualizar(nome, novaMedia);
            atualizarNovaVersao(nome, novaMedia);
        }

        if (op == 5) {
            printf("Informe o nome do estudante a ser deletado\n");
            char nome[50];
            scanf(" %[^\n]s", nome);
            delete(nome);
        }

        menu();
        scanf("%d", &op);
    }

    return 0;
}