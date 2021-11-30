#include <stdio.h>

int floatFloat2Int(unsigned uf)
{
  int sign = (uf >> 31) & 0x1;
  int e = (uf >> 23) & 0xFF;
  int frac = uf & 0x7FFFFF;

  int exponent = e - 127;
  int newFrac = 0x800000 + frac;
  printf("new Frac = %d %x\n", newFrac, newFrac);
  printf("Exponent = %d\n", exponent);
  int shifted;

  if (exponent < 0 || e == 0)
    return 0;
  if (exponent >= 31 || e == 0xFF)
    return 0x80000000;

  if (exponent > 23)
    shifted = newFrac << (exponent - 23);
  else
    shifted = newFrac >> (23 - exponent);

  if (sign)
    shifted = -shifted;
  printf("result = %x\n", shifted);
  return shifted;
}

int main() {
    unsigned f = 0xC0A00000;
    printf("%d\n", floatFloat2Int(f));
    printf("oct = %d hex = %x\n", f, f);
    return 0;
}
