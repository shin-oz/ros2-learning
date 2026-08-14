#include <stdio.h>

void main () {
  int a = 100;
  double b = 123.4;
  float c = 123.4f;
  char d = 'a';

  printf("aの値は%d、大きさは%zubyte、アドレスは0x%ls\n", a, sizeof(int), &a);
  printf("bの値は%f、大きさは%zubyte、アドレスは0x%p\n", b, sizeof(double), &b);
  printf("cの値は%f、大きさは%zubyte、アドレスは0x%p\n", c, sizeof(float), &c);
  printf("dの値は%c、大きさは%zubyte、アドレスは0x%s\n", d, sizeof(char), &d);
}