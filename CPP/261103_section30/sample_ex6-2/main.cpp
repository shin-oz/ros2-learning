#include <iostream>
#include <string>
#include  "chicken.h"
#include  "crow.h"

int main() {
  CBird* b1, *b2;
  b1 = new CCrow();
  b2 = new CChicken();
  // b3 = new CBird();
  b1->sing();
  b1->fly();
  b2->sing();
  b2->fly();

  delete b1, b2;

  return 0;
}