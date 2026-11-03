- STL: standard template library
- CPPの標準的なライブラリとして使われる

- 通常の配列はファイルの読み書きなど、あらかじめどんな大きさの配列にすべきかわからないケースには不向き。vector, list, mapならサイズを意識せずに使える

- vector:サイズを気にせずに使える配列
```cpp
#include <vector>

vector<int> v1;
vector<string> v1;

v1.push_back(1);
v2.push_back("DEF");
```

- vectorのメンバ関数
`push_back()` 要素の追加
`clear()` 要素のクリア
`size()` 配列の大きさを取得
`capacity` 動的配列に追加できる要素の許容量
`epmty()` 要素が空かどうか調べる

- list: vectorは動的配列のため、配列のインデックスが変わるような前へのデータ挿入はできなかった。listは前へのデータ挿入が可能

- listはvectorや配列のようにインデックスを使うことができず、イテレータを使う
```cpp
list<int>::iterator itr;
itr = li.begin();
insert(itr,4);
```

- removeメソッドはvectorには存在しない

- vectorはあくまでも配列の延長で、サイズを指定しなくてを指定しなくても使うことを主眼
→任意の場所への要素追加や削除は目的でない

- listは任意の場所への削除や挿入が想定されている。挿入でインデックスがかわるので、イテレータが必要

- listのメンバ関数
`push_front()` 先頭に要素を追加
`push_back()` 末尾に要素を追加
`pop_front()` 先頭の要素を削除
`pop_back()` 末尾の要素を削除　
`insert()` 要素を挿入する
`erase()` 要素を削除
`clear()` 全要素を削除
