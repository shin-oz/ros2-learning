// 標準入出力
#include <iostream>

// 名前空間→大規模開発で名前がかぶらないように同じ名前でも領域が異なれば問題ないようにする
// 標準名前空間を使う
// 標準名前空間でないとcoutやendlはつ買えない
using namespace std;

int main () {
  // stream→データの流れ
  // countにデータを流すとコンソール画面に表示される
  // endlが改行コードを示す
  cout << "HelloWorld." << endl;
  cout << "ABE#" << "123" << endl << "def" << endl;
  return 0;
}