#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca(celula *le, int x) {
    celula *new;
    for (new = le->prox; new != NULL; new = new->prox) {
        if (new->dado == x) {
            return new; 
        }
    }
    return NULL; 
}

celula *busca_rec(celula *le, int x) {
    if (le == NULL) {
        return NULL;
    }
    if (le->dado == x) {
        return le; 
    } else {
        return busca_rec(le->prox, x);
    }
}