#include <stdio.h>

int sum(int array[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += array[i];
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int campo[n][m];
    int sum_linha[n], sum_coluna[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        sum_linha[i] = sum(campo[i], m);
    }

    for (int j = 0; j < m; j++) {
        int coluna[m];
        for (int i = 0; i < n; i++) {
            coluna[i] = campo[i][j];
        }
        sum_coluna[j] = sum(coluna, n);
    }

    int maior_linha = sum_linha[0];
    int maior_coluna = sum_coluna[0];

    for (int i = 1; i < n; i++) {
        if (sum_linha[i] > maior_linha) {
            maior_linha = sum_linha[i];
        }
    }

    for (int j = 1; j < m; j++) {
        if (sum_coluna[j] > maior_coluna) {
            maior_coluna = sum_coluna[j];
        }
    }

    int resultado = 0;

    if (maior_linha > maior_coluna) {
        int linha = 0;
        while (linha < n && sum(campo[linha], m) != maior_linha) {
            linha++;
        }
        resultado = sum(campo[linha], m);
    } else {
        int coluna = 0;
        for (int j = 0; j < m; j++) {
            if (sum_coluna[j] == maior_coluna) {
                coluna = j;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            resultado += campo[i][coluna];
        }
    }

    printf("%d\n", resultado);

    return 0;
}
/*
PDF Informativo:
    https://drive.google.com/file/d/1g5ONlP-APNL5ichoqtnPZeZaBquuEVAi/view
*/