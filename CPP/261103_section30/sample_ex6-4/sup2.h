#ifndef _SUP2_H_
#define _SUP2_H_

#include <iostream>

class CSup2 {
  public:
    CSup2() { cout << "CSup2のコンストラクタ" << endl; }
    virtual ~CSup2() { cout << "CSup2のデコンストラクタ" << endl; }
};

#endif // _SUP2_H_