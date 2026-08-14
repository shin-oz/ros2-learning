#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  int a, b;
  srand((unsigned)time(NULL));

  // rand()で0~10まででるので、a,bは1~10の乱数を算出できる
  a = rand() % 10 + 1;
  b = rand() % 10 + 1;

  printf("%d + %d = %d\n", a, b, a + b);
}