#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
    celula *atual1 = l1->prox;
    celula *atual2 = l2->prox;
    celula *atual_l3 = l3;

    while (atual1 != NULL && atual2 != NULL) {
        if (atual1->dado < atual2->dado) {
            atual_l3->prox = atual1;
            atual1 = atual1->prox;
        } else {
            atual_l3->prox = atual2;
            atual2 = atual2->prox;
        }
        atual_l3 = atual_l3->prox;
    }

    
    while (atual1 != NULL) {
        atual_l3->prox = atual1;
        atual1 = atual1->prox;
        atual_l3 = atual_l3->prox;
    }

    while (atual2 != NULL) {
        atual_l3->prox = atual2;
        atual2 = atual2->prox;
        atual_l3 = atual_l3->prox;
    }
    
    
    atual_l3->prox = NULL;
    
    
    l1->prox = NULL;
    l2->prox = NULL;
}

void imprime(celula *le) {
    celula *atual = le->prox;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}


