#define __WINE_CONFIG_H

#define HAVE_STRERROR
#define HAVE_MEMMOVE
#define HAVE_FLOAT_H

#undef inline
#define inline __inline

#define HAVE_STRING_H
#define HAVE_SPAWNVP
#define HAVE_IO_H
#define HAVE_POLL
#define HAVE_PROCESS_H
#define DECLSPEC_HOTPATCH
#define DECLSPEC_NORETURN
#define HAVE__ISNAN 1
#define HAVE__FINITE 1
#define HAVE__STRICMP 1
#define USE_COMPILER_EXCEPTIONS

#ifdef __x86_64__
#define HAVE_SIZE_T
typedef unsigned __int64    size_t;
#endif

#ifdef WOW64
#define HAVE_SIZE_T
typedef unsigned __int64 size_t;
#endif

#include <direct.h>
#define snprintf _snprintf
#define strtoull _strtoui64
