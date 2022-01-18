#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MAX_VAGAS = 9;
int MAX_TURMAS = 3;
struct aluno {
 int mat;
 char nome[81];
 float notas[3];
 float media;
};
typedef struct aluno Aluno;

struct turma {
 char id; 
 int vagas; 
 Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;
Turma* turmas[MAX_TURMAS];
void menu(){
	printf("|========== Digite sua opcao ===========|\n");
	printf("|1 – Criar turma                        |\n");
	printf("|2 - Salvar turmas                      |\n");
	printf("|3 – Carregar turmas                    |\n");
	printf("|4 – Listar turmas                      |\n");
	printf("|5 – Matricular aluno                   |\n");
	printf("|6 – Lancar notas                       |\n");
	printf("|7 – Listar alunos                      |\n");
	printf("|8 – Sair                               |\n");
	printf("|=======================================|\n");
}
/*
void Turma* cria_turma(char id){
	int i;
	turma Turma;
	Turma* turmas[MAX_TURMAS];
	if(Turma.id == NULL){
		printf("Nao tem alunos matriculados nessa turma!\n");
		for(i=0; i<MAX_TURMAS; i++){
			int Aluno* turmas[i].id = (int *) malloc(sizeof(Aluno));
		}
	}
	else{
		Printf("Tem alunos matriculados nessa Turma!\n");
		if (turma.id == id){
			printf("Esse id ja tem alunos matriculados!\n");
		}
		else{
			printf("Ainda nao tem matricula nessa turma, matricule agora!");
			for(i=0; i<MAX_TURMAS; i++){
			int Aluno* turma1.aluno = (int *) malloc(sizeof(Aluno));
		    }
		}
	}
}
void matricula_aluno((Turma*) turma, int mat, char* nome){
	alunos[MAX_VAGAS];
	for(i=0; i<MAX_VAGAS; i++){
	    int mat* alunos[i].id = (int *) malloc(sizeof(Aluno));
	    char nome* alunos[i].id = (char *) malloc(sizeof(Aluno));
	}	
}
void lanca_notas(Turma* turma){
	Turma.Aluno.media = (Turma.Aluno.notas[0] + Turma.Aluno.notas[1] + Turma.Aluno.notas[2])/ 3;
	
}
void imprime_alunos(Turma* turma){
	int i;
	for(i=0; i<TotalMat; i++){
		printf("Nome %d: %s\n", i+1, Turma.Aluno.nome);
		printf("Matricula: %d\n", Turma.Aluno.mat);
		printf("Turma: %c\n", Turma.id);
		printf("Media: %d\n", Turma.Aluno.media);
	}
}
void imprime_turmas(Turma** turmas, int n){
	
}
Turma* procura_turma(Turma** turmas, int n, char id){
	
}
*/
int main(){
	FILE *file = fopen("./Turmas_Salvas.txt", "a");
	menu();
	int op, i;
	Turma* turmas[MAX_TURMAS];
	scanf("%d", &op);
	int TotalMat = 0;
	while(op != 8){
	    switch (op) {
		    case 1:
			    printf("Criando nova turma...\n");
				printf("Digite um id:");
				scanf("%c", Turma.id);
			case 2:
			    printf("Salvando nova turma...\n");
			    fprintf(file, "Turma %c\n", Turma.id);
			    fflush(file);	
			case 3:
			    printf("adsadm");
			case 4:
			    printf("\n Listando turmas...\n");
				printf("Turma %c – %d vagas disponíveis\n", Turma.id, Turma.vagas);
			case 5:
			    printf("Matriculando aluno.../n");
				printf("Digite o id da turma:\n");
				scanf("%c", Turma.id);
				printf("\nDigite a matricula:");
				scanf("%d", &Turma.Aluno.mat);
				printf("\nDigite o nome:");
				scanf("%s", Turma.Aluno.nome);
				printf("\nAluno matriculado com sucesso!n");
				TotalMat++;
			case 6:
			    for(i=0; i<TotalMat; i++){
			        printf("Lancando notas...\n");
		            printf("Digite o id da turma:\n");
			        scanf("%c", Turma.id);
			        printf("Matricula: %d Aluno: %s \n", Turma.Aluno.mat, Turma.Aluno.nome);
			        printf("Digite as notas:");
			        scanf("%f", &Turma.Aluno.notas[i]);
                }
			case 7:
			    for(i=0; i<TotalMat; i++){
					printf("Listando alunos...\n");
					printf("Digite o id da turma:");
					scanf("%c", Turma.id);
					printf("\nMatricula: %d\n", Turma.Aluno.mat);
					printf("Nome: %s\n", Turma.Aluno.nome);
					printf("Media: %f\n", Turma.Aluno.media);
				}
			case 8:
			    printf("Obrigado por usar este programa!");
			default:
			    printf("Opcao invalida!");
				
	    }
	menu();
	scanf("%d", &op);	
	}
	fclose(file);
	return 0;

}
 