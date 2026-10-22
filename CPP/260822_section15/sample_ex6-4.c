#include <stdio.h>
#include <stdlib.h>

void main () {
  FILE* file;
  int i;

  // 書き込むデータ:4byte分のバイナリデータを宣言
  char wdata[] = {0x10, 0x1a, 0x1e, 0x1f};
  char rdata[4];

  // バイナリデータの書き込み; wbでbinaryをwirteする
  file = fopen("/home/shinnosuke/projects/ros2-learning/CPP/260822_section15/test.bin", "wb");
  if (file == NULL) {
    printf("ファイルオープンに失敗しました。\n");
    exit(1);
  }
  // 書き込み、wdataをchar型のサイズでwdataサイズでfileポインタに入れる
  fwrite(wdata, sizeof(char), sizeof(wdata), file);
  fclose(file);

  file = fopen("/home/shinnosuke/projects/ros2-learning/CPP/260822_section15/test.bin", "rb");

  if (file == NULL) {
    printf("ファイルオープンに失敗しました\n");
    exit(1);
  }

  fread(rdata, sizeof(char), sizeof(rdata), file);
  fclose(file);

  for ( i = 0; i < sizeof(rdata); i++ ) {
    printf("%x", rdata[i]);
  }
  printf("\n");
}