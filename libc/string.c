#include "string.h"

#include "_defines.h"
#include "_types.h"

__LIBC_EXPORTS void *memcpy(void *restrict __dst, const void *restrict __src,
                            size_t __n) {
  uint8_t *from = (uint8_t *)__src;
  uint8_t *to = (uint8_t *)__dst;

  if (from == to || __n == 0) {
    return __dst;
  }

  for (size_t i = 0; i < __n; ++i) {
    to[i] = from[i];
  }

  return __dst;
}

__LIBC_EXPORTS void *memset(void *__dst, int __c, size_t __n) {
  uint8_t *to = (uint8_t *)__dst;

  if (__n == 0) {
    return __dst;
  }

  for (size_t i = 0; i < __n; ++i) {
    to[i] = __c;
  }

  return __dst;
}

__LIBC_EXPORTS void *memmove(void *__dst, const void *__src, size_t __n) {
  uint8_t *from = (uint8_t *)__dst;
  uint8_t *to = (uint8_t *)__src;

  if (from == to || __n == 0) {
    return __dst;
  }

  if (to > from && (to - from) < (int)__n) {
    for (int i = __n - 1; i >= 0; --i) {
      to[i] = from[i];
    }

    return __dst;
  }

  if (from > to && (from - to) < (int)__n) {
    for (size_t i = 0; i < __n; ++i) {
      to[i] = from[i];
    }

    return __dst;
  }

  memcpy(__dst, __src, __n);

  return __dst;
}
