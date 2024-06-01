#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void em_ordem(no *raiz) {
    no *atual = raiz;
    while (atual != NULL) {
        if (atual->esq == NULL) {
            printf("%d ", atual->dado);
            atual = atual->dir;
        } else {            
            no *predecessor = atual->esq;
            while (predecessor->dir != NULL && predecessor->dir != atual) {
                predecessor = predecessor->dir;
            }

            if (predecessor->dir == NULL) {
                predecessor->dir = atual;
                atual = atual->esq;
            }            
            else {
                predecessor->dir = NULL;
                printf("%d ", atual->dado);
                atual = atual->dir;
            }
        }
    }
}