#include <stdio.h>

int main() {
    int nmr_leituras, capacidade_max, pessoas_saindo, pessoas_entrando;
    int pessoas = 0, excedeu = 0;

    scanf("%d %d", &nmr_leituras, &capacidade_max);
    for (int i = 0; i < nmr_leituras; i++) {
        scanf("%d %d", &pessoas_saindo, &pessoas_entrando);

        pessoas += (pessoas_entrando - pessoas_saindo); 
        
        if (pessoas > capacidade_max) { 
            excedeu = 1;
        }
    }

    if (excedeu) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}