#include "_defines.h"

__LIBC_EXPORTS extern unsigned char __heap_base;

#ifdef __INTELLISENSE__
unsigned int bump_pointer = 0;
#else
unsigned int bump_pointer = (unsigned int)(void *)&__heap_base;
#endif

__LIBC_EXPORTS void *malloc(unsigned long n) {
  unsigned int r = bump_pointer;
  bump_pointer += (((n - 1) / 8) + 1) * 8;
  return (void *)r;
}

__LIBC_EXPORTS void *free(void *p) { return 0; }

__LIBC_EXPORTS void *exit(int code) { return 0; }
