#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int data;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
    
    celula *new_node = (celula *)malloc(sizeof(celula));

    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = x;
    new_node->prox = le->prox;   
    le->prox = new_node;
}

void insere_antes(celula *le, int x, int y) {
    
    celula *current = le->prox;
    celula *previous = le;
   
    while (current != NULL && current->data != y) {
        previous = current;
        current = current->prox;
    }
    
    celula *new_node = (celula *)malloc(sizeof(celula));

    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = x;
    new_node->prox = current;
   
    previous->prox = new_node;
}