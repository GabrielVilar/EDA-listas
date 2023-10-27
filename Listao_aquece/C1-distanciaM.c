#include <stdio.h>
int main(){

    int Xm, Ym, Xr, Yr;
    int distX, distY, dist;

    scanf("%d %d %d %d", &Xm, &Ym, &Xr, &Yr);

    if(Xr > Xm){
        distX = (Xr - Xm);
    }else{
        distX = (Xm - Xr);
    }

    if(Yr > Ym){
        distY = (Yr - Ym);
    }else{
        distY = (Ym - Yr);
    }

    dist = distX + distY;

    printf("%d\n", dist);
    
    return 0;
}