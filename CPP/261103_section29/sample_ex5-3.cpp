#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
  stack<int> stk; // スタックのデータを宣言
  queue<int> que; //キューのデータを宣言
  int data[] = {1, 2, 3};
  int i;

  // データの登録
  for(i = 0; i < 3; i++) {
    stk.push(data[i]);
    que.push(data[i]);
  }

  // データの出力(stack)
  cout << "stack: ";
  while(!stk.empty()) {
    // topで要素を取得し、popでその要素をstkから取り除く
    cout << stk.top() << " ";
    stk.pop();
  }
  cout << endl;
  
  // データの出力(queue)
  cout << "queue: ";
  while(!que.empty()) {
    // frontで要素を取得し、popでその要素をqueから取り除く
    cout << que.front() << " ";
    que.pop();
  }
  cout << endl;
}