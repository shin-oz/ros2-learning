#ifndef _POSITION2D_H_
#define _POSITION2D_H_

#include "vector2d.h"

// Position2Dクラスを継承
class Position2D : public Vector2D {
  public:
    // 位置のリセット
    void resetPosition();
    // 移動
    void move(int dx, int dy);
};

#endif // _POSITION_H_