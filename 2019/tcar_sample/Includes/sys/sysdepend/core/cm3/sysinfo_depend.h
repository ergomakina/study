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
 *    Modifications: Adapted to the TWR-K60N512.
 *    Modified by UC Technology at 2011/07/29.
 *    Modifications: Adapted to the TWR-K60N512-KEIL.
 *    Modified by UC Technology at 2012/02/17.
 *
 *    UCT micro T-Kernel Version 2.00.12-KEIL Version 1.00.00
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	@(#)sysinfo_depend.h (sys/core/cm3)
 *
 *	System common information  
 */

#ifndef __SYS_CORE_SYSINFO_DEPEND_H__
#define __SYS_CORE_SYSINFO_DEPEND_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _in_asm_source_

IMPORT	FP	knl_intvec[];
IMPORT	W	knl_taskindp;

#endif /* _in_asm_source_ */

#ifdef __cplusplus
}
#endif
#endif /* __SYS_CORE_SYSINFO_DEPEND_H__ */
