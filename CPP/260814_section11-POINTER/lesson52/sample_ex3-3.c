#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void main () {
  // ローカル変数はスタック領域なので自動的にメモリが解放される
  int *p1 = NULL;
  double *p2 = NULL;
  int i;

  // malloc関数: 必要なサイズのメモリをヒープ領域から動的に確保する
  // void*でreturnされるので、int*型にキャストする
  // 好きなタイミングでメモリを使え、メモリを使ったあとで削除できるのがメリット
  p1 = (int*)malloc(sizeof(int)*SIZE);
  p2 = (double*)malloc(sizeof(double)*SIZE);

  for (i = 0; i <SIZE; i++) {
    p1[i] = i;
    p2[i] = i / 10.0;
  }

  for (i = 0; i < SIZE; i++) {
    printf("p1[%d]=%d p2[%d] = %f\n", i, p1[i], i, p2[i]);
  }

  // ヒープ領域に確保したメモリは最後の解放しないといけない
  free(p1);
  free(p2);
}