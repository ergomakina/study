/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2011 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.01
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2011/07/29.
 *
 *----------------------------------------------------------------------
 *    Modified by UC Technology at 2016/09/30.
 *
 *    UCT micro T-Kernel 2.0
 *    Copyright (c) 2016 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	inittask_def.c
 *	Initial task definition
 */

#include "inittask_def.h"

IMPORT void knl_init_task(void);

#if !USE_IMALLOC
INT	init_task_stack[INITTASK_STKSZ/sizeof(INT)];
#endif

/*
 * Initial task creation parameter
 */
EXPORT const T_CTSK knl_c_init_task = {
	(void *)INITTASK_EXINF,		/* exinf */
#if USE_IMALLOC
	INITTASK_TSKATR,		/* tskatr */
#else
	INITTASK_TSKATR|TA_USERBUF,	/* tskatr */
#endif
	(FP)&knl_init_task,		/* task */
	INITTASK_ITSKPRI,		/* itskpri */
	INITTASK_STKSZ,			/* stksz */
#if USE_OBJECT_NAME
	INITTASK_DSNAME,		/* dsname */
#endif
#if USE_IMALLOC
	INITTASK_STACK,			/* bufptr */
#else
	init_task_stack,		/* bufptr */
#endif
};
