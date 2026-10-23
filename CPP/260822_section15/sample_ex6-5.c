#include <stdio.h>
#include <stdlib.h>

void main () {
  FILE* file;
  int i, size;

  // 書き込むデータ:4byte分のバイナリデータを宣言
  char* rdata;

  // バイナリデータの書き込み; rbとは？？？
  // ファイルサイズはわからない可能性がある->mallocを使い、ファイルサイズを確認してから代入する
  file = fopen("/home/shinnosuke/projects/ros2-learning/CPP/260822_section15/test.bin", "rb");
  if (file == NULL) {
    printf("ファイルオープンに失敗しました。\n");
    exit(1);
  }
  // ファイルの最後までseek（読み込む？移動？）
  fseek(file, 0, SEEK_END);
  // ファイルのサイズを取得
  size = ftell(file);

  // メモリサイズだけ配列を動的に取得
  rdata = (char*)malloc(sizeof(char)*size);

  // ファイルの最後までポインタを渡す
  fseek(file, 0, SEEK_SET);
  fread(rdata, sizeof(char), size, file);
  fclose(file);

  for ( i = 0; i < sizeof(rdata); i++ ) {
    printf("%x", rdata[i]);
  }
  printf("\n");
  // メモリ解放
  free(rdata);
}