#include <stdio.h>

int main() {
    int nmrn_rodadas, i, a, b, pontos_a = 0, pontos_b = 0, vencedor;
    for (i = 1;; i++) {
        scanf("%d", &nmrn_rodadas);
        if (nmrn_rodadas == 0) break;
        pontos_a = 0;
        pontos_b = 0;
        for (int j = 0; j < nmrn_rodadas; j++) {
            scanf("%d %d", &a, &b);
            pontos_a += a;
            pontos_b += b;
        }
        vencedor = (pontos_a > pontos_b) ? 0 : 1;
        printf("Teste %d\n", i);
        if (vencedor == 0) {
            printf("Aldo\n\n");
        } else {
            printf("Beto\n\n");
        }
    }
    return 0;
}
/*
PDF Informativo:
    https://drive.google.com/file/d/1YqBoV339zo6pZX989tl6yLbbRyN8ZDe-/view
*/