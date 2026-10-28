- cppでのclass宣言
``` cpp
class CSample // class宣言、classの名前は大文字から始める決まり
{
  public:
    void function(); // メンバ関数のことをとくにメソッドと呼ぶ
  private:
    int m_num;
};
```

- アクセス就職子→publicやprivateなど

- オブジェクト/インスタンスの作成
クラスは型なので、実体としてインスタンスが必要
設計図と、設計図をもとに作成した各車両のイメージ
``` cpp
CSample obj;
```

- メンバ変数やメンバ関数へのアクセス演算子は`.`
- インスタンスへのアクセス演算子は`->`