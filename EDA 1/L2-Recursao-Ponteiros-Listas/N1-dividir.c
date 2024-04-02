#include <stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void divide_lista(celula *l, celula *l1, celula *l2){
    celula *atual = l->prox;
    celula *atual_l1 = l1;
    celula *atual_l2 = l2;

    while (atual != NULL) {
        if (atual->dado % 2 == 0) {
            atual_l2->prox = atual;
            atual_l2 = atual_l2->prox;
        } else {
            atual_l1->prox = atual;
            atual_l1 = atual_l1->prox;
        }
        atual = atual->prox;
    }
    
    atual_l1->prox = NULL;
    atual_l2->prox = NULL;

    l->prox = NULL;
}