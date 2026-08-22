#include <stdio.h>
#include <string.h>

struct student {
  int id;
  char name[256];
  int age;
};

// student_dataと書くと、struct studentと同じように書いたこととする
typedef struct student student_data;

void main () {
  int i;
  // 構造体配列を宣言
  student_data data[] = {
    {1, "山田太郎", 18},
    {2, "佐藤良子", 19},
    {3, "太田隆", 18},
    {4, "中田優子", 18}
  };

  for ( i = 0; i < 4; i++) {
    printf("学生番号:%d 名前:%s 年齢%d\n", data[i].id, data[i].name, data[i].age);
  }
}