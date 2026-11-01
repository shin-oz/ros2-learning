#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

// 二次元ベクトルクラス
class Vector2D {
  protected: // このスーパークラスにあるメンバを、こスーパークラスとサブクラス以外では使えなくする
    int m_x;
    int m_y;
  public:
    // コンストラクタ
    Vector2D();
    // 値の設定
    void setValue(int x, int y);
    // x座標の取得
    int getX();
    // Y座標の取得
    int getY();
  protected: // このスーパークラスにあるメンバを、こスーパークラスとサブクラス以外では使えなくする
    // 初期化
    void init();
};

#endif // _VECTOS2D_H_