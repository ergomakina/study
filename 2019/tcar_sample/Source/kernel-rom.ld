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
 *    Modifications: Adapted to the TMPM362.
 *    Modified by UC Technology at 2014/01/24.
 *    Modified by UC Technology at 2015/06/04.
 *
 *    UCT micro T-Kernel Version 2.00.12
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *  kernel-rom.lnk (sysmain, m367)
 *	linker script (ROM)
 */

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x80000 /* 512K */
	RAM (rwx) : ORIGIN = 0x20000800, LENGTH = 0x1F800 /* 126K */
}

SECTIONS {
	.text 0x00000000 : {
		__vector_org = .;
		KEEP(*(.vector))
		__start = .;
		*(.text)
		*(.text.*)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(0x10);
	} =0
	. = ALIGN(4);
	__data_org = .;
	vector 0x20000800 (NOLOAD) : {
		__vector_start = .;
		KEEP(*(.data_vector))
		__vector_end = .;
	}
	.data __vector_end : AT(__data_org) {
		__data_start = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		__data_end = .;
	}
	.bss ALIGN(4) (NOLOAD) : {
		__bss_start = .;
		PROVIDE (__noinit_start = .);
		*(.noinit)
		PROVIDE (__noinit_end = .);
		*(.bss)
		*(.bss.*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end = .;
		__end = .;
	}
}

