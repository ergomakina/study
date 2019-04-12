/*
 *----------------------------------------------------------------------
 *    UCT micro T-Kernel Version 2.00.12
 *
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 *
 *    Modified by UC Technology at 2015/06/04.
 *
 *----------------------------------------------------------------------
 */

#ifndef __IODRV_H__
#define __IODRV_H__

#include <basic.h>

/* P1A を IRQ_IN2 として利用(6LBR用) */
#define USE_P1A_AS_IRQOUT

/* 入力用に用いるポート */
#define IO_P10 (1U << 0x0)
#define IO_P1A (1U << 0xa)

/* 出力用に用いるポート */
#define IO_P3D (1U << 0xd)
#define IO_P3E (1U << 0xe)
#define IO_P3C (1U << 0xc)
#define IO_P3F (1U << 0xf)

IMPORT ER io_port_init( UW analogbits );
IMPORT void io_port_output( UW setbits, UW clearbits );
IMPORT UW io_port_input( void );

Inline void io_p3d_output( BOOL val )
{
	if (val) io_port_output(IO_P3D, 0); else io_port_output(0, IO_P3D);
}
Inline void io_p3e_output( BOOL val )
{
	if (val) io_port_output(IO_P3E, 0); else io_port_output(0, IO_P3E);
}
Inline void io_p3c_output( BOOL val )
{
	if (val) io_port_output(IO_P3C, 0); else io_port_output(0, IO_P3C);
}
Inline void io_p3f_output( BOOL val )
{
	if (val) io_port_output(IO_P3F, 0); else io_port_output(0, IO_P3F);
}

#define io_p10_input() (io_port_input() & IO_P10)

#ifdef USE_P1A_AS_IRQOUT
Inline void io_p1a_output( BOOL val )
{
	if (val) io_port_output(IO_P1A, 0); else io_port_output(0, IO_P1A);
}
#else
#define io_p1a_input() (io_port_input() & IO_P1A)
#endif

IMPORT ER adc_init( void );
IMPORT ER adc_start( void );
IMPORT UH adc_result( void );

#endif /* __IODRV_H__ */
