#include <stdio.h>
#include <stdlib.h>

void main () {
  char s1[] = "1000";
  char s2[] = "12.345";

  int a;
  double b;

  // 文字列を整数や実数に変換
  a = atoi(s1);
  b = atof(s2);

  printf("a=%d b=%f\n", a, b);

}