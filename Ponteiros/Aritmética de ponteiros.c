#include <stdio.h>

int main() {
    //! showMemory(start=65520)
	int n; 
	int *pn;
	pn = &n;
	printf("Informe a quantidade de valores\n");
	scanf("%d", pn);
	int v[n];
	int i;
	    for (i = 0; i < n; i++){
		    scanf("%d", &v[i]);
	    }
	    int menor = v[0];
	    for(i = 1; i<n; i++){
		    if(v[i] < menor){
			    menor = v[i];
		    }
	    }
	printf("O menor numero é o %d\n", menor);
	
    return 0;
}
  