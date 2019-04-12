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
 * joystick.h
 * アナログ ジョイスティック ドライバ
 */

#ifndef __DEVICE_JOYSTICK_H__
#define __DEVICE_JOYSTICK_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	H x; /* x 軸方向の値 (-100:左最大, 0:中央, 100:右最大) */
	H y; /* y 軸方向の値 (-100:後ろ最大, 0:中央, 100:前最大) */
} joystick_status_t;

typedef struct {
	H min; /* 最小位置とみなす ADC 出力値 */
	H neutral_min; /* 中央位置とみなす ADC 出力値の最小 */
	H neutral_max; /* 中央位置とみなす ADC 出力値の最大 */
	H max; /* 最大位置とみなす ADC 出力値 */
} joystick_calib_comp_t;

typedef struct {
	joystick_calib_comp_t x; /* x 軸方向の補正 */
	joystick_calib_comp_t y; /* y 軸方向の補正 */
} joystick_calib_t;

/*
 * ジョイスティックの初期化
 */
IMPORT ER joystick_init(void);

/*
 * キャリブレーションのパラメータ設定
 */
IMPORT ER joystick_set_calibration(const joystick_calib_t *param);

/*
 * ジョイスティックの状態取得
 */
IMPORT ER joystick_get_status(joystick_status_t *status);

/*
 * ジョイスティックの生の値を取得
 */
IMPORT ER joystick_get_raw(H *raw);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_JOYSTICK_H__ */
