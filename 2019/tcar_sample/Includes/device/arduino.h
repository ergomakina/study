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
 * arduino.h
 *
 * Arduino I/F ドライバ
 */

#ifndef __DEVICE_ARDUINO_H__
#define __DEVICE_ARDUINO_H__

#include <basic.h>
#include <tk/typedef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    PIN_D0 = 0, // デジタルピン D0
    PIN_D1 = 1, // デジタルピン D1
    PIN_D2 = 2, // デジタルピン D2
    PIN_D3 = 3, // デジタルピン D3
    PIN_D4 = 4, // デジタルピン D4
    PIN_D5 = 5, // デジタルピン D5
    PIN_D6 = 6, // デジタルピン D6
    PIN_D7 = 7, // デジタルピン D7
    PIN_D8 = 8, // デジタルピン D8
    PIN_D9 = 9, // デジタルピン D9
    PIN_D10 = 10, // デジタルピン D10
    PIN_D11 = 11, // デジタルピン D11
    PIN_D12 = 12, // デジタルピン D12
    PIN_D13 = 13, // デジタルピン D13
    PIN_A0 = 14, // アナログ入力ピン A0
    PIN_A1 = 15, // アナログ入力ピン A1
    PIN_A2 = 16, // アナログ入力ピン A2
    PIN_A3 = 17, // アナログ入力ピン A3
    PIN_A4 = 18, // アナログ入力ピン A4
    PIN_A5 = 19, // アナログ入力ピン A5
} arduino_pin_no_t; // ピン番号

typedef enum {
    PIN_DIGITAL_IN = 0, // デジタル入力
    PIN_DIGITAL_OUT = 1, // デジタル出力
    PIN_PWM_OUT = 2, // PWM 出力
    PIN_ANALOG_IN = 3, // アナログ入力
} arduino_pin_mode_t; // ピンのモード

typedef enum {
    INT_EDGE_HIGH = 1, /* 立ち上がりエッジ (0→1) */
    INT_EDGE_LOW = 2, /* 立ち下がりエッジ (1→0) */
    INT_EDGE_TOGGLE = 3, /* 両エッジ (0→1, 1→0) */
} arduino_int_mode_t; /* 割込みのモード */

/*
 * ドライバの初期化
 */
IMPORT ER arduino_init(void);

/*
 * ピンのモード設定
 *
 * pin : ピン番号
 * mode : ピンのモード
 */
IMPORT ER arduino_set_pin(arduino_pin_no_t pin, arduino_pin_mode_t mode);

/*
 * デジタル入力
 *
 * pin : ピン番号
 * val : 入力値が格納される
 */
IMPORT ER arduino_digital_in(arduino_pin_no_t pin, BOOL *val);

/*
 * デジタル入力の割込み設定
 *
 * pin : ピン番号
 * mode : 割込みモード
 * handler : ハンドラ
 */
IMPORT ER arduino_set_int(arduino_pin_no_t pin, arduino_int_mode_t mode, void (*handler)(arduino_pin_no_t pin, BOOL val));

/*
 * デジタル入力の割込み許可
 * f: TRUE=現在の状態に応じてすぐハンドラを呼び出す
 */
IMPORT ER arduino_ena_int(arduino_pin_no_t pin, BOOL f);

/*
 * デジタル入力の割込み禁止
 */
IMPORT ER arduino_dis_int(arduino_pin_no_t pin);

/*
 * デジタル出力
 *
 * pin : ピン番号
 * val : 出力値
 */
IMPORT ER arduino_digital_out(arduino_pin_no_t pin, BOOL val);

/*
 * PWM 出力
 *
 * pin : ピン番号
 * period : パルスの周期 [マイクロ秒]
 * duty : パルスの1の幅 [マイクロ秒]
 */
IMPORT ER arduino_pwm_out(arduino_pin_no_t pin, INT period, INT duty);

/*
 * アナログ入力
 *
 * pin : ピン番号
 * val : 入力値 (12 bit) が格納される
 */
IMPORT ER arduino_analog_in(arduino_pin_no_t pin, H *val);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_ARDUINO_H__ */
