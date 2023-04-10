#include <stdio.h>
int main()
{
    int n, V[10000], iMenor;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
       scanf("%d", &V[i]);
    }
    iMenor = 0;
    for(int i = 1; i < n; i++){
        if(V[i] < V[iMenor]){
            iMenor = i;
        }
    }
    printf("%d", iMenor);
    return 0;
}
