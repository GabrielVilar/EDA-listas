/*
#include <stdio.h>
#include <stdlib.h>
int main(){
    
    int *vetor = NULL; // iniciar o ponteiro para um vetor vazio
    int *vetorAux = NULL;// iniciar o ponteiro para um vetor vazio (armazena índice)
    int tamanho = 0; // tamanho atual do vetor
    int tamanhoAux = 0;// Tamanho atual do vetorAux
    int capacidade = 0; // capacidade atual do vetor
    int capacidadeAux = 0;// capacidade atual do vetorAux
    int numero, barra;
    int soma = 0, cont = 0, ultimoNumero = 0, ultimoIndice = -1;
    do
    {
        scanf("%d", &numero);
        // verifica se o vetor precisa ser realocado
        if(tamanho == capacidade){
            capacidade += 10; // aumenta a capacidade do vetor em 10 elementos;
            vetor = (int *) realloc(vetor, capacidade * sizeof(int)); // realoca a memória
        }
        // armazena o número no vetor e incrementa o tamanho
        if (numero != 0){
            vetor[tamanho] = numero;
            tamanho++;
        }

    } while (numero != 0);
    
    scanf("%d", &barra);

    for (int i = 0; i < tamanho; i++){
       
        soma += vetor[i];
        if (soma >= barra){
            cont++;
            soma = 0;
            if(tamanhoAux == capacidadeAux){
                capacidadeAux += 10;
                vetorAux = (int *) realloc(vetorAux, capacidadeAux * sizeof(int));
            }
            vetorAux[tamanhoAux] = i;
            tamanhoAux++;
        }
        
    }
    
    for (int i = tamanhoAux - 1; i >= 0; i--){
        printf("%d\n",vetor[vetorAux[i]]);
    }
    

    free(vetor);
    free(vetorAux);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

void imprimirNumeros(int* vetor, int* indices, int tamanho) {
    if (tamanho == 0) { // caso base: vetor de índices vazio
        return;
    }
    imprimirNumeros(vetor, indices + 1, tamanho - 1); // chama recursivamente com o próximo índice
    printf("%d\n", vetor[indices[0]]); // imprime o número do vetor com base no primeiro índice
}

int main() {
    int *vetor = NULL;
    int *vetorAux = NULL;
    int tamanho = 0;
    int tamanhoAux = 0;
    int capacidade = 0;
    int capacidadeAux = 0;
    int numero, barra;
    int soma = 0, cont = 0, ultimoNumero = 0, ultimoIndice = -1;

    do {
        scanf("%d", &numero);
        if(tamanho == capacidade){
            capacidade += 10;
            vetor = (int *) realloc(vetor, capacidade * sizeof(int));
        }
        if (numero != 0){
            vetor[tamanho] = numero;
            tamanho++;
        }

    } while (numero != 0);
    scanf("%d", &barra);

    for (int i = 0; i < tamanho; i++){
        soma += vetor[i];
        if (soma >= barra){
            cont++;
            soma = 0;
            if(tamanhoAux == capacidadeAux){
                capacidadeAux += 10;
                vetorAux = (int *) realloc(vetorAux, capacidadeAux * sizeof(int));
            }
            vetorAux[tamanhoAux] = i;
            tamanhoAux++;
        }
    }
    
    imprimirNumeros(vetor, vetorAux, tamanhoAux);

    free(vetor);
    free(vetorAux);
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int somaRecursiva(int *vetor, int tamanho, int barra, int *ultimoNumero, int *ultimoIndice) {
    // caso base: vetor vazio
    if (tamanho == 0) {
        return 0;
    }
    // chama recursivamente para o vetor sem o último elemento
    int soma = somaRecursiva(vetor, tamanho - 1, barra, ultimoNumero, ultimoIndice);

    // adiciona o último elemento à soma
    soma += vetor[tamanho - 1];

    // verifica se a soma atual é maior ou igual a barra
    if (soma >= barra) {
        // salva o último número e índice antes de zerar a soma
        *ultimoNumero = vetor[tamanho - 1];
        *ultimoIndice = tamanho - 1;
        soma = 0;
    }

    return soma;
}

int main() {
    int *vetor = NULL;
    int *vetorAux = NULL;
    int tamanho = 0;
    int tamanhoAux = 0;
    int capacidade = 0;
    int capacidadeAux = 0;
    int numero, barra;
    int ultimoNumero = 0, ultimoIndice = -1;

    do {
        scanf("%d", &numero);
        if(tamanho == capacidade){
            capacidade += 10;
            vetor = (int *) realloc(vetor, capacidade * sizeof(int));
        }
        if (numero != 0){
            vetor[tamanho] = numero;
            tamanho++;
        }

    } while (numero != 0);
    scanf("%d", &barra);

    for (int i = 0; i < tamanho; i++) {
        int soma = somaRecursiva(vetor, i + 1, barra, &ultimoNumero, &ultimoIndice);
        if (ultimoIndice != -1) {
       
            if(tamanhoAux == capacidadeAux){
                capacidadeAux += 10;
                vetorAux = (int *) realloc(vetorAux, capacidadeAux * sizeof(int));
            }
            vetorAux[tamanhoAux] = ultimoIndice;
            tamanhoAux++;
        }
        if (soma == 0) {
            break;
        }
    }

    // imprime os elementos em ordem decrescente de índice
    for (int i = tamanhoAux - 1; i >= 0; i--) {
        printf("%d\n", vetor[vetorAux[i]]);
    }

    free(vetor);
    free(vetorAux);
    return 0;
}
*/

