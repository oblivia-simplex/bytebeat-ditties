#include <stdio.h>

int main(int t) {
  int x = 6;
  for (;;t++) {
    putchar(
        t & (x|(x%128? x/=2 : x++)) & t>>5 ^ t << (t%9? 1 : 2) & t>>8
    );
  }
  return 0;
}
