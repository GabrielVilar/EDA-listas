#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p == NULL || p->prox == NULL) {
        return 0; 
    }
    celula *temp = p->prox;
    p->prox = temp->prox;
    free(temp);
    return 1; 
}

void remove_elemento(celula *le, int x) {
    celula *current = le;
    while (current->prox != NULL) {
        if (current->prox->dado == x) {
            celula *temp = current->prox;
            current->prox = temp->prox;
            free(temp);
            return;
        }
        current = current->prox;
    }
}

void remove_todos_elementos(celula *le, int x) {
    celula *current = le;
    while (current->prox != NULL) {
        if (current->prox->dado == x) {
            celula *temp = current->prox;
            current->prox = temp->prox;
            free(temp);
        } else {
            current = current->prox;
        }
    }
}