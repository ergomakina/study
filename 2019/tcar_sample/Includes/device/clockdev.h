/*
 *----------------------------------------------------------------------
 *    UCT micro T-Kernel Version 2.00.12
 *
 *    Copyright (c) 2011-2015 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 *
 *    Modified by UC Technology at 2015/06/04.
 *
 *----------------------------------------------------------------------
 */

#ifndef __DEVICE_CLOCKDEV_H__
#define __DEVICE_CLOCKDEV_H__

#include <basic.h>

#ifdef __cplusplus
extern "C" {
#endif

#define	RTC_DEVNM		"CLOCK"

/* 属性データ */
/* CLOCKデータ番号 */
typedef enum {
	/* Common atr. */
	DN_CKEVENT = TDN_EVENT,
	/* original atr. */
	DN_CKDATETIME = (-100),
	DN_CKAUTOPWON = (-101),
	/* h/w */
	DN_CKREGISTER = (-200)
} ClockDataNo;

/* 現在時刻の設定／取得 */
typedef struct {
	W d_year;		/* offset from 1900 */
	W d_month;		/* month(1 to 12) */
	W d_day;		/* day(1 to 31) */
	W d_hour;		/* hour(0 to 23) */
	W d_min;		/* minute(0 to 59) */
	W d_sec;		/* second(0 to 59) */
	W d_week;		/* week of year(not use) */
	W d_wday;		/* day of week(0 to 6, 0 is SUN) */
	W d_days;		/* day of year(not use) */
} DATE_TIM;

/* 不揮発性レジスタの書き込み／読み出し */
typedef struct {
	W nreg; 		/* number of the registers */
	struct ck_reg {
		W regno;	/* register number */
		UW data;	/* data for the register */
	} c[1];
} CK_REGS;

typedef	T_DEVEVT_ID	ClockEvt;

IMPORT	ER	rtcDrvEntry( void );
IMPORT	ID	CLOCK_mbfid;

#ifdef __cplusplus
}
#endif
#endif /* __DEVICE_CLOCKDEV_H__ */
