#include <stdio.h>

int main() {
  int x;
  while (1) {
    printf("x = ");
    scanf("%d", &x);
    printf("!x = %x\n", !x);
    printf("x ? 1 : 0 = %d", x ? 1 : 0);
  }
  return 0;
}