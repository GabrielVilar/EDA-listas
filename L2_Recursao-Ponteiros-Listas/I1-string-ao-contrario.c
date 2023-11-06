#include <stdio.h>
#include <string.h>

void inverte_string(char *str, int tamanho) {
    if(tamanho <= 0) { // caso base
        return;
    } else { // caso recursivo
        printf("%c", str[tamanho-1]);
        inverte_string(str, tamanho-1);
    }
}

int main() {
    char str[501];
    scanf("%s", str);
    int n = strlen(str);
    inverte_string(str, n);
    return 0;
}
