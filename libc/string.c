#include "string.h"

__LIBC_EXPORTS void *memset(void *restrict __dst, int __c, size_t __n) {
  register uint8_t *to = (uint8_t *)__dst;

  if (__n == 0) {
    return __dst;
  }

  for (size_t i = 0; i < __n; ++i) {
    to[i] = __c;
  }

  return __dst;
}
