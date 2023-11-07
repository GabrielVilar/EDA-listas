#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int num;
    char c;
    while (scanf("%x", &num) != EOF) { // lê números inteiros hexadecimal da entrada
        for (int i = 0; i < 4; i++) { // decodifica cada grupo de 1 byte
            c = (char) (num & 0xff); // extrai o byte menos significativo
            if (c == '\0') { // verifica se é o fim da mensagem
                printf("\n"); // imprime a mensagem decodificada
                exit(0); // finaliza o programa
            }
            printf("%c", c); // imprime o caractere decodificado
            num >>= 8; // remove o byte que já foi decodificado
        }
    }
    return 0;
}