## const参照渡しと値渡しとポインタ渡しの比較
- 値渡し
変数の値をコピー
元の変数は変えられない
小さいデータの受け渡しに使う
`int x`
`func(a)`

- ポインタ渡し
アドレスのみコピー
元の変数を変えることができる
元データの変更が必要な場合に使う
`int* x`
`func(&a)`
→nullptrが渡され、問題になる可能性がある？？？

- 参照渡し
データもアドレスもコピーしない
元の変数は変える
大きなデータの読み取りに使う
`const int& x`
`func(a)`

- const参照渡し
データもアドレスもコピーしない
元の変数は変えず、元の変数を参照して読み取るら
大きなデータの読み取りに使う
`const int& x`
`func(a)`

### &と*の違い
&aは変数aのアドレスを取得
*aはポインタaが示す場所
int&参照の意味
&xはアドレスの意味

## autoの使い方
autoは変数の方をコンパイラが自動で推論してくれるキーワード
```cpp
aut a = 10; // int
auto b = 3.14; // double
auto c = std::string("hage"); // std::string
```

文字列をautoで代入しても、std::stringにはならない
```cpp
auto a = "hage" // std::stringにはならない
```

型名が長いときに便利
```cpp
std::vector<int> numbers = {10, 20, 30};
// std::vector<int>::iterator it = numbers.begin();と同義
// auto it = numbers.begin();
```

### autoと参照の関係
```cpp
int a = 10;
auto b = a; // bはaの値渡し
b = 100;
std::cout << a; // 10
```

```cpp
int a = 10;
auto& b = a; // 参照渡し
b = 100;
std:cout << a; // 100
```

```cpp
int a = 10;
const auto& b = a; // const参照渡し
// b = 100; // const参照のため変更できない
```

### autoを使う際の注意点
- 初期値から型を推論するため初期値が必要
```cpp
auto b; // エラー
```

- 型が自由に変わる仕組みではないため、後から型を変更できない
```cpp
auto a = 10; // int
a = 3.14; // intなので3になる

## 範囲forの使い方
配列やstd::vectorなどの要素を先頭から順番に取り出して処理するための構文
```cpp
std::vector<int> numbers = {10, 20, 30};
for(int num : numbers) { // intをautoにすると自動推論する
  std::cout << num << std::endl;
}
```