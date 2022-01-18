#include <stdio.h>
typedef struct{
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
	int cont;
}estudante;
int main(){
	FILE *file = fopen("./danca.txt", "a");
	int n, i;
	fscanf(file, "%d", &n);
	estudante e;
	for(i=0; i<3; i++){
		fscanf(file, "%s %f %f %f", e.nome, &e.nota1, &e.nota2, &e.nota3);
		int cont = 0;
		if(e.nota1 == 10){
			cont++;
		} 
		if(e.nota2 == 10){
			cont++;
		} 
		if(e.nota3 == 10){
			cont++;
		} 
		
	}
	fseek(file, 0, SEEK_CUR);
	fprintf(file, "%s: com %d notas 10", e.nome, e.cont);
	printf("Prorama finalizado\n");
	return 0;
}