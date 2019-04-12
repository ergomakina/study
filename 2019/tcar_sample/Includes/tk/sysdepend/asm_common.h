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
 *    Modifications: Adapted to the TWR-K60N512.
 *    Modified by UC Technology at 2011/07/29.
 *    Modifications: Adapted to the STM3221G-EVAL.
 *    Modified by UC Technology at 2011/10/28.
 *    Modifications: Adapted to the MCBTMPM362 EVAL BD.
 *    Modified by UC Technology at 2012/01/31.
 *    Modifications: Adapted to the TWR-K60N512-KEIL.
 *    Modified by UC Technology at 2012/02/17.
 *    Modifications: Adapted to the EBDTMPM440 EVAL BD.
 *    Modified by UC Technology at 2012/09/27.
 *    Modifications: Adapted to the TWR-K60F120M-KEIL.
 *    Modified by UC Technology at 2013/01/07.
 *    Modifications: Adapted to the FM3.
 *    Modified by UC Technology at 2013/01/24.
 *    Modifications: Adapted to the STM32437I-EVAL.
 *    Modified by UC Technology at 2013/12/25.
 *    Modifications: Adapted to the TMPM440-SK.
 *    Modified by UC Technology at 2014/01/23.
 *    Modifications: Adapted to the STM32439I-EVAL2.
 *    Modified by UC Technology at 2014/03/19.
 *    Modifications: Adapted to the FM4.
 *    Modified by UC Technology at 2014/05/09.
 *    Modifications: Adapted to the TMPM369-SK.
 *    Modified by UC Technology at 2014/06/06.
 *    Modifications: Adapted to the RX.
 *    Modified by UC Technology at 2015/01/16.
 *    Modifications: Adapted to the FRDM-K64F.
 *    Modified by UC Technology at 2015/02/24.
 *    Modifications: Adapted to the SK-FM4-176L-S6E2CC-ETH.
 *    Modified by UC Technology at 2015/06/16.
 *    Modifications: Adapted to the SK-PIC32MX.
 *    Modified by UC Technology at 2015/06/26.
 *    Modifications: Adapted to the SK-FM0-100L-S6E1B8.
 *    Modified by UC Technology at 2015/07/28.
 *    Modified by Inagination Technologies on 2015/10/23 for PIC32MZ.
 *    Modifications: Adapted to the EBD-TMPM46BF10FG.
 *    Modified by UC Technology at 2016/03/23.
 *    Modifications: Adapted to the TMPM367.
 *    Modified by UC Technology at 2016/06/24.
 *
 *    UCT micro T-Kernel 2.0 Version 2.00.16
 *    Copyright (c) 2011-2016 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	@(#)asm_common.h (tk)
 *
 *	Assembler Macro
 */

#ifndef __TK_ASM_COMMON_H__
#define __TK_ASM_COMMON_H__

#if APP_AT91
#  include <tk/sysdepend/app_at91/asm_depend.h>
#endif

#if APP_H8S2212
#  include <tk/sysdepend/app_h8s2212/asm_depend.h>
#endif

#if TWR_K40X256
#  include <tk/sysdepend/twr_k40x256/asm_depend.h>
#endif

#if TWR_K60N512
#  include <tk/sysdepend/twr_k60n512/asm_depend.h>
#endif

#if TWR_K60F120M
#  include <tk/sysdepend/twr_k60f120m/asm_depend.h>
#endif

#if TWR_K60D100M
#  include <tk/sysdepend/twr_k60d100m/asm_depend.h>
#endif

#if TWR_K70F120M
#  include <tk/sysdepend/twr_k70f120m/asm_depend.h>
#endif

#if FRDM_K64F
#  include <tk/sysdepend/frdm_k64f/asm_depend.h>
#endif

#if EVAL_STM3221G
#  include <tk/sysdepend/eval_stm3221g/asm_depend.h>
#endif

#if EVAL_STM32437I
#  include <tk/sysdepend/eval_stm32437i/asm_depend.h>
#endif

#if EVAL2_STM32439I
#  include <tk/sysdepend/eval2_stm32439i/asm_depend.h>
#endif

#if MCB_M362
#  include <tk/sysdepend/mcb_m362/asm_depend.h>
#endif

#if SK_M369
#  include <tk/sysdepend/sk_m369/asm_depend.h>
#endif

#if IOTE_M367
#  include <tk/sysdepend/iote_m367/asm_depend.h>
#endif

#if EBD_M440
#  include <tk/sysdepend/ebd_m440/asm_depend.h>
#endif

#if EBD_TMPM46BF10FG
#  include <tk/sysdepend/ebd_tmpm46bf10fg/asm_depend.h>
#endif

#if SK_M440
#  include <tk/sysdepend/sk_m440/asm_depend.h>
#endif

#if MCB_MB9BF500
#  include <tk/sysdepend/mcb_mb9bf500/asm_depend.h>
#endif

#if MCB_MB9AFB44
#  include <tk/sysdepend/mcb_mb9afb44/asm_depend.h>
#endif

#if MCB_MB9AF156M
#  include <tk/sysdepend/mcb_mb9af156m/asm_depend.h>
#endif

#if APP_MB9AF312K
#  include <tk/sysdepend/app_mb9af312k/asm_depend.h>
#endif

#if SKFM4_MB9BF568R
#  include <tk/sysdepend/skfm4_mb9bf568r/asm_depend.h>
#endif

#if SKFM4_S6E2CC
#  include <tk/sysdepend/skfm4_s6e2cc/asm_depend.h>
#endif

#if SKFM0_S6E1B8
#  include <tk/sysdepend/skfm0_s6e1b8/asm_depend.h>
#endif

#if ASURA_RX62N
#  include <tk/sysdepend/asura_rx62n/asm_depend.h>
#endif

#if AP_RX62N
#  include <tk/sysdepend/ap_rx62n/asm_depend.h>
#endif

#if HSB_RX62N
#  include <tk/sysdepend/hsb_rx62n/asm_depend.h>
#endif

#if GR_RX63N
#  include <tk/sysdepend/gr_rx63n/asm_depend.h>
#endif

#if AP_RX63N
#  include <tk/sysdepend/ap_rx63n/asm_depend.h>
#endif

#if FE_RX2108
#  include <tk/sysdepend/fe_rx2108/asm_depend.h>
#endif

#if SK_PIC32MX
#  include <tk/sysdepend/sk_pic32mx/asm_depend.h>
#endif

#if SK_PIC32MZ
#  include <tk/sysdepend/sk_pic32mz/asm_depend.h>
#endif

#endif /* __TK_ASM_COMMON_H__ */
