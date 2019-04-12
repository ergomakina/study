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
 *	syslib_depend.h
 *
 *	micro T-Kernel Cortex-M3 Library
 */

#ifndef __TK_CORE_SYSLIB_DEPEND_H__
#define __TK_CORE_SYSLIB_DEPEND_H__

#include <tk/errno.h>
#include <tk/sysdef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * CPU interrupt control
 *	As armv7-m architecture does not support disable interrupt in
 *	xpsr register, we have to raise the excution priority to 
 *	that the interrupt group have. Write the BASEPRI to implement 
 *	disint and enaint.
 */
IMPORT UINT disint( void );
IMPORT UINT enaint( UINT intsts );
IMPORT UINT get_basepri( void );
#define DI(intsts)	( (intsts) = disint() )
#define EI(intsts)	( enaint(intsts) )
#define isDI(intsts)	( (intsts) != 0 )

/*
 * Convert to interrupt definition number
 *
 * For backward compatibility.
 * 	INTVEC has been obsoleted since micro T-Kernel 2.0.
 */
#define DINTNO(intvec)	(intvec)

#define INTLEVEL_DI	(0)
#define INTLEVEL_EI	(255)

/*
 * Interrupt priority grouping
 *
 *	PRIGROUP in the AIRCR register determins the split of group
 *	priority from subpriority. PRIGROUP is initialized to 3 ('011'
 *	in binary) in the boot sequence.
 */
#define INTPRI_GROUP(pri, subpri)	(((pri) << (8-INTPRI_BITWIDTH)) | (subpri))

/*
 * Set Interrupt Mask Level in CPU
 */
IMPORT void SetCpuIntLevel( INT level );

/*
 * Get Interrupt Mask Level in CPU
 */
IMPORT INT GetCpuIntLevel( void );

/*
 * Interrupt enable
 *	Enable the interrupt specified by 'intno.'
 */
IMPORT void EnableInt( UINT intno, INT level );

/*
 * Interrupt disable
 *	Disable the interrupt specified by 'intno.'
 */
IMPORT void DisableInt( UINT intno );

/*
 * Clear interrupt
 *
 *	Clear the state that the specified interrupt has been
 *	asserted. 
 *
 *	We just clear the pending state from the specified interrupt.
 *	Because the processor automatically removes the pending state
 *	from the interrupt when it enters the interrupt service
 *	routine, and removes the active state from the interrupt when
 *	it returns from the interrupt service routine.
 */
#define ClearInt(intno) ClearPendingInt(intno)

/*
 * Issue EOI to Interrupt Controller.
 */
#define EndOfInt(intno)

/*
 * Check active state
 *	Current active state for the associated interrupt
 */
IMPORT BOOL CheckInt( UINT intno );

/* ------------------------------------------------------------------------ */
/*
 * Interrupt Controller functions for Cortex-M3.
 */

/*
 * Set-Pending
 *  Pends the associated interrupt under software control.
 */
IMPORT void SetPendingInt( UINT intno );

/*
 * Clear-Pending
 *	Un-pends the associated interrupt under software control.
 */
IMPORT void ClearPendingInt( UINT intno );

/* ------------------------------------------------------------------------ */

/*
 * I/O port access
 *	Only memory mapped I/O for Arm
 */
Inline void out_w( UW port, UW data )
{
	*(_UW*)port = data;
}
Inline void out_h( UW port, UH data )
{
	*(_UH*)port = data;
}
Inline void out_b( UW port, UB data )
{
	*(_UB*)port = data;
}

Inline UW in_w( UW port )
{
	return *(_UW*)port;
}
Inline UH in_h( UW port )
{
	return *(_UH*)port;
}
Inline UB in_b( UW port )
{
	return *(_UB*)port;
}

#ifdef __cplusplus
}
#endif
#endif /* __TK_CORE_SYSLIB_DEPEND_H__ */
