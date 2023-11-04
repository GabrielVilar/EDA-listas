#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    celula *novo_elemento = (celula *)malloc(sizeof(celula));
    novo_elemento->dado = x;
    novo_elemento->prox = le->prox;
    le->prox = novo_elemento;
}

void insere_antes(celula *le, int x, int y) {
    celula *atual = le;
    while (atual->prox != NULL) {
        if (atual->prox->dado == y) {
            celula *novo_elemento = (celula *)malloc(sizeof(celula));
            novo_elemento->dado = x;
            novo_elemento->prox = atual->prox;
            atual->prox = novo_elemento;
            return;
        }
        atual = atual->prox;
    }

    
    celula *novo_elemento = (celula *)malloc(sizeof(celula));
    novo_elemento->dado = x;
    novo_elemento->prox = NULL;
    atual->prox = novo_elemento;
}

void imprime(celula *le) {
    celula *atual = le->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}