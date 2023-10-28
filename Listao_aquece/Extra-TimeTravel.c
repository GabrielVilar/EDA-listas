// #include <stdio.h>
// #include <stdlib.h>
// int timeltravel(int Gates, int GateIwant, int whereIam, int Past, int Future);
// int main(int argc, char const *argv[])
// {
//     printf("%d\n", timeltravel(100,12,2,1,2));
    
//     return 0;
// }
// int timeltravel(int Gates, int GateIwant, int whereIam, int Past, int Future){
//     int gatesUp, gatesDown, cont1 = 0, cont2 = 0;
//     gatesUp = Gates - whereIam;
//     gatesDown = (Gates - (gatesUp + 1));

//     if (GateIwant < whereIam){
//         for (int i = gatesDown; i >= 0; i = i - Past){
//             cont1++;
//             if (i == GateIwant)
//             {
//                 return cont1;
//             }else{
//                 return -1;
//             }
//         }
//     }else{
//         for (int i = whereIam; i <= gatesUp; i= i + Future){
//             cont2++;
//             if (i == GateIwant)
//             {
//                 return cont2;
//             }else{
//                 return -1;
//             }
//         }
//     }
// }
#include <stdio.h>
#include <stdlib.h>

int timeltravel(int Gates, int GateIwant, int whereIam, int Past, int Future);

int main(int argc, char const *argv[]) {
    printf("%d\n", timeltravel(100, 100, 99, 1, 0));
    
    return 0;
}

int timeltravel(int Gates, int GateIwant, int whereIam, int Past, int Future) {
    if (GateIwant < 1 || GateIwant > Gates || whereIam < 1 || whereIam > Gates) {
        return -1; // Invalid gate numbers
    }

    if (GateIwant == whereIam) {
        return 0; // Already at the desired gate
    }

    if (GateIwant < whereIam && Past <= 0) {
        return -1; // Cannot travel to the past with Past <= 0
    }

    if (GateIwant > whereIam && Future <= 0) {
        return -1; // Cannot travel to the future with Future <= 0
    }

    if (GateIwant < whereIam && Past >= whereIam - 1) {
        return -1; // Cannot travel to the past with insufficient Past value
    }

    if (GateIwant > whereIam && Future >= Gates - whereIam) {
        return -1; // Cannot travel to the future with insufficient Future value
    }

    int jumps = 0;

    if (GateIwant < whereIam) {
        while (whereIam > GateIwant) {
            whereIam -= Past;
            jumps++;
        }
    } else {
        while (whereIam < GateIwant) {
            whereIam += Future;
            jumps++;
        }
    }

    return (whereIam == GateIwant) ? jumps : -1;
}



