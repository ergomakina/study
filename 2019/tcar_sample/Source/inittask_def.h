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
 *	inittask_def.h
 *	Initial task definition
 */

#ifndef _INITTASK_DEF_
#define _INITTASK_DEF_

#include <basic.h>
#include <tk/tkernel.h>
#include "utk_config.h"

/*
 * Initial task parameter
 */
#define INITTASK_EXINF		(0x0)
#define INITTASK_TSKATR		(TA_HLNG | TA_RNG0)
#define INITTASK_ITSKPRI	(1)
#define INITTASK_STKSZ		(1*1024)
#define INITTASK_DSNAME		"inittsk"
#define INITTASK_STACK		(NULL)

#endif /* _INITTASK_DEF_ */
