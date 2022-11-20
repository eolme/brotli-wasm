#include "_types.h"

__LIBC_EXPORTS void *memset(void *__dst, int __c, size_t __n);

// bulk-memory
__LIBC_EXPORTS void *memcpy(void *__dst, const void *__src, size_t __n);

// bulk-memory
__LIBC_EXPORTS void *memmove(void *__dst, const void *__src, size_t __n);
