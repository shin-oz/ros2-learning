#include "sample.h"
#include <iostream>

using namespace std;

int main () {
  Sample s;
  s.a = 1;
  // s.b = 2; privateのためヘッダの中以外では変更できない
  s.func1();
  // s.func2(); privateのためヘッダの中以外では読み出せない
}