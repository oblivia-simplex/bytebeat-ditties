#include <stdio.h>
/* sample rate: 8000 Hz. Unsigned 8 bit. 
 * compile with `gcc foo2.c -o foo`
 * play with `./foo2 | aplay -r 8000`
 */
void main() {
  long int t;
  int rev = 0;
  for (t=0;;t++) {
    putchar(
        0xFA
        & (
          t 
          & t >> 6
          & ((t % (1 << 14)) < (1 << 13)? 
             t ^ t >> 8
             : t >> 8) 
          / (t <= 0? 1 : (1 + t % 32))
          ^ (t % 30)
          + ((t * (t>>18)) & 0xe0)
          //^ ((t * (t>>19)) & 0xe1) //?
          //& (t > (1<<18) && t < (1<<19)? 0xdeadbeef / t : t)
          & (t > (1<<18)? t+=2 : t)
          //& (t > (1<<20)? rev=1 : t)
          //& (rev? t +=1 >> 2 : t)
          & (t < 1? rev = 0 : t)

          | ((t / 10) & (t >> 14) & (t>>15) & 0xaa)

        )
    );
  }
}
