#include <stdio.h>
#include <string.h>
/* Essas funçoes so sao validas para o CODCAST
pois o mesmo nao le a bilioteca string
int strlen(char []){
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}
int strcmp(char s1[], char s2[]){
    if(strlen(s1) != strlen(s2)) return 1;
    int i;
    for(i=0; i< strlen(s1); i++){
        if(s1[i] != s2[i]) return 1;
    }
    return 0;
}
*/
int main(){
    //! showMemory(start=65520)
    char v[3][3];
    char s[3];
    printf("Informe as strings\n");
    scanf("%s %s %s %s", v[0], v[1], v[2], s);
    int i;
    for(i=0; i<3; i++){
        if(strcmp(v[i], s) == 0){
            printf("%d \n", i);
        }
    }
	return 0;
}