#include <stdio.h>

int main(int t) {
  for (;;t++) {
    putchar(
        t 
        & t>>6
        & ((t%(1<<14))<(1<<13)? (t^t>>8):(t>>8)) 
        / (1+!t + (t%32)) 
        ^ ((t%30)) 
        | (((t%(1<<3)>(t<<8)? t%3 : t/10)))
    );
  }
  return 0;
}
