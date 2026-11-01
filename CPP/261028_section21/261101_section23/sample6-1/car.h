#ifndef _CAR_H_
#define _CAR_H_

class CCar {
  public:
    // コンストラクタ: インスタンスが生成される時に実行
    CCar();
    // デストラクタ: インスタンスが破棄される時に実行
    ~CCar();
    // 移動メソッド
    void move();
    // 燃料補給メソッド
    void supply(int fuel);
  private:
    int m_fuel;
    int m_migration; // 移動距離
};

#endif