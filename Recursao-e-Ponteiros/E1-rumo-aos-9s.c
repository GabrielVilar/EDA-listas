#include <stdio.h>
#include <string.h>
#define MAX_INPUT_SIZE 1001

int soma_digitos(int soma){
    if(soma == 0) return 0;
    return soma % 10 + soma_digitos(soma/10);
}

int grau_nove(int n ){
    if(n == 9) return 1;
    if(n == 0) return 0;
    n = soma_digitos(n);
    return  1 + grau_nove(n);
}

int main(){
    char num_str[MAX_INPUT_SIZE];
    int soma;
    do {
        scanf("%s", num_str);

        soma = 0;
        char* ptr = num_str;
        while (*ptr != '\0') {
            soma += *ptr - '0';
            ptr++;
        }
        
        if(soma != 0) {
            if(soma_digitos(soma) % 9 == 0){
                printf("%s is a multiple of 9 and has 9-degree %d.\n",num_str, grau_nove(soma));
            } else {
                printf("%s is not a multiple of 9.\n", num_str);
            }
        }
    } while(soma != 0);
    return 0;
}
