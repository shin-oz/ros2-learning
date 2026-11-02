#ifndef _CACL_H_
#define _CALC_H_

template<typename T> class CCalc {
  private:
    T m_n1;
    T m_n2;
  public:
    // 一つのマシンコードにまとめてビルドする？？？
    inline void set(const T n1, const T n2) {
      m_n1 = n1; m_n2 = n2;
    };// 引数のセット
    inline T add() const {
      return m_n1 + m_n2;
    };// 計算結果
};

#endif // _CALC_H_