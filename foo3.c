#include <stdio.h>

int main(int t) {
  for (;;t++) {
    putchar(
        t 
        & t>>6
        & t>>8 
        / (1+!t + (t%32)) 
    );
  }
  return 0;
}
