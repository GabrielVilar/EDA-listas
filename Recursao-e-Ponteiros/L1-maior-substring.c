#include <stdio.h>
#include <string.h>
int maiorSubcadeia(char* str, char* sub, int tamStr, int tamSub) {
    if (tamStr < tamSub) {
        // Caso base: não é possível encontrar subcadeias que comecem e terminem por sub
        return 0;
    } else if (strncmp(str, sub, tamSub) == 0) {
        // Caso em que a subcadeia começa por sub, procuramos agora o final da subcadeia
        char* pos = strstr(str + tamSub, sub); // Procura próxima ocorrência de sub
        if (pos == NULL) {
            // Caso em que não há mais ocorrências de sub na string
            return tamSub; // A subcadeia atual é a maior encontrada até agora
        } else {
            // Caso em que encontramos uma ocorrência de sub que termina a subcadeia
            int tamAtual = pos + tamSub - str + maiorSubcadeia(pos + tamSub, sub, tamStr - (pos + tamSub - str), tamSub);
            // Verifica se há uma subcadeia maior a partir da próxima ocorrência de sub
            int tamOutra = maiorSubcadeia(pos + tamSub, sub, tamStr - (pos + tamSub - str), tamSub);
            return (tamAtual > tamOutra) ? tamAtual : tamOutra;
        }
    } else {
        // Caso em que não encontramos a subcadeia no início da string, procuramos recursivamente a partir do próximo caractere
        return maiorSubcadeia(str + 1, sub, tamStr - 1, tamSub);
    }
}
int main() {
    char str[102], sub[101];
    scanf("%s", str);
    scanf("%s", sub);
    int tamStr = strlen(str), tamSub = strlen(sub);
    int tamanhoMaiorSubcadeia = maiorSubcadeia(str, sub, tamStr, tamSub);
    printf("%d\n", tamanhoMaiorSubcadeia);
}