#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* remover(no *raiz, int x) {
    
    if (raiz == NULL) {
        return raiz;
    }

    if (x < raiz->chave) {
        raiz->esq = remover(raiz->esq, x);
    }
   
    else if (x > raiz->chave) {
        raiz->dir = remover(raiz->dir, x);
    }
    
    else {
        if (raiz->esq == NULL) {
            no *temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            no *temp = raiz->esq;
            free(raiz);
            return temp;
        }

        no *antecessor = raiz->esq;
        while (antecessor->dir != NULL) {
            antecessor = antecessor->dir;
        }

        raiz->chave = antecessor->chave;

        raiz->esq = remover(raiz->esq, antecessor->chave);
    }
    return raiz;
}