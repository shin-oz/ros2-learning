#include <stdio.h>
#include <stdlib.h>

void main63 () {
  FILE *file;
  int c;
  file = fopen("/home/shinnosuke/projects/ros2-learning/CPP/260822_section15/sample.txt", "r");
  if (file == NULL) {
    printf("ファイルが開けません。\n");
    exit(1);
  }

  // ファイルをEOFが出るまで、1文字ずつ読み込み
  while ((c = fgetc(file)) != EOF) {
    printf("%c", (char)c);
  }
  fclose(file);
}