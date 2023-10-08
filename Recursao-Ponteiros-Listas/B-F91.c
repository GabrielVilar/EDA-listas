#include <stdio.h>
int f91(int n);
int main() {
    int numero;
    do {        
        scanf("%d", &numero);
        if(numero!= 0) printf("f91(%d) = %d\n", numero, f91(numero));
        
    } while(numero != 0);
    
}
int f91(int n) {
    if(n >= 101) {
        return n - 10;
    } else {
        return f91(f91(n + 11));
    }
}