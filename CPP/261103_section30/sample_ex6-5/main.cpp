#include "sample.h"

// IInf1のみが使える関数
void foo(IInf1*);
// IInf2のみが使える関数
void bar(IInf2*);

int main() {
  CSample * s = new CSample();
  foo((IInf1*)s);
  bar((IInf2*)s);

  return 0;
}

// IInf1のみが使える関数
void foo(IInf1* p) {
  p->func1();
  p->func2();
  // p->func3();
  // p->func4();
}

// IInf2のみが使える関数
void bar(IInf2* p) {
  // p->func1();
  // p->func2();
  p->func3();
  p->func4();
}