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
 *    Modifications: Adapted to the FRDM-K64F.
 *    Modified by UC Technology at 2015/02/24.
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
 *	@(#)machine_common.h (sys)
 *
 *	Machine type definition
 */

#ifndef __SYS_MACHINE_COMMON_H__
#define __SYS_MACHINE_COMMON_H__

#ifdef _APP_AT91_
#  include <sys/sysdepend/app_at91/machine_depend.h>
#endif

#ifdef _APP_H8S2212_
#  include <sys/sysdepend/app_h8s2212/machine_depend.h>
#endif

#ifdef _TWR_K40X256_
#  include <sys/sysdepend/twr_k40x256/machine_depend.h>
#endif

#ifdef _TWR_K60N512_
#  include <sys/sysdepend/twr_k60n512/machine_depend.h>
#endif

#ifdef _TWR_K60F120M_
#  include <sys/sysdepend/twr_k60f120m/machine_depend.h>
#endif

#ifdef _TWR_K60D100M_
#  include <sys/sysdepend/twr_k60d100m/machine_depend.h>
#endif

#ifdef _TWR_K70F120M_
#  include <sys/sysdepend/twr_k70f120m/machine_depend.h>
#endif

#ifdef _FRDM_K64F_
#  include <sys/sysdepend/frdm_k64f/machine_depend.h>
#endif

#ifdef _EVAL_STM3221G_
#  include <sys/sysdepend/eval_stm3221g/machine_depend.h>
#endif

#ifdef _EVAL_STM32437I_
#  include <sys/sysdepend/eval_stm32437i/machine_depend.h>
#endif

#ifdef _EVAL2_STM32439I_
#  include <sys/sysdepend/eval2_stm32439i/machine_depend.h>
#endif

#ifdef _MCB_M362_
#  include <sys/sysdepend/mcb_m362/machine_depend.h>
#endif

#ifdef _SK_M369_
#  include <sys/sysdepend/sk_m369/machine_depend.h>
#endif

#ifdef _IOTE_M367_
#  include <sys/sysdepend/iote_m367/machine_depend.h>
#endif

#ifdef _EBD_M440_
#  include <sys/sysdepend/ebd_m440/machine_depend.h>
#endif

#ifdef _EBD_TMPM46BF10FG_
#  include <sys/sysdepend/ebd_tmpm46bf10fg/machine_depend.h>
#endif

#ifdef _SK_M440_
#  include <sys/sysdepend/sk_m440/machine_depend.h>
#endif

#ifdef _MCB_MB9BF500_
#  include <sys/sysdepend/mcb_mb9bf500/machine_depend.h>
#endif

#ifdef _MCB_MB9AFB44_
#  include <sys/sysdepend/mcb_mb9afb44/machine_depend.h>
#endif

#ifdef _MCB_MB9AF156M_
#  include <sys/sysdepend/mcb_mb9af156m/machine_depend.h>
#endif

#ifdef _APP_MB9AF312K_
#  include <sys/sysdepend/app_mb9af312k/machine_depend.h>
#endif

#ifdef _SKFM4_MB9BF568R_
#  include <sys/sysdepend/skfm4_mb9bf568r/machine_depend.h>
#endif

#ifdef _SKFM4_S6E2CC_
#  include <sys/sysdepend/skfm4_s6e2cc/machine_depend.h>
#endif

#ifdef _SKFM0_S6E1B8_
#  include <sys/sysdepend/skfm0_s6e1b8/machine_depend.h>
#endif

#ifdef _ASURA_RX62N_
#  include <sys/sysdepend/asura_rx62n/machine_depend.h>
#endif

#ifdef _AP_RX62N_
#  include <sys/sysdepend/ap_rx62n/machine_depend.h>
#endif

#ifdef _HSB_RX62N_
#  include <sys/sysdepend/hsb_rx62n/machine_depend.h>
#endif

#ifdef _FRK_RX62N_
#  include <sys/sysdepend/frk_rx62n/machine_depend.h>
#endif

#ifdef _GR_RX63N_
#  include <sys/sysdepend/gr_rx63n/machine_depend.h>
#endif

#ifdef _AP_RX63N_
#  include <sys/sysdepend/ap_rx63n/machine_depend.h>
#endif

#ifdef _FE_RX2108_
#  include <sys/sysdepend/fe_rx2108/machine_depend.h>
#endif

#ifdef _SK_PIC32MX_
#  include <sys/sysdepend/sk_pic32mx/machine_depend.h>
#endif

#ifdef _SK_PIC32MZ_
#  include <sys/sysdepend/sk_pic32mz/machine_depend.h>
#endif

#endif /* __SYS_MACHINE_COMMON_H__ */
