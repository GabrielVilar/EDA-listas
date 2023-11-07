#include <stdio.h>
int main()
{
    int n, V[10000], iPar, iImpar;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
       scanf("%d", &V[i]);
    }
    for(int i = 0; i < n; i++){
        if(V[i]%2==0){
            iPar = i;
            printf("%d ", iPar);
        }
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        if(V[i]%2!=0){
            iImpar = i;
            printf("%d ", iImpar);
        }
    }
}
