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
 *    Modifications: Adapted to the MCBTMPM362 EVAL BD.
 *    Modified by UC Technology at 2012/01/31.
 *    Modified by UC Technology at 2014/02/05.
 *    Modified by UC Technology at 2014/06/09.
 *    Modified by UC Technology at 2015/06/04.
 *    Modifications: Adapted to the TMPM367.
 *    Modified by UC Technology at 2016/06/24.
 *
 *    UCT micro T-Kernel Version 2.00.12
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	utk_config_depend.h (TMPM367)
 *	System Configuration Definition
 */


/* RAMINFO */
#define SYSTEMAREA_TOP	0x20000800	/* RAM system area top */
					/* 0x20000000-0x200007FF:BackUp RAM(2K) */
#define SYSTEMAREA_END	0x20020000	/* RAM system area end */

/* User definition */
#define RI_USERAREA_TOP	0x20000000	/* RAM user area top */
#define RI_USERINIT	NULL		/* User initialization program */

/* SYSCONF */
#define CFN_TIMER_PERIOD	10
#define CFN_MAX_TSKID		32
#define CFN_MAX_SEMID		16
#define CFN_MAX_FLGID		16
#define CFN_MAX_MBXID		8
#define CFN_MAX_MTXID		2
#define CFN_MAX_MBFID		8
#define CFN_MAX_PORID		4
#define CFN_MAX_MPLID		2
#define CFN_MAX_MPFID		8
#define CFN_MAX_CYCID		4
#define CFN_MAX_ALMID		8
#define CFN_MAX_SSYID		4
#define CFN_MAX_SSYPRI		16

#define CFN_MAX_REGDEV		(8)
#define CFN_MAX_OPNDEV		(16)
#define CFN_MAX_REQDEV		(16)
#define CFN_DEVT_MBFSZ0		(-1)
#define CFN_DEVT_MBFSZ1		(-1)

#define CFN_VER_MAKER		0x011D
#define CFN_VER_PRID		0
#define CFN_VER_MAJOR		2
#define CFN_VER_MINOR		0
#define CFN_VER_SPVER		(0x6000 | (CFN_VER_MAJOR << 8) | CFN_VER_MINOR)
#define CFN_VER_PRVER		((CFN_VER_MAJOR << 8) | CFN_VER_MINOR)
#define CFN_VER_PRNO1		0
#define CFN_VER_PRNO2		0
#define CFN_VER_PRNO3		0
#define CFN_VER_PRNO4		0

#define CFN_REALMEMEND		((void *)0x20020000)

/*
 * Use zero-clear bss section
 */
#define USE_NOINIT		(0)

/*
 * Stack size for each mode
 */
#define EXC_STACK_SIZE		2048
#if defined(DEBUG)
#define	TMP_STACK_SIZE		(256)
#else
#define	TMP_STACK_SIZE		(128)
#endif
#define USR_STACK_SIZE		0	/* not used */

#define EXCEPTION_STACK_TOP     INTERNAL_RAM_END

/*
 * Use dynamic memory allocation
 */
#define USE_IMALLOC		(1)

/*
 * Use program trace function (in debugger support)
 */
#define USE_HOOK_TRACE		(0)

/*
 * Use clean-up sequence
 */
#define USE_CLEANUP		(1)


/*
 * Use high level programming language support routine
 */
#define USE_HLL_INTHDR		(1)

/*
 * Use ARM SP_process register
 */
#define USE_PROCESS_SP		(0)

/*
 * Use static interrupt vector table
 */
#define USE_STATIC_IVT		(0)

/*
 * Use __user_initial_stackheap
 */
#define USE_INITIAL_HEAP	(1)

