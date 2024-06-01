#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

void pre_ordem(no *raiz) {
    no *current = raiz;
    while (current != NULL) {
        if (current->esq == NULL) {
            printf("%d ", current->dado);
            current = current->dir;
        } else {
           
            no *predecessor = current->esq;
            while (predecessor->dir != NULL && predecessor->dir != current) {
                predecessor = predecessor->dir;
            }

            if (predecessor->dir == NULL) {
             
                predecessor->dir = current;
                printf("%d ", current->dado); 
                current = current->esq;
            } else {
                predecessor->dir = NULL;
                current = current->dir;
            }
        }
    }
}