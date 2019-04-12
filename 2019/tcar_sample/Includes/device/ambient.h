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
 * ambient.h
 * 環境センサ (アナログ) ドライバ
 */

#ifndef __DEVICE_AMBIENT_H__
#define __DEVICE_AMBIENT_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	struct {
		H raw; /* ADC 出力値 */
		INT adj; /* 補正値 */
	} c[2];
} ambient_calib_comp_t;

typedef struct {
	ambient_calib_comp_t temperature;
	ambient_calib_comp_t brightness;
} ambient_calib_t;

/*
 * 環境センサの初期化
 */
IMPORT ER ambient_init(void);

/*
 * キャリブレーションのパラメータ設定
 */
IMPORT ER ambient_set_calibration(const ambient_calib_t *param);

/*
 * 温度の読み取り
 *
 * *temperature : 温度 (単位は1/10℃; 23.4℃ならば234を返す)
 */
IMPORT ER ambient_get_temperature(INT *temperature);

/*
 * 照度の読み取り
 *
 * *brightness : 明るさ (単位はルクス)
 */
IMPORT ER ambient_get_brightness(INT *brightness);

/*
 * 温度センサー、照度センサーの生の値を取得
 */
IMPORT ER ambient_get_raw(H *raw);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_AMBIENT_H__ */
