#include <stdio.h>
int main()
{
    int i,n, v[10000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for(int i = 0; i< n ; i++){
        if(v[i]%2 == 0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
    for(int i =0; i<n;i++){
        if(v[i] %2 != 0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
    return 0;
}
/*
PDF Informativo:
    https://drive.google.com/file/d/1qsrn1Lp77VnN5canpog3XCc3QHQ-2k0Q/view
*/