#include <stdio.h>

void main () {
  unsigned char i = 0xf;
  unsigned char j = 0xff;
  
  printf("%x << 1 = %x\n", i, i << 1);
  printf("%x >> 1 = %x\n", i, i >> 1);
  printf("%x | %x = %x\n", i, j, i | j);
  printf("%x & %x = %x\n", i, j, i & j);
  printf("~%x = %x\n", i, (unsigned char)~i);
}