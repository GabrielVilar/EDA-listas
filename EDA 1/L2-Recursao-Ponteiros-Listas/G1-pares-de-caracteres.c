#include <stdio.h>
#include <string.h>

int conta_pares_rec(char str[], int pos, int cont) {
    if (pos >= strlen(str) - 1) { // caso base: chegou ao final da string
        return cont;
    }

    if (str[pos] == str[pos + 2]) { // encontrou um par
        cont++;
    }

    return conta_pares_rec(str, pos + 1, cont); // chamada recursiva para o restante da string
}

int main() {
    char str[201];
    scanf("%200s", str); // lê a string com no máximo 200 caracteres

    int pares = conta_pares_rec(str,0,0);

    printf("%d\n", pares); // imprime a quantidade de pares na string

    return 0;
}
