#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

void pos_ordem(no *raiz) {
    no *temp = (no *)malloc(sizeof(no));
    temp->esq = raiz;
    no *atual, *predecessor;

    atual = temp;
    while (atual != NULL) {
        if (atual->esq == NULL) {
            atual = atual->dir;
        } else {
            predecessor = atual->esq;
            while (predecessor->dir != NULL && predecessor->dir != atual) {
                predecessor = predecessor->dir;
            }
            
            if (predecessor->dir == NULL) {
                predecessor->dir = atual;
                atual = atual->esq;
            } else {
                predecessor->dir = NULL;
                no *temp1 = atual->esq;
                no *temp2 = temp1->dir;
                temp1->dir = NULL;

                while (temp2 != NULL) {
                    no *next = temp2->dir;
                    temp2->dir = temp1;
                    temp1 = temp2;
                    temp2 = next;
                }

                while (temp1 != atual->esq) {
                    printf("%d ", temp1->dado);
                    no *next = temp1->dir;
                    temp1->dir = temp2;
                    temp2 = temp1;
                    temp1 = next;
                }
                printf("%d ", atual->esq->dado);
                
                atual = atual->dir;
            }
        }
    }
    free(temp);
}