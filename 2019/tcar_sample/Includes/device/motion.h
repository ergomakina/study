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
 * motion.h
 *
 * 車体センサー (9軸センサー・モーター回転速度計測用フォトセンサー) ドライバ
 */

#ifndef __DEVICE_MOTION_H__
#define __DEVICE_MOTION_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * 地表座標: x軸: 東向き, y軸: 北向き, z軸: 天頂向き
 * 車体座標: x軸: 右向き, y軸: 前向き, z軸: 上向き
 * ピッチ: x 軸まわりの回転 (原点から x 軸方向を見て、右ねじの進む向きがプラス)
 * ロール: y 軸まわりの回転 (原点から y 軸方向を見て、右ねじの進む向きがプラス)
 * ヨー:   z 軸まわりの回転 (原点から z 軸方向を見て、右ねじの進む向きがプラス)
 */
typedef struct {
	H pitch; /* ピッチ */
	H roll; /* ロール */
	H yaw; /* ヨー */
} motion_direction_t;

typedef struct {
	struct {
		H raw; /* センサーの値 */
		INT adj; /* 補正値 */
	} c[2];
} motion_calib_comp_t;

typedef struct {
	motion_calib_comp_t acc[3]; /* 加速度センサーの補正 */
	motion_calib_comp_t gyro[3]; /* ジャイロセンサーの補正 */
	motion_calib_comp_t mag[3]; /* 地磁気センサーの補正 */
	H mag_decl; /* 地磁気の偏角 (単位: 1/10 度、西がプラス) */
	H wheel_size; /* 後輪の一周の長さ [mm] */
} motion_calib_t;

/*
 * 車体センサードライバの初期化
 */
IMPORT ER motion_init(void);

/*
 * キャリブレーションのパラメータ設定
 */
IMPORT ER motion_set_calibration(const motion_calib_t *param);

/*
 * 車体の姿勢を取得
 *
 * 地表座標をz軸、y軸、x軸の順に回転して車体座標に一致させるときの
 * ピッチ、ロール、ヨーを求める
 * 単位: [1/10 度]
 *  -900 <= ピッチ <= 900
 * -1800 <= ロール < 1800
 * -1800 <= ヨー   < 1800
 */
IMPORT ER motion_get_direction(motion_direction_t *dir);

/*
 * 車体の回転速度を取得
 *
 * 車体座標での各軸まわりの回転速度を求める (単位 [1/10 度/秒])
 */
IMPORT ER motion_get_rotation(motion_direction_t *rot);

/*
 * モータの回転速度取得 (フォトセンサー)
 *
 *  >= 0 : 速度 (対路面 [mm/秒])
 *   < 0 : エラーコード
 */
IMPORT INT motion_get_speed(void);

/*
 * 加速度センサー、ジャイロセンサー、地磁気センサーの生の値を取得
 */
IMPORT ER motion_get_raw(H *acc, H *gyro, H *mag);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_MOTION_H__ */
