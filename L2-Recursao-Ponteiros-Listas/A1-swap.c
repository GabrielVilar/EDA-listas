#include <stdio.h>
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
int main(){
  int a, b;
  a = 3;
  b = 7;
  
  printf("Antes: %d %d\n", a, b);
  swap(&a,&b);
  printf("Depois: %d %d", a, b);
}