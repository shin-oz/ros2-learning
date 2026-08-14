#include "showResult.h"
#include <stdio.h>

// グローバル変数のansを使えるようにする　
extern int ans;

void showAnswer() {
  printf("%d\n", ans);
}