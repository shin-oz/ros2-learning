## unordered_mapとmapとsetの違い

- std::unordered_map
キーと値を格納し、順序保証なし
平均でO(1)最悪でO(n)
- std::map
キーと値を格納し、キー順の順序保証あり
O(logN)
- std::set
値だけ格納で、値順で格納
集合なので、重複を持たない　
O(logN)
- std::unordered_set
値だけ格納で、順番は決まっていない
集合なので、重複を持たない
平均でO(1)最悪でO(n)

## mapのkeyについて
キーを変えると並び順が壊れるため、キーにはconstがついている
```cpp
for (auto& [name, count] : errors) {
    count = 0;          // OK：値は書き換えられる
    // name = "x";      // コンパイルエラー：キーはconst
}
```