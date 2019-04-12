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
 * range.h
 *
 * 赤外線距離センサー ドライバ
 */

#ifndef __DEVICE_RANGE_H__
#define __DEVICE_RANGE_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 距離センサーの初期化
 */
IMPORT ER range_init(void);

/*
 * 前方障害物までの距離を測定する
 *
 * 戻り値 >= 0 : 前方障害物までの距離 (単位: cm)
 *	   <  0 : エラーコード
 */
IMPORT INT range_get_distance(void);

/*
 * 距離センサーの生の値を取得
 */
IMPORT ER range_get_raw(H *raw);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_RANGE_H__ */
