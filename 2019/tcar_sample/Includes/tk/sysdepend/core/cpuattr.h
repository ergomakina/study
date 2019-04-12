/*
 *----------------------------------------------------------------------
 *    UCT micro T-Kernel Version 2.00.14
 *
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 *
 *    Released by UC Technology (http://www.uctec.com/) at 2014/06/17.
 *    Modified by UC Technology at 2015/06/04.
 *    Modifications: Adapted to the SK-PIC32MX.
 *    Modified by UC Technology at 2015/06/26.
 *    Modifications: Adapted to the SK-FM0-100L-S6E1B8.
 *    Modified by UC Technology at 2015/07/28.
 *
 *----------------------------------------------------------------------
 */

/*
 *	cpuattr.h
 *
 *	Select CPU Core
 */

#ifndef __TK_SELECT_CPUATTR_H__
#define __TK_SELECT_CPUATTR_H__

#if	CPU_CORE_CM3
#include <tk/sysdepend/core/cm3/cpuattr.h>
#elif	(CPU_CORE_CM4 ||CPU_CORE_CM4F)
#include <tk/sysdepend/core/cm4/cpuattr.h>
#elif	(CPU_CORE_CM0PLUS)
#include <tk/sysdepend/core/cm0plus/cpuattr.h>
#elif	(CPU_CORE_RX600)
#include <tk/sysdepend/core/RX600/cpuattr.h>
#elif	(CPU_CORE_RX200)
#include <tk/sysdepend/core/RX200/cpuattr.h>
#elif	(CPU_CORE_MIPS32)
#include <tk/sysdepend/core/mips32/cpuattr.h>
#else
#error	Please define CPU_CORE_[CORE] in <include/sys/sysdepend/[TARGET]/cpuattr.h>.
#endif

#endif /* __TK_SELECT_CPUATTR_H__ */