// #include <stdio.h>
// #include <stdlib.h>

// void leituraVetorRecursivo(int **vetor, int *tamanho, int *capacidade, int barra, int *soma) {
//     int numero;
//     scanf("%d", &numero);

//     if (numero == 0) {
//         return;
//     }

//     if (*tamanho == *capacidade) {
//         *capacidade += 10;
//         *vetor = (int *)realloc(*vetor, (*capacidade) * sizeof(int));
//     }

//     (*vetor)[(*tamanho)++] = numero;
//     *soma += numero;

//     if (*soma >= barra) {
//         printf("%d\n", (*vetor)[(*tamanho) - 1]);
//         *soma = 0;
//     }

//     leituraVetorRecursivo(vetor, tamanho, capacidade, barra, soma);
// }

// int main() {
//     int *vetor = NULL;
//     int tamanho = 0;
//     int capacidade = 0;
//     int barra;
//     scanf("%d", &barra);

//     leituraVetorRecursivo(&vetor, &tamanho, &capacidade, barra, &(int){0});

//     free(vetor);
//     return 0;
// }

/*
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
// #include <stdio.h>
// #include <stdlib.h>

// // Estrutura de pilha
// typedef struct {
//     int *data;
//     int top;
//     int capacity;
// } Stack;

// // Função para inicializar a pilha
// void initStack(Stack *stack, int capacity) {
//     stack->data = (int *)malloc(capacity * sizeof(int));
//     stack->top = -1;
//     stack->capacity = capacity;
// }

// // Função para empilhar um valor na pilha
// void push(Stack *stack, int value) {
//     if (stack->top == stack->capacity - 1) {
//         stack->capacity += 10;
//         stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
//     }
//     stack->data[++stack->top] = value;
// }

// // Função para desempilhar um valor da pilha
// int pop(Stack *stack) {
//     if (stack->top == -1) {
//         return -1; // Pilha vazia
//     }
//     return stack->data[stack->top--];
// }

// // Função para imprimir os valores da pilha
// void printStack(Stack *stack) {
//     while (stack->top >= 0) {
//         printf("%d\n", stack->data[stack->top--]);
//     }
// }

// int main() {
//     int *vetor = NULL;
//     int tamanho = 0;
//     int capacidade = 0;
//     int barra;

//     // Lê números e armazena no vetor
//     int numero;
//     do {
//         scanf("%d", &numero);
//         if (numero != 0) {
//             if (tamanho == capacidade) {
//                 capacidade += 10;
//                 vetor = (int *)realloc(vetor, capacidade * sizeof(int));
//             }
//             vetor[tamanho++] = numero;
//         }
//     } while (numero != 0);

//     scanf("%d", &barra);

//     Stack resultStack;
//     initStack(&resultStack, 10); // Inicializa a pilha

//     int soma = 0;
//     int cont = 0;
//     for (int i = 0; i < tamanho; i++) {
//         soma += vetor[i];
//         if (soma >= barra) {
//             cont++;
//             soma = 0;
//             push(&resultStack, vetor[i]);
//         }
//     }

//     // Imprime os resultados usando a pilha
//     printStack(&resultStack);

//     free(vetor);
//     free(resultStack.data);

//     return 0;
// }

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


