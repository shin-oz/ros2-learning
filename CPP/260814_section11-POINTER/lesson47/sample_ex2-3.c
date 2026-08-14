#include <stdio.h>

// int*はint型のポインタ変数
void swap (int*, int*);

void main () {
  int a = 1, b = 2;
  printf("a = %d b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d b = %d\n", a, b);
}

void swap (int *num1, int* num2) {
  // *num1はnum1というポインタ変数の指す先の値
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}