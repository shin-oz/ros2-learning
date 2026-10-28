#include <iostream>

using namespace std;

// newとdeleteはclassだけでなく一般の型にも実行可能　
int main() {
  int *p = 0;
  p = new int(); // int型の動的なメモリ領域を確保
  *p = 123;
  cout << *p << endl;
  delete p; // メモリ領域を解放
  return 0;
}

