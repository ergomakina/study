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
 * cruise.h
 *
 * 走行制御ドライバ (モーター回転速度制御、ステアリング制御)
 */

#ifndef __DEVICE_CRUISE_H__
#define __DEVICE_CRUISE_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	H min; /* 最小のデューティー比 (1/1024 単位) */
	H neutral; /* 中央のデューティー比 (1/1024 単位) */
	H max; /* 最大のデューティー比 (1/1024 単位) */
} cruise_calib_comp_t;

typedef struct {
	cruise_calib_comp_t speed; /* モーター回転速度制御の補正 */
	cruise_calib_comp_t steer; /* ステアリング制御の補正 */
} cruise_calib_t;

/*
 * 走行制御ドライバの初期化
 */
IMPORT ER cruise_init(void);

/*
 * キャリブレーションのパラメータ設定
 */
IMPORT ER cruise_set_calibration(const cruise_calib_t *param);

/*
 * モーター回転速度制御
 *
 * speed : モーター回転速度 (-100:後進最速, 0:停止, 100:前進最速)
 */
IMPORT ER cruise_set_speed(INT speed);

/*
 * ステアリング制御
 *
 * steer : 前輪の角度 (-100:左最大, 0:中央, 100:右最大)
 */
IMPORT ER cruise_set_steer(INT steer);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_CRUISE_H__ */
