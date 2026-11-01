#include "amblance.h"
#include <iostream>

using namespace std;

// コンストラクタ
CAmblance::CAmblance() : m_number(119) {
  cout << "CAmblanceオブジェクト作成" << endl;
}

// デコンストラクタ
CAmblance::~CAmblance() {
  cout << "CAmblanceオブジェクト破棄" << endl;
}

// 救急救命活動
void CAmblance::savePeople() {
  cout << "救急救命活動" << endl << "読み出しは" << m_number << "番" << endl;
}