#include <stdio.h>
#include <string.h>

struct student {
  int id;
  char name[256];
  int age;
};

void main () {
  struct student data;  // dataというstudent構造体を宣言
  data.id = 1;
  // ここはなぜdatan.name = "山田太郎"ではだめ?
  // cの配列は初期化時しか'='でまとめて代入できないので、strcpyを使う
  strcpy(data.name, "山田太郎");
  data.age = 18;

  printf("学生番号:%d 名前:%s 年齢:%d\n", data.id, data.name, data.age);
}