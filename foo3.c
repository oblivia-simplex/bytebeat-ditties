#include <stdio.h>
#define W 1024 

int main(int t) {
  unsigned int buf[W];
  for (;;t++) {
    putchar(
      34535293 / ((t % 12242)+1)
      & (t >> 10)
      ^ (t % 0x10)
      / (t << (t % 0x10) & 0x3)
    );
  }
  return 0;
}
