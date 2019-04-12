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
 * road.h
 *
 * 路面センサー (フォトセンサー) ドライバ
 */

#ifndef __DEVICE_ROAD_H__
#define __DEVICE_ROAD_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ROAD_INT_BLACK   1 /* 黒 */
#define ROAD_INT_WHITE   2 /* 白 */
#define ROAD_INT_TOGGLE  3 /* 黒および白 */

/*
 * 路面センサーの初期化
 */
IMPORT ER road_init(void);

/*
 * 路面センサーの割込み許可
 *
 * unit : 0=左, 1=右
 * mode : 割込みモード (ROAD_INT_xxx)
 * f : TRUE=現在の状態に応じてすぐハンドラを呼び出す
 * handler : ハンドラ
 */
IMPORT ER road_interrupt_enable(INT unit, UINT mode, BOOL f, void (*handler)(INT unit, UINT mode));

/*
 * 路面センサーの割込み禁止
 */
IMPORT ER road_interrupt_disable(INT unit);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_ROAD_H__ */
