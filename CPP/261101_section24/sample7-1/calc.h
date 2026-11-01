#ifndef _CALC_H_
#define _CALC_H_

class CCalc {
  private:
    int m_a, m_b;
  public:
    // デフォルトコンストラクタ
    CCalc();
    // コンストラクタ（引数つき）
    CCalc(int a, int b);
    // 足し算処理その１
    int add();
    // 足し算処理その２
    int add(int a, int b);
    // 値の設定
    void setValue(int a, int b);
    // 値の取得(m_a)
    int getA();
    // 値の取得(m_bj)
    int getB();
};

#endif // _CALC_H_