#include <stdio.h>

int main(int argc, char **argv) {
  while (1) {
    int i = argc;
    int s[72] = {2048};
    int q[72] = {512};
    int counter = 0;
    for (;; i %= 72) {
      s[i] += s[(i+1)%72];
      q[(i+36)%72] += q[(i+37)%72];
      putchar(q[i++]=(1<<(i % 100? q[i]^i : q[i]/2)));
      counter++;
      if (counter == 10000) break;
    }
  }
  return 0;
}
