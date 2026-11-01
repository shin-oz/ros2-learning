#ifndef _A_H_
#define _A_H_

class B;  // クラスBへの参照→おたがいが参照し合うとき、参照し合い続けて止まってしまうことを避ける

class A {
  private:
    B * m_pB;
  public:
    A(); // コンストラクタ
    virtual ~A();
    void foo();
    void bar();
};

#endif // _A_H_