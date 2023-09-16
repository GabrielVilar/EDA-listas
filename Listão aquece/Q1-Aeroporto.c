#include <stdio.h>

#define MAX_AEROPORTOS 10000

int main() {
    int a, v;
    int voos[MAX_AEROPORTOS+1][2] = {0};
    int trafego[MAX_AEROPORTOS+1] = {0};
    int max_trafego = 0;
    
    int teste = 1;
    while (scanf("%d %d", &a, &v) == 2 && (a != 0 || v != 0)) {
        // zera as variáveis para o novo teste
        for (int i = 1; i <= a; i++) {
            trafego[i] = 0;
        }
        max_trafego = 0;
        
        // lê os voos e calcula o tráfego de cada aeroporto
        for (int i = 0; i < v; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            voos[i][0] = x;
            voos[i][1] = y;
            trafego[x]++;
            trafego[y]++;
        }
        
        // encontra o aeroporto com maior tráfego
        for (int i = 1; i <= a; i++) {
            if (trafego[i] > max_trafego) {
                max_trafego = trafego[i];
            }
        }
        
        // exibe o resultado
        printf("Teste %d\n", teste);
        for (int i = 1; i <= a; i++) {
            if (trafego[i] == max_trafego) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
        
        teste++;
    }
    
    return 0;
}
