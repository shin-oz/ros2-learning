#include <stdio.h>

typedef struct {
  int a;
  double d;
} num_data;

void dealData1(num_data data);
void dealData2(num_data *data);

void main () {
  num_data n1 = {1, 1.2};
  num_data n2 = {1, 1.2};

  printf("n1のアドレス:0x%x n2のアドレス:0x%x\n", (unsigned int)&n1, (unsigned int)&n2);

  dealData1(n1);
  // 構造体の場合は最初の値のアドレスから\0を取得できないのか？？？
  dealData2(&n2);

  printf("n1.a = %d n1.d = %f\n", n1.a, n1.d);
  printf("n2.a = %d n2.d = %f\n", n2.a, n2.d);
}

void dealData1(num_data data) {
  printf("a=%d d=%f\n", data.a, data.d);
  printf("dealData1にわたってきたデータのアドレス: 0x%x\n", (unsigned int)&data);
  data.a = 2;
  data.d = 2.4;
}

void dealData2(num_data *pdata) {
  // ポインタでわたしているからアロー関数を使う→わざわざわけるのはなぜ？　
  printf("a=%d d=%f\n", pdata->a, pdata->d);
  // なんでここはアドレスで取得しなくていい？　
  printf("dealData2にわたってきたデータのアドレス: 0x%x\n", (unsigned int)pdata);
  pdata->a = 2;
  pdata->d = 2.4;
}