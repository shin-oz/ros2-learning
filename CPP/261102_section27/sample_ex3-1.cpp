#include <iostream>
#include <string>

using namespace std;

// テンプレート関数
// Tに好きなものを入れることができる
template <typename T>
T add(T x, T y) {
  return x + y;
}

int main() {
  // Tがintの場合
  cout << add<int>(4, 3) << endl;
  // Tがstringの場合
  cout << add<string>("ABC", "DEF") << endl;
  cout << add(1, 2) << endl;

  // intとdoubleなので、Tは一種類しかないのでエラーになる
  // cout << add(1, 2.3) << endl;
  // doubleとdoubleなので、Tは一種類しかないのでエラーにならない
  cout << add(1.0, 2.3) << endl;

}