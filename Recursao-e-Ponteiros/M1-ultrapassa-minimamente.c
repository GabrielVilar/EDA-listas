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
    //printf("\n");
    //printf("%d %d %d %d\n", barra, cont, tamanhoAux, capacidadeAux);
    
    for (int i = tamanhoAux - 1; i >= 0; i--){
        printf("%d\n",vetor[vetorAux[i]]);
    }
    

    free(vetor);
    free(vetorAux);
    return 0;
}

//Versão do chatGPT
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
//Outra maneira que tá errada do chatGPT
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