#include "math.h"

#include "_defines.h"

__LIBC_INLINE inline float fast_log2(float val) {
  int *const exp_ptr = (int *)(void *)(&val);
  int x = *exp_ptr;
  const int log_2 = ((x >> 23) & 255) - 128;
  x &= ~(255 << 23);
  x += 127 << 23;
  *exp_ptr = x;
  val = ((-1.0f / 3) * val + 2) * val - 2.0f / 3;
  return (val + log_2);
}

__LIBC_EXPORTS double log2(double num) { return (double)fast_log2((float)num); }
