#include <stdio.h>
/* sample rate: 8000 Hz. Unsigned 8 bit. 
 * compile with `gcc foo2.c -o foo`
 * play with `./foo2 | aplay -r 8000`
 */
void main() {
  long int t;
  for (t=0;;t++) {
    putchar(
        0xFA
        & (
          t 
          & t >> 6
          & ((t % (1 << 14)) < (1 << 13)? 
             t ^ t >> 8
             : t >> 8) 
          / (1 + t % 32) 
          ^ (t % 30)
          ^ ((t * (t>>18)) & 0xe0)
          ^ ((t * (t>>19)) & 0xe1)
          & (t > (1<<18) && t < (1<<19)? 0xdeadbeef / t : t)
          & (t > (1<<18)? t+=2 : t)

          //| t / 10

        )
    );
    //fprintf(stderr, "%x\n", t);
  }
}
