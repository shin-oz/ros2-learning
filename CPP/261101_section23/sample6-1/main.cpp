#include "car.h"
#include "ambulance.h"

int main() {
  CCar c;
  c.suply(10); // 燃料給油
  c.move();
  c.move();

  CAmbulance a; // CAmbulanceはCCarクラスを継承
  a.supply(10);
  a.move();
  a.savePeople();

  return 0;
}