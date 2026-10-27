#include <iostream>
#include "sample.h"

using namespace std;

int main() {
  CSample obj; //CSampleをインスタンス化
  int num;

  cout << "整数を入力してください";
  cin >> num;

  obj.set(num);
  cout << obj.get() << endl;

  return 0;
}