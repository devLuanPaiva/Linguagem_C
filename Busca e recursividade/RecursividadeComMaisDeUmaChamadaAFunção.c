#include <stdio.h>
int f(int n){
	if(n == 1){
		return 0;
	}
	if(n == 2){
		return 1;
	}
	return f(n - 1) + f(n - 2);
}
int main(){
	int n;
	printf("Informe o valor de n\n");
	scanf("%d", &n);
	int r = f(n);
	printf("%d\n", r);
}	