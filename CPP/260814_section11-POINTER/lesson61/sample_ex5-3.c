#include <stdio.h>
#include <string.h>

// student_data構造体を宣言
typedef struct {
  int id;
  char name[256];
  int age;
} student_data;

// ポインタ変数の値を指すのではないので、型名のあとに*
void setData(student_data*, int, char*, int);
void showData(student_data*);

void main () {
  student_data data[4];
  int i;
  int id[] = {1,2,3,4};
  // 4人ぶんの文字列を扱う場合は、256文字ぶんの箱を複数個必要
  char name[][256] = {"山田太郎", "佐藤良子", "太田隆", "中田優子"};
  int age[] = {18,19,18,18};
  
  for (i = 0; i < 4; i++) {
    // name[i]でなくname(4人ぶんの文字列)で渡してしまうとchar*(１文字列ぶんのポインタ)宣言と異なるのでNG
    setData(&data[i], id[i], name[i], age[i]);
  }

  for (i = 0; i < 4; i++) {
    showData(&data[i]);
  }
  return;
}

// char*は文字列の一番最初のアドレスを示し、\0がでてくるまでを示す
void setData(student_data* data, int id, char* name, int age) {
  // 構造体をポインタとして渡すのでアロー演算子を使う
  // 構造体を値の変数なら.で指定する
  data->id = id;
  // c langは文字列が増えたらヒープ領域を増やせないので、自動で領域を増やすappend()はない
  strcpy(data->name, name);
  data->age = age;
}

void showData(student_data* data) {
  printf("学生番号:%d 名前:%s 年齢:%d\n", data->id, data->name, data->age);
}