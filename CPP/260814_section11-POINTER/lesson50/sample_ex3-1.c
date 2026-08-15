#include <stdio.h>

#define SIZE 5

void main () {
  int ar1[SIZE];
  char ar2[SIZE];
  int i;
  int *p1 = NULL;
  char *p2 = NULL;

  for ( i = 0; i < SIZE; i++) {
    ar1[i] = i;
    ar2[i] = 'A' + i;
  }

  p1 = &ar1[0];
  p2 = &ar2[0];

  for ( i = 0; i < SIZE; i++ ) {
    // ポインタには最初のアドレスしか入れないが、以降の要素も出力できる
    // →ポインタを配列になりすますことができる　
    printf("ar1[%d]=%d *(p1+%d)=%d ", i, ar1[i], i, *(p1 + i));
    printf("ar2[%d]=%d *(p1+%d)=%c\n ", i, ar2[i], i, *(p2 + i));
  }
}