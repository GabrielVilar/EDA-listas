#include <stdio.h>
long long int somaDigitos(long long int num) {
   if (num < 10) {
      return num;
   }
   return (num % 10) + somaDigitos(num / 10);
}

int main() {
   long long int num;
   scanf("%lld", &num);
   int soma = somaDigitos(num);
   printf("%d\n", soma);
   return 0;
}