#ifndef _SAMPLE_H_
#define _SAMPLE_H_
#include <iostream>
#include <string>

using namespace std;

class CSample {
  private:
    string m_str;
  public:
    CSample();
    void setStr(const string str); // 引数をconstに
    string getStr() const; // メンバ変数のconst化
  public:
    static const int m_cst = 100; // 定数
};

#endif // _SAMPLE_H_