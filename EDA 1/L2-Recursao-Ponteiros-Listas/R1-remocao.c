#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0;  // Não é possível remover o elemento seguinte
    }

    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
    return 1;  // Remoção bem-sucedida
}

void remove_elemento(celula *le, int x) {
    celula *atual = le;

    while (atual->prox != NULL) {
        if (atual->prox->dado == x) {
            celula *temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
            return;  // Remoção da primeira ocorrência bem-sucedida
        }
        atual = atual->prox;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *atual = le;

    while (atual->prox != NULL) {
        if (atual->prox->dado == x) {
            celula *temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

void imprime(celula *le) {
    celula *atual = le->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

