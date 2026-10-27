#include <iostream>
// stringを使うならばstringが必要
#include <string> // Cのstring.hとは異なる

using namespace std;

int main () {
  string s, t;
  t = "入力された文字は";
  cout << "文字列を入力: ";
  cin >> s;
  cout << t + s << "です" << endl;
  return 0;
}

