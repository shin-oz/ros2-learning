#ifndef _B_H_
#define _B_H_

class A;  // クラスBへの参照→おたがいが参照し合うとき、参照し合い続けて止まってしまうことを避ける

class B {
  private:
    A * m_pA;
  public:
    B(A* pA); // コンストラクタ
    virtual ~B();
    void hoge();
};

#endif // _B_H_