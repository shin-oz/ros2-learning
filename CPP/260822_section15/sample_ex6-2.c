#include <stdio.h>
#include <stdlib.h>

#define SIZE 256

// 一つのフォルダに同じ名前のmain()は存在してはいけない？
// コードを実行すると問題は発生しないが、なぜか何も表示されない。。。　
void main62() {
  FILE *file;
  // 1行読み込む先のサイズを256で宣言する
  char line[SIZE];
  // line文字列はなにもないことにするために初期化する
  line[0] = '\0';
  // テキストファイルを読み込む
  file = fopen("/home/shinnosuke/projects/ros2-learning/CPP/260822_section15/sample.txt", "r");

  if (file == NULL) {
    printf("ファイルが開けません。\n");
    exit(1);
  }

  // ファイルの読み込み　
  // fgets():読み込みが続く間はNULL以外が帰ってくるので、lineを表示する
  while (fgets(line, SIZE, file) != NULL) {
    printf("%s", line);
  }
  
  fclose(file);
}
