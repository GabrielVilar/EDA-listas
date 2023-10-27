#include <stdio.h>
#include <stdlib.h>
int timeltravel(int Gates, int GateIwant, int whereIam, int Past, int Future);
int main(int argc, char const *argv[])
{
    printf("%d\n", timeltravel(100,12,2,1,3));

    for (int i = 1; i >= 0; i= i - 1)
    {
       // printf("%d\n",i);
    }
    
    return 0;
}
int timeltravel(int Gates, int GateIwant, int whereIam, int Past, int Future){
    int gatesUp, gatesDown, cont1 = 0, cont2 = 0;
    gatesUp = Gates - whereIam;
    gatesDown = (Gates - (gatesUp + 1));

    if (GateIwant < whereIam){
        for (int i = gatesDown; i >= 0; i = i - Past){
            cont1++;
            if (i == GateIwant)
            {
                return cont1;
            }else{
                return -1;
            }
        }
    }else{
        for (int i = whereIam; i <= gatesUp; i+= Future){
            cont2++;
            if (i == GateIwant)
            {
                return cont2;
            }else{
                return -1;
            }
            
        }
        
    }
    
}