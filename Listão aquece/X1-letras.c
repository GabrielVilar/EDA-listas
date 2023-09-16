#include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     char frase[1000];
//     char letra;
//     int qtd_letra = 0, qtd_palavras_sem_letra = 0;
//     float porcentagem, qtd_palavra_com_letra = 0.0, total_de_palavras;

//     scanf("%c\n%[^\n]s", &letra, frase);

//     for(int i = 0; frase[i] != '\0'; i++){
//         for(i=i;(frase[i] != ' '); i++){
//             if(frase[i] == letra){
//                 qtd_letra++;
//             }
//         }
      
//         if(qtd_letra >= 1){
//             qtd_palavra_com_letra++;
//         }else{
//             qtd_palavras_sem_letra++;
//         }
//         qtd_letra = 0;
//     }
    
//     total_de_palavras = (qtd_palavra_com_letra + qtd_palavras_sem_letra);

//     porcentagem = ((qtd_palavra_com_letra * 100)/total_de_palavras);

//     printf("%.1f\n",porcentagem);
//     return 0;
// }
//Usando uma função
int contaString(char str[]);
int main(){
    char letra;
    char frase[1002]={};
    scanf("%c\n",&letra);
    fgets(frase,1002,stdin);
    int espaco[1000]={};
    int cont = 0;
    int tamanho_Frase = contaString(frase);
    for(int i=0;i<tamanho_Frase;i++){
        if(frase[i]==' '){
            espaco[cont]=i;
            cont++;
        }
    }
    espaco[cont+1]=12345;
    float qntd_Palavra = cont + 1.0;
    cont=0;
    float qntd_Letras=0.0;
    int check=0;
    for( ;check<tamanho_Frase;check++){
        if(frase[check]==letra){
            qntd_Letras++;
            if(qntd_Palavra==1){
                break;
            }
            if(check<espaco[cont]){
                check=espaco[cont];
                cont++;
            } else{
                for(cont;check>espaco[cont];cont++){
                }
                if(espaco[cont]==12345){
                    break;
                } else{
                    check=espaco[cont];
                }
            }
        }
    }
    float prcen = (qntd_Letras/qntd_Palavra)*100;
    printf("%.1f\n",prcen);
    return 0;
}
int contaString(char str[]){
    int tamanho = 0;
    while (str[tamanho] != '\0')
    {
        tamanho++;
    }
    return tamanho;
}
