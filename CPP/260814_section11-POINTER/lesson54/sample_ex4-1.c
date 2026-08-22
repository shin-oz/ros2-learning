#include <stdio.h>
#include <string.h>

void main () {
  char s[10];
  int len;

  // 文字列を代入
  strcpy(s, "ABC");
  printf("s=%s\n", s);

  // 文字列を追加
  strcat(s, "def");
  printf("s=%s\n", s);

  // 文字列の長さを算出
  len = strlen(s);
  printf("文字列の長さ: %d\n", len);
}