#include <stdio.h>
int main(){
    int n[1000], i, t, j;
	
    scanf ("%d", &t);
    for(i=0,j=0; i<1000; i++){
        printf("N[%d] = %d\n",i,j);
        j++;
        if(j==t){
            j=0;
		}	
    }
    return 0;
}