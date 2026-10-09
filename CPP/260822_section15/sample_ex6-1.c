#include <stdio.h>
#include <stdlib.h>

void main () {
  FILE *file;
  // fileポインタを書き込み用にオープンする
  file = fopen("/home/shinnosuke/projects/ros2-learning/CPP/260822_section15/sample.txt", "w");
  if (file == NULL) {
    printf("ファイルが開けません\n");
    // プログラムを異常終了する
    exit(1);
  }

  // fileポインタへの書き込み
  // windowsでファイルへのテキストファイル書き込みをする際の改行コードは\r\nになる。表示は通常の\nでよい
  fprintf(file, "Hello World. \r\n");
  fprintf(file, "ABCDEF\r\n");
  fprintf(file, "ええやんええやん\r\n");
  // fileポインタをクローズする
  fclose(file);
}

