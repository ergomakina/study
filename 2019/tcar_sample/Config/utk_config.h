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
 *    Modified by UC Technology at 2014/03/20.
 *    Modifications: Adapted to the RX
 *    Modified by UC Technology at 2014/11/21.
 *    Modifications: Adapted to the FRDM-K64F
 *    Modified by UC Technology at 2015/02/24.
 *    Modified by UC Technology at 2015/06/04.
 *    Modifications: Adapted to the SK-FM4-176L-S6E2CC-ETH.
 *    Modified by UC Technology at 2015/06/16.
 *    Modifications: Adapted to the SK-FM0-100L-S6E1B8.
 *    Modified by UC Technology at 2015/07/28.
 *    Modified by Imagination Technologies on 2015/10/23 for PIC32MZ.
 *    Modifications: Adapted to the EBDTMPM46BF10FG EVAL BD.
 *    Modified by UC Technology at 2016/03/23.
 *    Modifications: Adapted to the TMPM367.
 *    Modified by UC Technology at 2016/06/24.
 *
 *    UCT micro T-Kernel Version 2.00.16
 *    Copyright (c) 2011-2016 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	utk_config.h
 *	System Configuration Definition
 */

#ifndef _UTK_CONFIG_H_
#define _UTK_CONFIG_H_

#include "config.h"

#ifdef APP_H8S2212
#include "sysdepend/app_h8s2212/utk_config_depend.h"
#endif

#ifdef APP_AT91
#include "sysdepend/app_at91/utk_config_depend.h"
#endif

#ifdef TWR_K40X256
#include "sysdepend/twr_k40x256/utk_config_depend.h"
#endif

#ifdef TWR_K60N512
#include "sysdepend/twr_k60n512/utk_config_depend.h"
#endif

#ifdef TWR_K60F120M
#include "sysdepend/twr_k60f120m/utk_config_depend.h"
#endif

#ifdef TWR_K60D100M
#include "sysdepend/twr_k60d100m/utk_config_depend.h"
#endif

#ifdef TWR_K70F120M
#include "sysdepend/twr_k70f120m/utk_config_depend.h"
#endif

#ifdef FRDM_K64F
#include "sysdepend/frdm_k64f/utk_config_depend.h"
#endif

#ifdef EVAL_STM3221G
#include "sysdepend/eval_stm3221g/utk_config_depend.h"
#endif

#ifdef EVAL_STM32437I
#include "sysdepend/eval_stm32437i/utk_config_depend.h"
#endif

#ifdef EVAL2_STM32439I
#include "sysdepend/eval2_stm32439i/utk_config_depend.h"
#endif

#ifdef MCB_M362
#include "sysdepend/mcb_m362/utk_config_depend.h"
#endif

#ifdef SK_M369
#include "sysdepend/sk_m369/utk_config_depend.h"
#endif

#ifdef IOTE_M367
#include "sysdepend/iote_m367/utk_config_depend.h"
#endif

#ifdef EBD_M440
#include "sysdepend/ebd_m440/utk_config_depend.h"
#endif

#ifdef EBD_TMPM46BF10FG
#include "sysdepend/ebd_tmpm46bf10fg/utk_config_depend.h"
#endif

#ifdef SK_M440
#include "sysdepend/sk_m440/utk_config_depend.h"
#endif

#ifdef MCB_MB9BF500
#include "sysdepend/mcb_mb9bf500/utk_config_depend.h"
#endif

#ifdef MCB_MB9AFB44
#include "sysdepend/mcb_mb9afb44/utk_config_depend.h"
#endif

#ifdef MCB_MB9AF156M
#include "sysdepend/mcb_mb9af156m/utk_config_depend.h"
#endif

#ifdef APP_MB9AF312K
#include "sysdepend/app_mb9af312k/utk_config_depend.h"
#endif

#ifdef SKFM4_MB9BF568R
#include "sysdepend/skfm4_mb9bf568r/utk_config_depend.h"
#endif

#ifdef SKFM4_S6E2CC
#include "sysdepend/skfm4_s6e2cc/utk_config_depend.h"
#endif

#ifdef SKFM0_S6E1B8
#include "sysdepend/skfm0_s6e1b8/utk_config_depend.h"
#endif

#ifdef ASURA_RX62N
#include "sysdepend/asura_rx62n/utk_config_depend.h"
#endif

#ifdef AP_RX62N
#include "sysdepend/ap_rx62n/utk_config_depend.h"
#endif

#ifdef HSB_RX62N
#include "sysdepend/hsb_rx62n/utk_config_depend.h"
#endif

#ifdef FRK_RX62N
#include "sysdepend/frk_rx62n/utk_config_depend.h"
#endif

#ifdef GR_RX63N
#include "sysdepend/gr_rx63n/utk_config_depend.h"
#endif

#ifdef AP_RX63N
#include "sysdepend/ap_rx63n/utk_config_depend.h"
#endif

#ifdef FE_RX2108
#include "sysdepend/fe_rx2108/utk_config_depend.h"
#endif

#ifdef SK_PIC32MX
#include "sysdepend/sk_pic32mx/utk_config_depend.h"
#endif

#ifdef SK_PIC32MZ
#include "sysdepend/sk_pic32mz/utk_config_depend.h"
#endif

#include "utk_config_func.h"

#if !USE_TRAP && !(USE_DBGSPT && USE_HOOK_TRACE)
#include "tksvcproxy.h"
#include "tdsvcproxy.h"
#endif

#endif /* _UTK_CONFIG_H_ */
