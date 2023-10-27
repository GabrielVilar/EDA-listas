#include <stdio.h>
#include <stdlib.h>
int contaString(char str[]);

int main(){ 
    char str[1000];
    scanf("%s", str); 
    printf("%d\n", contaString(str));
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
