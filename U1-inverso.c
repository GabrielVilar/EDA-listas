#include <stdio.h>
int main(){
    char str[1000];
    char inversa[1000];
    int i,n, x = 0;
    scanf("%s",str);
    n = strlen(str);
    for(i = n-1; i>=0;i--){
        inversa[x] = str[i];
        x++;
    }
    inversa[x]='\0';
    printf("%s\n",inversa);
    return 0;
}