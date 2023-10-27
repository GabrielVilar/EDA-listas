#include <stdio.h>
int main()
{
    int n, g,v[10000], flag = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d",&g);
    for(int i = 0; i < n; i++){
        if(g == v[i]){
           flag++;
        }
    }
    if(flag > 0){
        printf("Pertence\n");
    }else if(flag == 0){
            printf("nao pertence\n");
    }
    
    return 0;
}
