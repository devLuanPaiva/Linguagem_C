#include <stdio.h>
int main(){
	int a, b, c, d;
	scanf("%d\n %d\n %d\n %d\n", &a, &b, &c, &d);
	if(b > c && d > a && c + d > a + b && c && d > 0 && a %2 == 0){
		printf("Valores aceitos");
	}
	else printf("Valores nao aceitos");
	return 0;
}