#include <stdio.h>
#include <stdlib.h>
// math.hはlinux環境では標準cライブラリでなくlibmに入っている
// gccはlibmを自動リンクしないため、明示する必要あり
// gcc sample_ex1-2.c -o sample_ex1-2 -lm
#include <math.h>

// 定数を定義
#define PI 3.14

void main () {
  // 三角関数
  // int angle;
  // double rad;

  // printf("角度を入力してください（0~360）");
  // scanf("%d", &angle);

  // rad = PI * (double)angle / 180.0;

  // printf("sin(%d)=%f\n", angle, sin(rad));
  // printf("cos(%d)=%f\n", angle, cos(rad));
  // printf("tan(%d)=%f\n", angle, tan(rad));

  // 他数学関数
  int n = -2;
  double d1 = -2.5, d2 = 4.0;

  printf("%dの絶対値は%d\n", n, abs(n));
  printf("%fの絶対値は%f\n", d1, fabs(d1));
  printf("%fの2乗は%f\n", d2, pow(d2, 2));
  printf("%fの平方根は%f\n", d2, sqrt(d2));

}