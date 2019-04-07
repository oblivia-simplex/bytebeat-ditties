#include <stdio.h>
/* sample rate: 8000 Hz. Unsigned 8 bit. 
 * compile with `gcc foo2.c -o foo`
 * play with `./foo2 | aplay -r 8000`
 */
int main(int t) {
  for (t=0;;t++) {
    putchar(
        t 
        & t >> 6
        & ((t % (1 << 14)) < (1 << 13)? 
           t ^ t >> 8
           : t >> 8) 
        / (1 + t % 32) 
        ^ (t % 30) 
        | t / 10
    );
    fprintf(stderr, "%x\n", t);
  }
  return 0;
}
