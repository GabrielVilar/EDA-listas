#include <stdio.h>
#include <string.h>

void move_x(char *str, int len, int i, int j) {
    if (i >= len) {// Caso base: a string chegou ao fim  
        str[j] = '\0';// Finaliza a nova string com o caractere nulo
        return;
    }
    
    if (str[i] == 'x') {// Caso o caractere atual seja 'x', move-o para o final da string
        move_x(str, len, i+1, j);
        str[j+len-i-1] = 'x'; 
        /*
        A variável j é usada para rastrear a posição na nova string onde 
        o próximo caractere deve ser adicionado.A variável len é usada para 
        rastrear o número total de caracteres na nova string, e 
        a variável i é usada para rastrear a posição atual na string original.
        */
        
    } else {
        str[j] = str[i];
        move_x(str, len, i+1, j+1);
    }
}

int main() {
    char str[101];
    scanf("%s", str);
    
    int len = strlen(str);
    move_x(str, len, 0, 0);
    
    printf("%s\n", str);
    
    return 0;
}
