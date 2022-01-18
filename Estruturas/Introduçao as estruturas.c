#include <stdio.h>

struct funcionario{
	int idade, horas;
	float salario;
};
int main(){
	struct funcionario f[3];
	printf("Informe os dados do funcionario\n");
	printf("Idade; salario e horas trabalhadas\n");
	int i;
	for(i=0; i<3; i++){
		scanf("%d %f %d", &f[i].idade, &f[i].salario, &f[i].horas);
	}
	int imaior = 0;
	for(i = 1; i < 3; i++){
		if(f[i].salario > f[imaior].salario){
			imaior = i;
		}
	}
	printf("%d\n", imaior + 1);
	return 0;
}