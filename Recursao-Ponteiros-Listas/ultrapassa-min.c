// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char const *argv[])
// {
//     int *vetor; 
//     int numero, barra, tamanho = 0, capacidade = 0;
//     vetor = (int *)malloc(tamanho * sizeof(int));
//     int *vetorAux;
//     int tamanhoAux = 0, capacidadeAux = 0;
//     vetorAux = (int *)malloc(tamanhoAux * sizeof(int));
//     int soma = 0, cont = 0, ultimoNumero = 0, ultimoIndice = -1;
//     do
//     {
//         scanf("%d", &numero);
       
//         if(tamanho == capacidade){
//             capacidade += 1; 
//             vetor = (int *) realloc(vetor, capacidade * sizeof(int)); 
//         }
        
//         if (numero != 0){
//             vetor[tamanho] = numero;
//             tamanho++;
//         }

//     } while (numero != 0);

//     scanf("%d", &barra);

//     for (int i = 0; i < tamanho; i++){
       
//         soma += vetor[i];
//         if (soma >= barra){
//             cont++;
//             soma = 0;
//             if(tamanhoAux == capacidadeAux){
//                 capacidadeAux += 1;
//                 vetorAux = (int *) realloc(vetorAux, capacidadeAux * sizeof(int));
//             }
//             vetorAux[tamanhoAux] = i;
//             tamanhoAux++;
//         }
//     }
    
//     for (int i = tamanhoAux - 1; i >= 0; i--){
//         printf("%d\n",vetor[vetorAux[i]]);
//     }
   
//     free(vetor); 
//     free(vetorAux); 
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // Definição da estrutura de um nó da lista encadeada
// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// int main(int argc, char const *argv[])
// {
//     Node* head = NULL;
//     Node* tail = NULL;
//     int numero, barra;
//     int soma = 0, cont = 0;

//     do {
//         scanf("%d", &numero);

//         if (numero != 0) {
//             // Cria um novo nó
//             Node* newNode = (Node*)malloc(sizeof(Node));
//             newNode->data = numero;
//             newNode->next = NULL;

//             if (head == NULL) {
//                 head = newNode;
//                 tail = newNode;
//             } else {
//                 tail->next = newNode;
//                 tail = newNode;
//             }

//             soma += numero;

//             if (soma >= barra) {
//                 cont++;
//                 soma = 0;
//             }
//         }
//     } while (numero != 0);

//     scanf("%d", &barra);

//     // Percorre a lista e imprime os números que atendem ao critério
//     Node* current = head;
//     while (current != NULL) {
//         soma += current->data;
//         if (soma >= barra) {
//             printf("%d\n", current->data);
//             soma = 0;
//         }
//         current = current->next;
//     }

//     // Libera a memória alocada para os nós da lista
//     current = head;
//     while (current != NULL) {
//         Node* temp = current;
//         current = current->next;
//         free(temp);
//     }

//     return 0;
// }

//Usando pilha
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para empilhar um valor na pilha
void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Função para desempilhar um valor da pilha
int pop(Node** top) {
    if (*top == NULL) {
        return -1; // Valor inválido para indicar pilha vazia
    }
    Node* temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Node* tail = NULL;
    int numero, barra;

    do {
        scanf("%d", &numero);

        if (numero != 0) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = numero;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    } while (numero != 0);

    scanf("%d", &barra);

    Node* current = head;
    int soma = 0;
    Node* resultStack = NULL;

    while (current != NULL) {
        soma += current->data;
        if (soma >= barra) {
            push(&resultStack, current->data);
            soma = 0;
        }
        current = current->next;
    }

    // Imprime os resultados na ordem inversa
    int result;
    while ((result = pop(&resultStack)) != -1) {
        printf("%d\n", result);
    }

    // Libera a memória alocada para os nós da lista
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}