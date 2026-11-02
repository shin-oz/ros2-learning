- ジェネリックプログラミング
演算子あ同じであれば、型がなんであっても使えるようにすること
→cppではテンプレートを使う

- テンプレート関数とテンプレートクラスがある

- テンプレート関数
```cpp
// Tにどんな型がきてもいい
template <template T>
T add(T x, T y) {
  return x + y;
}
```

- テンプレートクラス
ヘッダファイルないで実装することを推奨
```cpp
template <template T> class CCalc
CCalc<int> i1;
CCalc<string> i2;
```