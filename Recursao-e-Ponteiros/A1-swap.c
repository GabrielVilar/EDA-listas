#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int main(){
  int a, b, *aa, *bb;
  a = 3;
  aa = &a; 
  b = 7;
  bb = &b;
  swap(aa,bb);
  printf("%d %d\n", *aa, *bb);
  return 0;
}
