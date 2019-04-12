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
 *    Modifications: Adapted to the micro T-Kernel 2.0
 *    Modified by UC Technology at 2013/11/12.
 *    Modified by UC Technology at 2014/06/16.
 *    Modified by UC Technology at 2015/06/04.
 *
 *    UCT micro T-Kernel Version 2.00.12
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	asm_depend.h
 *
 *	Assembler Macro
 */

#ifndef __TK_CORE_ASM_DEPEND_H__
#define __TK_CORE_ASM_DEPEND_H__

#if defined(__GNUC__)
#define LABEL(x)		x##:
#define RESET_HDR		Csym(Reset_Handler)
#define _VECTOR_ENTRY(name)	.word	name
#define _WEAK_ENTRY(name)	.weak	name

#elif defined(__IASMARM__)
#define LABEL(x)		x
#define RESET_HDR		__iar_program_start
#define _VECTOR_ENTRY(name)	DCD	name
#define _WEAK_ENTRY(name)	PUBWEAK	name

#elif defined(__CC_ARM)
#define LABEL(x)		x
#define RESET_HDR		Reset_Handler
#define _VECTOR_ENTRY(name)	DCD	name
#define _WEAK_ENTRY(name)	EXPORT	name	[WEAK]
#endif

/* ------------------------------------------------------------------------ */
/*
 *	Exception restore
 */

/*
 * Exception return
 */
#if defined(__GNUC__)
.macro EXC_RETURN
	bx	lr
.endm
#elif defined(__IASMARM__)
 MACRO EXC_RETURN
	THUMB
	bx	lr
 ENDM
#elif defined(__CC_ARM)
	MACRO
	EXC_RETURN
	THUMB
	bx	lr
 	MEND
#endif

/* ------------------------------------------------------------------------ */
#endif /* __TK_CORE_ASM_DEPEND_H__ */
