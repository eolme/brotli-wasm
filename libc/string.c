#include "string.h"

#include "_defines.h"
#include "_types.h"

__LIBC_EXPORTS void *memcpy(void *__dst, const void *__src, size_t __n) {
  unsigned char *csrc = (unsigned char *)__src;
  unsigned char *cdest = (unsigned char *)__dst;

  for (int i = 0; i < __n; ++i) {
    cdest[i] = csrc[i];
  }

  return __dst;
}

__LIBC_EXPORTS void *memset(void *__dst, int __c, size_t __n) {
  unsigned char *cdest = __dst;

  while (__n > 0) {
    *cdest = (unsigned char)__c;
    ++cdest;
    --__n;
  }

  return __dst;
}

__LIBC_EXPORTS void *memmove(void *__dst, const void *__src, size_t n) {
  unsigned char *from = (unsigned char *)__dst;
  unsigned char *to = (unsigned char *)__src;

  if (from == to || n == 0) return __dst;
  if (to > from && to - from < (int)n) {
    /* to overlaps with from */
    /*  <from......>         */
    /*         <to........>  */
    /* copy in reverse, to avoid overwriting from */
    int i;
    for (i = n - 1; i >= 0; i--) to[i] = from[i];
    return __dst;
  }
  if (from > to && from - to < (int)n) {
    /* to overlaps with from */
    /*        <from......>   */
    /*  <to........>         */
    /* copy forwards, to avoid overwriting from */
    size_t i;
    for (i = 0; i < n; i++) to[i] = from[i];
    return __dst;
  }
  memcpy(__dst, __src, n);
  return __dst;
}
