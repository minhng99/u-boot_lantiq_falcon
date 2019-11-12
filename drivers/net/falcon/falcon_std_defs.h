/******************************************************************************

                               Copyright (c) 2011
                            Lantiq Deutschland GmbH

  For licensing information, see the file 'LICENSE' in the root folder of
  this software module.

******************************************************************************/

#ifndef _falcon_std_defs_h
#define _falcon_std_defs_h

#include "common.h"

#if (!defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L)) && 0
/* standard C99 types not available */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

#  if defined(__WORDSIZE) && (__WORDSIZE == 64)
typedef unsigned long int uint64_t;
#  else
typedef unsigned long long int uint64_t;
#  endif
#endif
#if !defined(__cplusplus) && !defined(bool)
#      ifndef SWIG
typedef char bool;
#    endif
#  define false 0
#  define true 1
#endif

typedef unsigned long int ulong_t;

/** This is the volatile unsigned 8-bit datatype. */
typedef volatile uint8_t  vuint8_t;
/** This is the volatile signed 8-bit datatype. */
typedef volatile int8_t   vint8_t;
/** This is the volatile unsigned 16-bit datatype. */
typedef volatile uint16_t vuint16_t;
/** This is the volatile signed 16-bit datatype. */
typedef volatile int16_t  vint16_t;
/** This is the volatile unsigned 32-bit datatype. */
typedef volatile uint32_t vuint32_t;
/** This is the volatile signed 32-bit datatype. */
typedef volatile int32_t  vint32_t;
/** This is the volatile unsigned 64-bit datatype. */
typedef volatile uint64_t vuint64_t;

#ifdef __cplusplus
#  ifndef EXTERN_C_BEGIN
/** Extern C block begin macro */
#     define EXTERN_C_BEGIN extern "C" {
#  endif
#  ifndef EXTERN_C_END
/** Extern C block end macro */
#     define EXTERN_C_END }
#  endif
#else
#  ifndef EXTERN_C_BEGIN
/** Extern C block begin macro */
#     define EXTERN_C_BEGIN
#  endif
#  ifndef EXTERN_C_END
/** Extern C block end macro */
#     define EXTERN_C_END
#  endif
#endif

#endif
