#include <iostream>
#include <string>
#include "chicken.h"
#include "chicken.h"
#include "crow.h"

int main() {
  CBird* b1, *b2;
  b1 = new CCrow();
  b2 = new CChicken();
  b1->sing(); // virtualで仮想関数なので、インスタンス側で別処理があればそちらを実行する
  b1->fly();
  b2->sing(); // virtualで仮想関数なので、インスタンス側で別処理があればそちらを実行する
  b2->fly();

  delete b1, b2;

  return 0;
}