#include <stdio.h>
#include <string.h>
int maiorSubcadeia(char* str, char* sub, int tamStr, int tamSub) {
    if (tamStr < tamSub) {
       
        return 0;
    } else if (strncmp(str, sub, tamSub) == 0) {
        
        char* pos = strstr(str + tamSub, sub); 
        if (pos == NULL) {
          
            return tamSub; 
        } else {
         
            int tamAtual = pos + tamSub - str + maiorSubcadeia(pos + tamSub, sub, tamStr - (pos + tamSub - str), tamSub);
           
            int tamOutra = maiorSubcadeia(pos + tamSub, sub, tamStr - (pos + tamSub - str), tamSub);
            return (tamAtual > tamOutra) ? tamAtual : tamOutra;
        }
    } else {
        return maiorSubcadeia(str + 1, sub, tamStr - 1, tamSub);
    }
}
int main() {
    char str[102], sub[102];
    scanf("%s", str);
    scanf("%s", sub);
    int tamStr = strlen(str), tamSub = strlen(sub);
    int tamanhoMaiorSubcadeia = maiorSubcadeia(str, sub, tamStr, tamSub);
    printf("%d\n", tamanhoMaiorSubcadeia);
}