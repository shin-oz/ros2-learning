#include <stdio.h>

void show(int, int, int);

void main () {
  int a = 100;
  int b = 200;
  // ポインタ変数には*をつける→ポインタへ代入すると、アドレスを指定するため、元の変数の値も変更する
  // 値は*でアクセスし、*がないとアドレスへアクセスになる
  // アドレスは変数に&をつけてアクセスする　
  int *p = NULL;

  p = &a;
  show(a, b, *p);

  *p = 300;
  show(a, b, *p);

  p = &b;
  show(a, b, *p);

  *p = 400;
  show(a, b, *p);
}