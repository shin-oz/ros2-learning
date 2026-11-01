#include "sample.h"

int main() {
  Sample* p1, *p2;
  // sample.hには引数ありのコンストラクタしか宣言されていない
  // 引数ありのコンストラクタを宣言すると、引数なしのコンストラクタは自動生成されなくなってしまう
  p1 = new Sample(1); // 引数のあるコンストラクタ
  // p2 = new Sample(); // デフォルトコンストラクタの読み出し
  return 0;
}