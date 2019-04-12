/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 2.0 Software Package
 *
 *    Copyright (C) 2006-2014 by Ken Sakamura.
 *    This software is distributed under the T-License 2.0.
 *----------------------------------------------------------------------
 *
 *    Released by T-Engine Forum(http://www.t-engine.org/) at 2014/09/01.
 *
 *----------------------------------------------------------------------
 *    Modifications: Adapted to the STM3221G-EVAL.
 *    Modified by UC Technology at 2011/10/28.
 *    Modifications: Adapted to the MCBTMPM362 EVAL BD.
 *    Modified by UC Technology at 2012/01/31.
 *    Modifications: Adapted to the TWR-K60N512-KEIL.
 *    Modified by UC Technology at 2012/02/17.
 *    Modifications: Adapted to the EBDTMPM440 EVAL BD.
 *    Modified by UC Technology at 2012/09/27.
 *    Modifications: Adapted to the FM3.
 *    Modified by UC Technology at 2013/01/24.
 *    Modified by UC Technology at 2013/02/28.
 *    Modified by UC Technology at 2015/06/04.
 *
 *    UCT micro T-Kernel Version 2.00.12
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	@(#)machine.h
 *
 *	Machine type definition 
 *
 *	Describes differences between platforms, such as hardware
 *	and OS. Where the source code must be differentiated
 *	according to platform, macros and other definitions given
 *	here should be used.
 *
 *	Where possible, classifications should be based on general
 *	attributes rather than the machine type. Thus, the endian,
 *	for instance, should be described as BIGENDIAN rather than
 *	using a classification based on the machine type. 
 *
 *	* Machine type definition is not used solely by the machine
 *	C language source file, so non-macro definitions are not
 *	permitted.
 */

#ifndef __MACHINE_H__
#define __MACHINE_H__

/* ===== System dependencies definitions ================================ */

#include <sys/sysdepend/machine_common.h>

/* ===== Common definitions ============================================= */

#ifndef Inline
#ifdef __cplusplus
#define Inline		inline
#elif (defined __ICCARM__)
#define Inline		inline
#elif (defined __CC_ARM)
#define Inline		static __inline
#elif (defined __RX)
#define Inline	static inline
#else
#define Inline		static __inline__
#endif
#endif

#ifndef Asm
#ifdef __GNUC__
#define Asm		__asm__ volatile
#elif  (defined __ICCARM__ | defined __CC_ARM)
#define Asm		__asm
#endif
#endif

/*
 * C symbol format 
 *	_Csym = 0	do not append _  
 *	_Csym = 1	append _  
 *
 *	* In the UNIX System V Release 4 C compiler,
 *	   _ is not appended to symbols.
 */
#if _Csym == 0
#define Csym(sym)	sym
#else
#define Csym(sym)	_##sym
#endif


/*
 * No initialization section
 */
#if (defined __GNUC__) && !(defined __XC32)
#define Noinit(decl)	decl __attribute__ ((section (".noinit")))
#elif (defined __RX)
#define Noinit(decl)	_Pragma("section _NOINIT") \
decl; \
_Pragma("section")
#else
#define Noinit(decl)	decl
#endif


#endif /* __MACHINE_H__ */
