#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int mapa1[n][n], mapa2[n][n], resultado[n][n];
    
    // lê os dois mapas
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mapa1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mapa2[i][j]);
        }
    }
    
    // calcula a quantidade total de chuva acumulada nos dois períodos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = mapa1[i][j] + mapa2[i][j];
        }
    }
    
    // exibe o resultado
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
