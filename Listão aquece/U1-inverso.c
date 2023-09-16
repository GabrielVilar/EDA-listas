#include <stdio.h>
//#include <string.h>
//Poderia usar o strlen ao invés da função contaString
#define MAX 1000
int contaString(char str[]);
int main(){
    char str[MAX];
    char inversa[MAX];
    int i,n, x = 0;
    scanf("%s",str);
    n = contaString(str);
    for(i = n-1; i>=0;i--){
        inversa[x] = str[i];
        x++;
    }
    inversa[x]='\0';
    printf("%s\n",inversa);
    return 0;
}
int contaString(char str[]){
    int tamanho = 0;
    while (str[tamanho] != '\0')
    {
        tamanho++;
    }
    return tamanho;
}