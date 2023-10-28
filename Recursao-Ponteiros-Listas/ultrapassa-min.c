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
