/*
//50p
#include <stdio.h>
#include <stdlib.h>

// Função recursiva para ler números e armazenar em um vetor
int lerNumeros(int **vetor, int *tamanho, int *capacidade) {
    int numero;
    scanf("%d", &numero);

    if (numero == 0) {
        return 0; // Condição de parada
    }

    if (*tamanho == *capacidade) {
        *capacidade += 10;
        *vetor = (int *)realloc(*vetor, *capacidade * sizeof(int));
    }

    if (numero != 0) {
        (*vetor)[(*tamanho)++] = numero;
    }

    return lerNumeros(vetor, tamanho, capacidade);
}

// Função recursiva para calcular e imprimir os valores
void calcularEImprimir(int *vetor, int *vetorAux, int tamanho, int *tamanhoAux, int capacidadeAux, int barra, int soma, int cont, int i) {
    if (i == tamanho) {
        return; // Condição de parada
    }

    soma += vetor[i];

    if (soma >= barra) {
        cont++;
        soma = 0;

        if (*tamanhoAux == capacidadeAux) {
            capacidadeAux += 10;
            vetorAux = (int *)realloc(vetorAux, capacidadeAux * sizeof(int));
        }

        vetorAux[(*tamanhoAux)++] = i;
    }

    calcularEImprimir(vetor, vetorAux, tamanho, tamanhoAux, capacidadeAux, barra, soma, cont, i + 1);

    if (i == tamanho - 1) {
        for (int j = (*tamanhoAux) - 1; j >= 0; j--) {
            printf("%d\n", vetor[vetorAux[j]]);
        }
    }
}

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int capacidade = 0;
    int barra;

    lerNumeros(&vetor, &tamanho, &capacidade);

    scanf("%d", &barra);

    int *vetorAux = NULL;
    int tamanhoAux = 0;
    int capacidadeAux = 0;
    int soma = 0;
    int cont = 0;

    calcularEImprimir(vetor, vetorAux, tamanho, &tamanhoAux, capacidadeAux, barra, soma, cont, 0);

    free(vetor);
    free(vetorAux);

    return 0;
}
*/

/*
// 50p
#include <stdio.h>
#include <stdlib.h>

// Estrutura de pilha
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack, int capacity) {
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

// Função para empilhar um valor na pilha
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity += 10;
        stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = value;
}

// Função para desempilhar um valor da pilha
int pop(Stack *stack) {
    if (stack->top == -1) {
        return -1; // Pilha vazia
    }
    return stack->data[stack->top--];
}

// Função para imprimir os valores da pilha
void printStack(Stack *stack) {
    while (stack->top >= 0) {
        printf("%d\n", stack->data[stack->top--]);
    }
}

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int capacidade = 0;
    int barra;

    // Lê números e armazena no vetor
    int numero;
    do {
        scanf("%d", &numero);
        if (numero != 0) {
            if (tamanho == capacidade) {
                capacidade += 10;
                vetor = (int *)realloc(vetor, capacidade * sizeof(int));
            }
            vetor[tamanho++] = numero;
        }
    } while (numero != 0);

    scanf("%d", &barra);

    Stack resultStack;
    initStack(&resultStack, 10); // Inicializa a pilha

    int soma = 0;
    int cont = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
        if (soma >= barra) {
            cont++;
            soma = 0;
            push(&resultStack, vetor[i]);
        }
    }

    // Imprime os resultados usando a pilha
    printStack(&resultStack);

    free(vetor);
    free(resultStack.data);

    return 0;
}
*/

/*
//50p
#include <stdio.h>
#include <stdlib.h>

// Estrutura de pilha
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack, int capacity) {
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
}

// Função para empilhar um valor na pilha
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity += 10;
        stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = value;
}

// Função para desempilhar um valor da pilha
int pop(Stack *stack) {
    if (stack->top == -1) {
        return -1; // Pilha vazia
    }
    return stack->data[stack->top--];
}

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int capacidade = 0;
    int barra;

    // Lê números e armazena no vetor
    int numero;
    do {
        scanf("%d", &numero);
        if (numero != 0) {
            if (tamanho == capacidade) {
                capacidade += 10;
                vetor = (int *)realloc(vetor, capacidade * sizeof(int));
            }
            vetor[tamanho++] = numero;
        }
    } while (numero != 0);

    scanf("%d", &barra);

    Stack resultStack;
    initStack(&resultStack, 10); // Inicializa a pilha

    int soma = 0;
    int cont = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
        if (soma >= barra) {
            cont++;
            soma = 0;
            push(&resultStack, vetor[i]);
        }
    }

    // Imprime os resultados usando a pilha (ao contrário)
    while (resultStack.top >= 0) {
        printf("%d\n", pop(&resultStack));
    }

    free(vetor);
    free(resultStack.data);

    return 0;
}
*/
