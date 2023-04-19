#include <stdio.h>
int main()
{
    int cartas[5];
    int i, crescente = 1, decrescente = 1;

    for(i = 0; i < 5; i++){
        scanf("%d", &cartas[i]);
    }

    for (i = 0; i < 4; i++){
        if(cartas[i] > cartas[i+1]){
            crescente = 0;
        }else if(cartas[i] < cartas[i+1]){
            decrescente = 0;
        }
    }

    if(crescente){
        printf("C\n");
    }else if (decrescente)
    {
        printf("D\n");
    }else
    {
        printf("N\n");
    }  

    return 0;
}
/*
PDF Informativo:
    https://drive.google.com/file/d/1VXgzzfO8vsvR3sZfu6aamg8fBg2k-H9q/view
*/