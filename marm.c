#include <stdio.h>
/* sample rate: 8000 Hz. Unsigned 8 bit. 
 * compile with `gcc foo2.c -o foo`
 * play with `./foo2 | aplay -r 8000`
 */
void main(int t) {
  for (;;t++) {
    putchar(
        (((t * (t>>8) & 0xA0)
        ^ (t * (t>>7) & 0x0A))
        >> ((t>>11) % 4)  
        - ((t % 3)? 1 : 0)
        )
        & (t >> 8 & 0x2a) 
        ^ "\0MAR\0\0DUK"[(t>>10)&7]
        | (t * (t>>14) & 0x2a)
    );
  }
}
