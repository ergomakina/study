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
 * gpiodrv.h
 * GPIO ドライバ
 */

#ifndef __DEVICE_GPIODRV2_H__
#define __DEVICE_GPIODRV2_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ピンの割り当て */
typedef struct {
#if IOTE_M367
	UINT gp_h:4; // GPIO (Pmn) のポート m (A=0, B=1, ...)
	UINT gp_l:3; // GPIO (Pmn) の番号 n

	UINT an_f:1; // アナログ入力の割り当ての有無 (1:あり, 0:なし)
	UINT an_m:1; // アナログ入力 (AINmn) のポート m (A=0, B=1)
	UINT an_n:2; // アナログ入力 (AINmn) の番号 n

	UINT pm_f:1; // PMD の割り当ての有無 (1:あり, 0:なし)
	UINT pm_h:1; // PMD の番号 (U,V,W=0, X,Y,Z=1)
	UINT pm_l:2; // PMD の番号 (U,X=0, V,Y=1, W,Z=2)

	UINT it_f:1; // 割込みの割り当ての有無 (1:あり, 0:なし)
	UINT it_n:4; // 割込み (INTn) の番号 n
#elif TCAR_S6E1B8
	UINT gp_h:4; // GPIO (Pn) の番号 n の上位
	UINT gp_l:4; // GPIO (Pn) の番号 n の下位

	UINT an_f:1; // アナログ入力の割り当ての有無 (1:あり, 0:なし)
	UINT an_n:7; // アナログ入力 (ANn) の番号 n

	UINT tm_f:1; // タイマーの割り当ての有無 (1:あり, 0:なし)
	UINT tm_n:6; // タイマー (TIOAn_m) の番号 n
	UINT tm_m:2; // タイマー (TIOAn_m) の番号 m

	UINT it_f:1; // 割込みの割り当ての有無 (1:あり, 0:なし)
	UINT it_n:6; // 割込み (INTn_m) の番号 n
	UINT it_m:2; // 割込み (INTn_m) の番号 m
#endif
} gpio_pin_t;

/* 割込みのモード */
typedef enum {
	gpio_int_edge_high = 1, /* 立ち上がりエッジ (0→1) */
	gpio_int_edge_low = 2, /* 立ち下がりエッジ (1→0) */
	gpio_int_edge_toggle = 3, /* 両エッジ (0→1, 1→0) */
} gpio_int_mode_t;

/*
 * GPIO の初期化
 * opt: 1: 割込みを使用する
 */
IMPORT ER gpio_init(UINT opt);

/*
 * ピンを GPIO 入力に設定する
 */
IMPORT ER gpio_conf_in(const gpio_pin_t *pin);

/*
 * ピンを GPIO 出力に設定する
 */
IMPORT ER gpio_conf_out(const gpio_pin_t *pin);

/*
 * ピンを A/D 変換に設定する
 */
IMPORT ER gpio_conf_adc(const gpio_pin_t *pin);

/*
 * ピンを PWM 出力に設定する
 */
IMPORT ER gpio_conf_pwm(const gpio_pin_t *pin);

/*
 * GPIO 入力値を取得する
 */
IMPORT ER gpio_get_in(const gpio_pin_t *pin, BOOL *val);

/*
 * GPIO 出力値を設定する
 */
IMPORT ER gpio_set_out(const gpio_pin_t *pin, BOOL val);

/*
 * 割込み設定
 */
IMPORT ER gpio_set_int(const gpio_pin_t *pin, gpio_int_mode_t mode, INT arg, void (*hdr)(INT arg, BOOL val));

/*
 * 割込み許可
 * f: TRUE=現在の状態に応じてすぐハンドラを呼び出す
 */
IMPORT ER gpio_ena_int(const gpio_pin_t *pin, BOOL f);

/*
 * 割込み禁止
 */
IMPORT ER gpio_dis_int(const gpio_pin_t *pin);

/*
 * PWM 出力
 *
 * period : パルスの周期 [マイクロ秒]
 * duty : パルスの1の幅 [マイクロ秒]
 */
IMPORT ER gpio_set_pwm(const gpio_pin_t *pin, INT period, INT duty);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_GPIODRV2_H__ */
