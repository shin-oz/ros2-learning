#ifndef _SAMPLE_H_ // マクロを定義して、2重インクルードを防止
#define _SAMPLE_H_

// クラス宣言
// 一つのヘッダファイルごとに一つのクラスを宣言するのがcppの思想
// クラスの銭湯は大文字で始めるのが原則
class CSample // クラス名もヘッダファイル名とそろえるべき
  {
    public:
      // メンバ関数
      void set(int num); // m_numに値を取得
      int get(); // m_numに値を代入
    private:
      // メンバ変数
      int m_num;
  };

// 二重インクルードを防止
#endif //_SAMPLE_H_
