#include <stdio.h>
typedef struct{
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
}estudante;
int main(){
	estudante e1;
	estudante e2;
	estudante e3;
	estudante v[3] = {e1, e2, e3};
	int i;
	FILE *file = fopen("./media.txt", "r");
	printf("Informe os dados dos estudantes\n");
	for(i=0; i<3; i++){
		fscanf(file, "%s %f %f %f", v[i].nome, &v[i].nota1, &v[i].nota2, &v[i].nota3);		
	}
	for(i=0; i<3; i++){
		float media = (v[i].nota1 + v[i].nota2 + v[i].nota3)/3;
		if(media >= 7.0){
			printf("\n O aluno %s passou e sua nota foi %.2f\n", v[i].nome, media);
		} 
	}
	fclose(file);
	return 0;
}