#ifndef __LIBC_EXPORTS
#define __LIBC_EXPORTS
#endif

#ifndef __LIBC_INLINE
#define __LIBC_INLINE static inline __attribute__((always_inline))
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif

#ifndef HUGE_VALF
#define HUGE_VALF (float)3.40282e+038
#endif

#ifndef HUGE_VAL
#define HUGE_VAL (double)1.79769e+308
#endif

#ifndef HUGE_VALL
#define HUGE_VALL (long double)1.79769e+308
#endif

#ifndef INFINITY
#define INFINITY (float)3.40282e+038
#endif

#ifndef NAN
#define NAN (char *)0x7fc00000
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif
