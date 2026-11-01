#ifndef _AMBLANCE_H_
#define _AMBLANCE_H_

#include "car.h"

// : public CCarでCCarクラスを継承
class CAmblance : public CCar {
  public:
    // コンストラクタ
    CAmblance();
    // デコンストラクタ
    virtual ~ CAmblance(); // 継承した場合はデコンストラクタはvirtualが必要ならしい
    void savePeople();
  private:
    int m_number;
};

#endif // _AMBLANCE_H_
