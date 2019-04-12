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
 *    Modified by UC Technology at 2014/13/19.
 *    Modifications: Adapted to the FM4.
 *    Modified by UC Technology at 2014/05/09.
 *    Modifications: Adapted to the TMPM369-SK.
 *    Modified by UC Technology at 2014/06/06.
 *    Modifications: Adapted to the RX.
 *    Modified by UC Technology at 2015/01/20.
 *    Modified by UC Technology at 2015/06/04.
 *    Modifications: Adapted to the SK-FM4-176L-S6E2CC-ETH.
 *    Modified by UC Technology at 2015/06/16.
 *    Modifications: Adapted to the SK-PIC32MX.
 *    Modified by UC Technology at 2015/06/26.
 *    Modifications: Adapted to the SK-FM0-100L-S6E1B8.
 *    Modified by UC Technology at 2015/07/28.
 *    Modified by Imagination Technologies on 2015/10/23 for PIC32MZ.
 *    Modifications: Adapted to the EBD-TMPM46BF10FG.
 *    Modified by UC Technology at 2016/03/23.
 *    Modifications: Adapted to the TMPM367.
 *    Modified by UC Technology at 2016/06/24.
 *
 *    UCT micro T-Kernel Version 2.00.16
 *    Copyright (c) 2011-2016 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	@(#)sysinfo_common.h (sys)
 *
 *	System shared information  
 */

#ifndef __SYS_SYSINFO_COMMON_H__
#define __SYS_SYSINFO_COMMON_H__

#ifdef APP_AT91
#  include <sys/sysdepend/app_at91/sysinfo_depend.h>
#endif

#ifdef APP_H8S2212
#  include <sys/sysdepend/app_h8s2212/sysinfo_depend.h>
#endif

#ifdef TWR_K40X256
#  include <sys/sysdepend/twr_k40x256/sysinfo_depend.h>
#endif

#ifdef TWR_K60N512
#  include <sys/sysdepend/twr_k60n512/sysinfo_depend.h>
#endif

#ifdef TWR_K60F120M
#  include <sys/sysdepend/twr_k60f120m/sysinfo_depend.h>
#endif

#ifdef TWR_K60D100M
#  include <sys/sysdepend/twr_k60d100m/sysinfo_depend.h>
#endif

#ifdef TWR_K70F120M
#  include <sys/sysdepend/twr_k70f120m/sysinfo_depend.h>
#endif

#ifdef FRDM_K64F
#  include <sys/sysdepend/frdm_k64f/sysinfo_depend.h>
#endif

#ifdef EVAL_STM3221G
#  include <sys/sysdepend/eval_stm3221g/sysinfo_depend.h>
#endif

#ifdef EVAL_STM32437I
#  include <sys/sysdepend/eval_stm32437i/sysinfo_depend.h>
#endif

#ifdef EVAL2_STM32439I
#  include <sys/sysdepend/eval2_stm32439i/sysinfo_depend.h>
#endif

#ifdef MCB_M362
#  include <sys/sysdepend/mcb_m362/sysinfo_depend.h>
#endif

#ifdef SK_M369
#  include <sys/sysdepend/sk_m369/sysinfo_depend.h>
#endif

#ifdef IOTE_M367
#  include <sys/sysdepend/iote_m367/sysinfo_depend.h>
#endif

#ifdef EBD_M440
#  include <sys/sysdepend/ebd_m440/sysinfo_depend.h>
#endif

#ifdef EBD_TMPM46BF10FG
#  include <sys/sysdepend/ebd_tmpm46bf10fg/sysinfo_depend.h>
#endif

#ifdef SK_M440
#  include <sys/sysdepend/sk_m440/sysinfo_depend.h>
#endif

#ifdef MCB_MB9BF500
#  include <sys/sysdepend/mcb_mb9bf500/sysinfo_depend.h>
#endif

#ifdef MCB_MB9AFB44
#  include <sys/sysdepend/mcb_mb9afb44/sysinfo_depend.h>
#endif

#ifdef MCB_MB9AF156M
#  include <sys/sysdepend/mcb_mb9af156m/sysinfo_depend.h>
#endif

#ifdef APP_MB9AF312K
#  include <sys/sysdepend/app_mb9af312k/sysinfo_depend.h>
#endif

#ifdef SKFM4_MB9BF568R
#  include <sys/sysdepend/skfm4_mb9bf568r/sysinfo_depend.h>
#endif

#ifdef SKFM4_S6E2CC
#  include <sys/sysdepend/skfm4_s6e2cc/sysinfo_depend.h>
#endif

#ifdef SKFM0_S6E1B8
#  include <sys/sysdepend/skfm0_s6e1b8/sysinfo_depend.h>
#endif

#ifdef ASURA_RX62N
#  include <sys/sysdepend/asura_rx62n/sysinfo_depend.h>
#endif

#ifdef AP_RX62N
#  include <sys/sysdepend/ap_rx62n/sysinfo_depend.h>
#endif

#ifdef HSB_RX62N
#  include <sys/sysdepend/hsb_rx62n/sysinfo_depend.h>
#endif

#ifdef FRK_RX62N
#  include <sys/sysdepend/frk_rx62n/sysinfo_depend.h>
#endif

#ifdef GR_RX63N
#  include <sys/sysdepend/gr_rx63n/sysinfo_depend.h>
#endif

#ifdef AP_RX63N
#  include <sys/sysdepend/ap_rx63n/sysinfo_depend.h>
#endif

#ifdef FE_RX2108
#  include <sys/sysdepend/fe_rx2108/sysinfo_depend.h>
#endif

#ifdef SK_PIC32MX
#  include <sys/sysdepend/sk_pic32mx/sysinfo_depend.h>
#endif

#ifdef SK_PIC32MZ
#  include <sys/sysdepend/sk_pic32mz/sysinfo_depend.h>
#endif

#endif /* __SYS_SYSINFO_COMMON_H__ */
