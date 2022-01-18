#include <stdio.h>

struct funcionario{
	int idade, horas, salario;
};
int main(){
	struct funcionario f[3];
	printf("Informe os dados do funcionario\n");
	printf("Idade; salario e horas trabalhadas\n");
	int i;
	for(i=0; i<3; i++){
		scanf("%d %d %d", &f[i].idade, &f[i].salario, &f[i].horas);
	}
	
	for(i = 0; i < 3; i++){
		f[i].salario = 2 * f[i].salario;
		printf("O Salario dobrado  fica %d\n", f[i].salario);
	}
	
	return 0;
}
  