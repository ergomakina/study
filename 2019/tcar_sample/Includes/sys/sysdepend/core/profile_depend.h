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
 *	profile_depend.h
 *
 *	Select CPU Core
 */

#ifndef __SYS_SELECT_PROFILE_DEPEND_H__
#define __SYS_SELECT_PROFILE_DEPEND_H__

#if	CPU_CORE_CM3
#include <sys/sysdepend/core/cm3/profile_depend.h>
#elif	(CPU_CORE_CM4 || CPU_CORE_CM4F)
#include <sys/sysdepend/core/cm4/profile_depend.h>
#elif	(CPU_CORE_CM0PLUS)
#include <sys/sysdepend/core/cm0plus/profile_depend.h>
#elif	(CPU_CORE_RX600)
#include <sys/sysdepend/core/rx600/profile_depend.h>
#elif	(CPU_CORE_RX200)
#include <sys/sysdepend/core/rx200/profile_depend.h>
#elif	(CPU_CORE_MIPS32)
#include <sys/sysdepend/core/mips32/profile_depend.h>
#else
#error	Please define CPU_CORE_[CORE] in <include/sys/sysdepend/[TARGET]/profile_depend.h>.
#endif

#endif /* __SYS_SELECT_PROFILE_DEPEND_H__ */
