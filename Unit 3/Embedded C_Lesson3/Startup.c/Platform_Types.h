/*
 ==========================================================================
 Name        : Platform_Types
 Author      : Mohammed Hassan
 Created on	 : 9/5/2023
 Description : Platform_Types.h
 ==========================================================================
 */

 #ifndef PLATFORM_TYPES_H
 #define PLATFORM_TYPES_H

#ifndef _bool
#define _bool unsigned char
#endif

#ifndef FALSE
#define FALSE		(boolean)false
#endif

#ifndef TRUE
#define TRUE		(boolean)true
#endif

/*--------------Symbols--------------*/
#define CPU_TYPE 		CPU_TYPE_32
#define CPU_BIT_ORDER 	MSB_FIRST
#define CPU_BYTE_ORDER 	HIGH_BYTE_FIRST

/*--------------Types--------------*/
typedef _Bool               boolean;
typedef signed char         sint8_t;
typedef unsigned char       uint8_t;
typedef char                char_t;
typedef signed short        sint16_t;
typedef unsigned short      uint16_t;
typedef signed int          sint32_t;
typedef unsigned int        uint32_t;
typedef signed long long    sint64_t;
typedef unsigned long long  uint64_t;
typedef float               float32_t;
typedef double              float64_t;

/*--------------Volatile_Types--------------*/
typedef volatile signed char         vsint8_t;
typedef volatile unsigned char       vuint8_t;
typedef volatile char                vchar_t;
typedef volatile signed short        vint16_t;
typedef volatile unsigned short      vuint16_t;
typedef volatile signed int          vint32_t;
typedef volatile unsigned int        vuint32_t;
typedef volatile signed long long    vint64_t;
typedef volatile unsigned long long  vuint64_t;

#endif
