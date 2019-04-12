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
 *    Modified by UC Technology at 2011/07/29.
 *    Modified by UC Technology at 2012/02/17.
 *    Modified by UC Technology at 2014/06/12.
 *    Modified by UC Technology at 2015/06/04.
 *
 *    UCT micro T-Kernel Version 2.00.12
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	machine_depend.h
 *
 *	Machine type definition (system dependent)
 */

#ifndef __SYS_CORE_MACHINE_DEPEND_H__
#define __SYS_CORE_MACHINE_DEPEND_H__

/*
 * CPU_xxxx		CPU type
 * ALLOW_MISALIGN	1 if access to misalignment data is allowed 
 * BIGENDIAN		1 if big endian 
 * VIRTUAL_ADDRESS	1 if virtual memory 
 * ALLOCA_NOSPT		1 if alloca() is not supported 
 */

/* ----- T-Engine Appliance ARM Cortex-M3 definition ----- */

#define CPU_ARMV7_M		1
#define CPU_ARM_CORTEX_M3	1
#define ALLOW_MISALIGN		0
#define VIRTUAL_ADDRESS		0
#define ALLOCA_NOSPT		0
#define INT_BITWIDTH		32

/*
 * Endianness
 */
#if defined(__GNUC__)
#  if !defined(BIGENDIAN)
#    define BIGENDIAN		0	/* Default (Little Endian) */
#  endif
#elif defined(__IASMARM__) || defined(__ICCARM__)
#  if __LITTLE_ENDIAN__ == 0	/* __LITTLE_ENDIAN__ is defined by EWARM */
#    undef  BIGENDIAN
#    define BIGENDIAN		1	/* Big Endian */
#  elif __LITTLE_ENDIAN__ == 1
#    undef  BIGENDIAN
#    define BIGENDIAN		0	/* Little Endian */
#  endif
#elif defined(__CC_ARM)
#  if defined(__BIG_ENDIAN)	/* __BIG_ENDIAN is defined by MDK-ARM */
#    undef  BIGENDIAN
#    define BIGENDIAN		1	/* Big Endian */
#  else
#    undef  BIGENDIAN
#    define BIGENDIAN		0	/* Little Endian */
#  endif
#endif

#endif /* __SYS_CORE_MACHINE_DEPEND_H__ */
