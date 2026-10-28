#include "car.h"
#include <iostream>

using namespace std;

int main() {
  CCar* pC = 0; // CCarクラスのポインタ
  pC = new CCar();
  pC->supply(10); // 構造体と同じくポインタのメンバには->を使う
  pC->move();
  pC->move();
  // なにもないのにdeleteすると異常終了してしまう
  delete pC; // garbageコレクションがないので、インスタンスを削除しないとどんどんメモリ負荷が増してしまう
  cout << "インスタンスの削除終了" << endl;
  return 0;
}