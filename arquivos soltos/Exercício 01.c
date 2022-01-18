#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, x[10] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
	
	for(i = 0; i < 10; i++){
		printf("%i\n", x[i]); 	
	}
	
	system("pause");
	return(0);
}