#include <stdio.h>
#include <string.h>
    //alunos de uma escola

int alunos;
typedef struct {
	float nota1;
	float ultimaChance;
}recuperacao;
typedef struct {
    char nome[100];
    int matricula;
    int serie;
}identificacao;
typedef struct {
      float bimestre1;
      float bimestre2;
      float bimestre3;
      float bimestre4;
      float media;
       identificacao ide;
       recuperacao re;
}notas;
void  decisao (notas *pno);
int main(){
    FILE *file = fopen("./estudantes.txt", "a");
    printf("informe a quantidade de alunos\n");
    scanf("%d", &alunos);
	notas no[alunos];
	notas *pno;
	pno = no;
    printf("nome, matricula e serie\n");
    int i;
    for(i = 0; i < alunos ; i ++){
        scanf("%s %d %d", (pno+i)->ide.nome, &(pno+i)->ide.matricula, &(pno+i)->ide.serie);
        fprintf(file, "%s %d %d \n", (pno+i)->ide.nome, (pno+i)->ide.matricula, (pno+i)->ide.serie);
    }
	
	printf("digite as notas de cada bimestre dos alunos\n");
	for(i = 0; i < alunos ; i ++){
         scanf("%f %f %f %f", &(pno+i)->bimestre1, &(pno+i)->bimestre2, &(pno+i)->bimestre3, &(pno+i)->bimestre4);
	     fprintf(file, "%f %f %f %f\n ", (pno+i)->bimestre1, (pno+i)->bimestre2, (pno+i)->bimestre3, (pno+i)->bimestre4);
    }
    fclose(file);
	decisao(pno);
    return 0;
    
}
void  decisao (notas *pno){
	FILE *file = fopen("./estudantes.txt", "r");
	int i;
	char AlunoAprovado[100];
	char AlunoRecuperacao[100];
	for(i=0; i< alunos; i++){
		fscanf(file, "%f %f %f %f", &(pno+i)->bimestre1, &(pno+i)->bimestre2, &(pno+i)->bimestre3, &(pno+i)->bimestre4);
	    (pno+i)->media= ((pno+i)->bimestre1 + (pno+i)->bimestre2 + (pno+i)->bimestre3 + (pno+i)->bimestre4)/4;
		printf("A media do aluno %s eh %.2fn",(pno+i)->ide.nome, (pno+i)->media);
	}
	fclose(file);
	for(i=0; i< alunos; i++){
		if((pno+i)->media >= 7){
			strcpy(AlunoAprovado, (pno+i)->ide.nome);
			printf("O Aluno %s passou!\n", AlunoAprovado);
		}
		else{
			strcpy(AlunoRecuperacao, (pno+i)->ide.nome);
			printf("O aluno %s foi para a recuperacao!\n", AlunoRecuperacao);
			printf("Digite a nota da recuperacao \n");
			scanf("%f", &(pno+i)->re.nota1);
			if((pno+i)->re.nota1 > 6){
				printf("Aprovado!\n");
			}
			else printf("Reprovado!\n");
		}
	}
	
}