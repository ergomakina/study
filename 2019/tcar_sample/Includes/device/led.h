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
 * led.h
 *
 * LED (ヘッドライト・ウィンカー) ドライバ
 */

#ifndef __DEVICE_LED_H__
#define __DEVICE_LED_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ヘッドライトを初期化する
 */
IMPORT ER headlight_init(void);

/*
 * ヘッドライトの表示状態を設定する
 *
 * unit: 0 = 左, 1 = 右
 * color: 色 (0xRRGGBB)
 * period: 0: 点滅なし, 1〜255: 点滅間隔 (1/24 秒単位)
 * duty: 点滅のデューティー比 (1/256 単位, period = 0 の時は意味を持たない)
 */
IMPORT ER headlight_set_led(INT unit, UW color, INT period, INT duty);

/*
 * ウィンカーを初期化する
 */
IMPORT ER blinker_init(void);

/*
 * ウィンカーの表示状態を設定する
 *
 * unit: 0 = 左, 1 = 右
 * on: TRUE = 点灯, FALSE = 消灯
 */
IMPORT ER blinker_set_led(INT unit, BOOL on);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_LED_H__ */
