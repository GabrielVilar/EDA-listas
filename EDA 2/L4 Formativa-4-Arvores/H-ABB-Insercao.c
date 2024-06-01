// #include <stdio.h>
// #include <stdlib.h>

// typedef struct no {
//     int chave;
//     struct no *esq, *dir;
// } no;

// no* inserir(no *raiz, int x) {

//     if (raiz == NULL) {
//         no *novo = (no*)malloc(sizeof(no));
//         novo->chave = x;
//         novo->esq = novo->dir = NULL;
//         return novo;
//     }
   
//     if (x < raiz->chave) {
//         raiz->esq = inserir(raiz->esq, x);
//     }
    
//     else if (x > raiz->chave) {
//         raiz->dir = inserir(raiz->dir, x);
//     }
    
//     return raiz;
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no* inserir(no *raiz, int x) {
    // Se a árvore estiver vazia ou se chegamos a um nó folha, criamos um novo nó
    if (raiz == NULL) {
        no *novo = (no*)malloc(sizeof(no));
        novo->chave = x;
        novo->esq = novo->dir = NULL;
        return novo;
    }

    // Se x for menor que a chave do nó atual, inserimos na subárvore esquerda
    if (x < raiz->chave) {
        raiz->esq = inserir(raiz->esq, x);
    }
    // Se x for maior que a chave do nó atual, inserimos na subárvore direita
    else if (x > raiz->chave) {
        raiz->dir = inserir(raiz->dir, x);
    }
    // Se x for igual à chave do nó atual, não inserimos (chaves repetidas não são permitidas)
    // A árvore permanece inalterada
    return raiz;
}

int main() {
    // Exemplo de uso da função de inserção
    no *raiz = NULL;
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    // Exemplo de como imprimir os valores para verificar se foram inseridos corretamente
    printf("Valores inseridos: ");
    imprimirEmOrdem(raiz); // Supondo que haja uma função de impressão em ordem implementada
    printf("\n");

    return 0;
}
