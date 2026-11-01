#include "sup1.h"
#include "sub1.h"

int main() {
  Sup1 *sp1;
  Sub1 *sp2;
  sp1 = new Sup1();
  sp2 = new Sub1();

  sp1->func();
  sp2->func();
  // delete sp1;
  // delete sp2;
  delete sp1, sp2;

  return 0;
}