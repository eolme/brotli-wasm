typedef unsigned long size_t;

typedef unsigned long uintptr_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifndef __LIBC_EXPORTS
#define __LIBC_EXPORTS
#endif

#ifndef __LIBC_INLINE
#define __LIBC_INLINE static inline __attribute__((always_inline))
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

#ifndef HUGE_VAL
#define HUGE_VAL (double)1.79769e+308
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif
