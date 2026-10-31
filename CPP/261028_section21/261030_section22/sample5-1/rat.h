#ifndef _RAT_H_
#define _RAT_H_

class CRat {
  public:
    // コンストラクタ
    CRat();
    // デストラクタ
    ~CRat();
    // ネズミの数の出力
    // staticは、クラス全体で共有されるので、インスタンスを生成しなくても実git add 
    static void showNum();
    // ネズミが鳴く
    void squeak();
  private:
    // ネズミの番号
    int m_id;
    // ネズミの数
    // staticは、インスタンスがなんこできても一つしか生成されず共有される
    static int m_count;
};

#endif // _RAT_H_