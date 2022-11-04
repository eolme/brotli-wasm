#ifndef __LIBC_EXPORTS
#define __LIBC_EXPORTS __attribute__((visibility("default")))
#endif

#ifndef __LIBC_INLINE
#define __LIBC_INLINE __attribute__((__always_inline__))
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
