#include <iostream>
#include "sample.h"

using namespace std;

int main() {
  // CSample obj; //CSampleをインスタンス化
  // int num;

  // cout << "整数を入力してください";
  // cin >> num;

  // obj.set(num);
  // cout << obj.get() << endl;

  // 複数インスタンスを作成した場合
  CSample obj1, obj2;

  // obj1とobj2のメソッド（メンバ関数を呼び出し）
  obj1.set(1);
  obj2.set(2);

  cout << obj1.get() << endl;
  cout << obj2.get() << endl;

  return 0;
}