#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  // setは集合のSTL
  // ダブりを許さない
  // ダブって入力した場合は、重複して入力されるものは無視される
  set<string> names;

  names.insert("Tom");
  names.insert("Mike");
  names.insert("Mike"); // ダブって入力した場合
  names.insert("Bob");

  // 登録されている全データを表示
  set<string>::iterator it;
  for(it = names.begin(); it != names.end(); it++) {
    cout << *it << endl;
  }

  // Bob,Steveがデータ内に存在するか調べる
  string n[] = {"Bob", "Steve"};
  int i;
  
  for (i = 0; i < 2; i++) {
    it = names.find(n[i]);
    if (it == names.end()) {
      // データがset内に存在しない
      cout << n[i] << "is not in this set" << endl;
    } else {
      cout << n[i] << "is in this set" << endl;
    }
  }
  return 0;
}