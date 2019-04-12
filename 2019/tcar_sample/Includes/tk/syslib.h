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
 *    Modified by UC Technology at 2013/12/25.
 *    Modified by UC Technology at 2014/02/28.
 *    Modified by UC Technology at 2015/06/04.
 *
 *    UCT micro T-Kernel Version 2.00.12
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	@(#)syslib.h
 *
 *	System Library
 */

#ifndef __TK_SYSLIB_H__
#define __TK_SYSLIB_H__

#include <basic.h>
#include <tk/typedef.h>

#include <tk/sysdepend/syslib_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Wait
 */
IMPORT void WaitUsec( UW usec );	/* micro second wait */
IMPORT void WaitNsec( UW nsec );	/* nano second wait */

#ifdef __cplusplus
}
#endif
#endif /* __TK_SYSLIB_H__ */
