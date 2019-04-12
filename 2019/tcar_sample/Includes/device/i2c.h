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
 *	i2c.h
 *
 *	I2C (master) ドライバ
 */

#ifndef	__DEVICE_I2C_H__
#define	__DEVICE_I2C_H__

#include <basic.h>
#include <tk/syscall.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
	I2C 入出力

	I2C デバイスに対し、データの送受信を行う。

		ch:	使用 I2C チャネル (0 を指定のこと)
		cmddat:	コマンド/送受信データを格納する領域の先頭ポインタ
		words:	コマンド/送受信データのワード数
		xwords:	成功したコマンド/送受信データのワード数
			(NULL の場合は格納しない)

		戻り値:	E_OK もしくはエラー

	割り込みハンドラ、もしくは割り込みが禁止された状態から呼び出しては
	ならない。

	コマンド/送受信データは、以下のように記述する。

	例1)	1バイトのデータを送信する場合
		{
			I2C_START   | (address << 1) | 0x00,	// R/W# = 0
			I2C_SEND    | I2C_TOPDATA  | I2C_LASTDATA | txdata0,
			I2C_STOP,
		}

		送信するデータは、I2C_SEND を指定したワードの下位 8bit に
		格納しておく。

	例2)	複数バイトのデータを送信する場合
		{
			I2C_START   | (address << 1) | 0x00,	// R/W# = 0
			I2C_SEND    | I2C_TOPDATA  | txdata0,
			I2C_SEND    |                txdata1
				:
			I2C_SEND    | I2C_LASTDATA | txdataN,
			I2C_STOP,
		}

	例3)	送受信の切り替えを伴う場合
		{
			I2C_START   | (address << 1) | 0x00,	// R/W# = 0
			I2C_SEND    | I2C_TOPDATA  | I2C_LASTDATA | txdata0,
			I2C_RESTART | (address << 1) | 0x01,	// R/W# = 1
			I2C_RECV    | I2C_TOPDATA,		// rxdata0
			I2C_RECV,				// rxdata1
				:
			I2C_RECV    | I2C_LASTDATA,		// rxdataN
			I2C_STOP,
		}

		受信したデータは、I2C_RECV を指定したワードの下位 8bit に
		格納される (上位 8bit は不変)。

	コマンド/送受信データの最終ワードは、必ず I2C_STOP を記述すること。

	転送中にエラーが発生した場合は、ストップコンディションを自動的に
	発生させる。
*/
IMPORT ER i2cxfer(W ch, UH *cmddat, W words, W *xwords);

#define	I2C_RESTART	(3 << 14)	// リスタートコンディションを送信
#define	I2C_START	(2 << 14)	// スタートコンディションを送信
#define	I2C_STOP	(1 << 14)	// ストップコンディションを送信
#define	I2C_SEND	(1 << 13)	// データを送信
#define	I2C_RECV	(1 << 12)	// データを受信
#define	I2C_TOPDATA	(1 << 11)	// 送受信データの先頭
#define	I2C_LASTDATA	(1 << 10)	// 送受信データの末端

IMPORT ER i2c_init(W ch);

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_I2C_H__ */
