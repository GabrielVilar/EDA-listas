#include <stdio.h>
int main()
{
    int nmr_repeticoes;
    char Thums[]="THUMS";
    scanf("%d", &nmr_repeticoes);
    for(int i = 1; i <=nmr_repeticoes; i++){
        if(i%2 != 0){
            printf("%s %s %s\n", Thums, Thums, Thums);
        }else if (i%2 == 0){
            printf("%s %s %s %s %s %s\n", Thums, Thums, Thums, Thums, Thums, Thums);
        }
        
    }
    return 0;
}
/*
PDF Informativo:
    https://drive.google.com/file/d/1FDKu5w-LpCy4G3tZcvmbPz7MZjGS6580/view
*/