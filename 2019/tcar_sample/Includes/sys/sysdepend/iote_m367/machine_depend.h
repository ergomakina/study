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
 *    Modifications: Adapted to the TMPM369-SK.
 *    Modified by UC Technology at 2014/06/06.
 *    Modified by UC Technology at 2014/06/12.
 *    Modified by UC Technology at 2015/06/04.
 *    Modifications: Adapted to the TMPM367.
 *    Modified by UC Technology at 2016/06/24.
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

#ifndef __SYS_MACHINE_DEPEND_H__
#define __SYS_MACHINE_DEPEND_H__

/*
 * [TYPE]_[CPU]		TARGET BOARD
 * CPU_xxxx		CPU type
 * CPU_CORE_xxx		CPU CORE
 */

/* ----- TMPM367 (ARM Cortex-M3) definition ----- */
#undef _IOTE_M367_

#define  IOTE_M367		1
#define CPU_TMPM369FDFG		1
#define CPU_CORE_CM3		1

#include <sys/sysdepend/core/machine_depend.h>

#ifndef _Csym
#define _Csym			0
#endif

#endif /* __SYS_MACHINE_DEPEND_H__ */
