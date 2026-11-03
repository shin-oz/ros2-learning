#ifndef _BIRD_H_
#define _BIRD_H_

#include <iostream>
#include <string>

using namespace std;

class CBird {
  public:
    // 鳴く関数：仮想関数
    virtual void sing() = 0;
    // 飛ぶ関数
    virtual void fly() { cout << "鳥が飛びます　" << endl; }
};

#endif // _BIRD_H_