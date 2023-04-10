#include <stdio.h>
int main()
{
    int jogador_A, jogador_B, jogador_C;

    scanf("%d %d %d", &jogador_A, &jogador_B, &jogador_C);

    if((jogador_A <= 1) && (jogador_B <=1) && (jogador_C <= 1)){
        if((jogador_A == jogador_B) && (jogador_B == jogador_C)){
            printf("empate\n");
        }else if((jogador_B + jogador_C) == 2){
            printf("A\n");
        }else if ((jogador_B + jogador_C) == 0){
            printf("A\n");
        } else if ((jogador_A + jogador_C) == 2){
            printf("B\n");
        }else if ((jogador_A + jogador_C) == 0){
            printf("B\n");
        }else if ((jogador_A + jogador_B) == 2){
            printf("C\n");
        }else if ((jogador_A + jogador_B) == 0){
            printf("C\n");
        }      
    }
    return 0;
}
