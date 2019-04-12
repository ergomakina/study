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
 *    Copyright (c) 2013-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	@(#)stddef.h
 *
 *	C language: common definitions 
 */

#ifndef __STDDEF_H__
#define __STDDEF_H__

#include <stdtype.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int		ptrdiff_t;

#if defined(__GNUC__)
#ifndef _WINT_T
#define _WINT_T

#ifndef __WINT_TYPE__
#define __WINT_TYPE__ unsigned int
#endif
typedef __WINT_TYPE__ wint_t;
#endif
#endif

#ifndef __STDDEF_DECLS		/* KEIL uVision4 isn't used */ 

#if !defined(_SIZE_T) && !defined(_SIZET)
#ifdef	__size_t
#define _SIZE_T
#define _SIZET
typedef __size_t	size_t;
#undef	__size_t
#endif
#endif /* !defined(_SIZE_T) && !defined(_SIZET) */

#ifndef	_WCHART
#ifdef	__wchar_t
#define _WCHART
typedef __wchar_t	wchar_t;
#undef	__wchar_t
#endif
#endif /* #ifndef _WCHART */

#endif		/* #ifndef __STDDEF_DECLS */ 

#define offsetof(type, member)	( (size_t)(&((type *)0)->member) )

#ifndef NULL
#define NULL	0
#endif /* #ifndef NULL */

#ifdef __cplusplus
}
#endif
#endif /* __STDDEF_H__ */
