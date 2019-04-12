/*
 *----------------------------------------------------------------------
 *    UCT micro T-Kernel 2.0
 *
 *    Copyright (c) 2016 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 *
 *    Released by UC Technology (http://www.uctec.com/) at 2016/09/30.
 *
 *----------------------------------------------------------------------
 */

/*
 * adcdrv.h
 * A/D 変換 ドライバ
 */

#ifndef __DEVICE_ADCDRV2_H__
#define __DEVICE_ADCDRV2_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ADC の初期化
 */
IMPORT ER adc_init(void);

/*
 * ADC 出力値を取得する
 */
#if TCAR_S6E1B8
IMPORT ER adc_get_ad(H *dst, INT n, UW mask);
#endif
#if IOTE_M367
IMPORT ER adc_get_ad(H *dst, INT m, INT k, INT n);
#endif

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_ADCDRV2_H__ */
