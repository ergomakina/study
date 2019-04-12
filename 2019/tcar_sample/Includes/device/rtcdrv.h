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

#ifndef __RTCDRV_H__
#define __RTCDRV_H__

#include <device/common.h>
#include <tmpm440_rtc.h>

/* RTCデバイス名 */
#define	RTC_DEVNM	"CLOCK"

typedef enum {
	/* 一般属性 */
	DN_CKEVENT	= TDN_EVENT,	/* 事象通知用メッセージバッファID変更／参照 */
	
	/* RTC専用属性 */
	DN_CKTIME	= -100,		/* クロック時間（時分秒） */
	DN_CKDATE	= -101,		/* クロック日付（年月日） */
	DN_CKALARM	= -102,		/* アラーム時刻（日時分） */
	DN_CKMODE	= -103,		/* 動作モード */
	DN_CKHDRPNT	= -104		/* アラーム通知用割込みハンドラポインタ */
} RTCDataNo;

typedef struct {
	UB	HourMode;		/* 24時モード12時モード選択 */
	UB	Hour;			/* 時 */
	UB	AmPm;			/* 12時モードのときの午前午後 */
	UB	Min;			/* 分 */
	UB	Sec;			/* 秒 */
} RtcTime;

typedef struct {
	UB	LeapYear;		/* うるう年 */
	UB	Year;			/* 年 */
	UB	Month;			/* 月 */
	UB	Date;			/* 日 */
	UB	Day;			/* 曜日 */
} RtcDate;

typedef struct {
	UB	Date;			/* 日 */
	UB	Day;			/* 曜日 */
	UB	Hour;			/* 時 */
	UB	AmPm;			/* 12時モードのときの午前午後*/
	UB	Min;			/* 分 */
} RtcAlarm;

typedef struct {
	UB	Clock;			/* クロックの動作開始／停止 */
	UB	Alarm;			/* アラームの動作開始／停止*/
} RtcMode;

IMPORT	void	(*RtcFunc)(); 		/* アラーム割込みハンドラへのポインタ */


IMPORT	ID	rtc_mbfid;		/* 事象通知用メッセージバッファID格納用 */

IMPORT	ER	RtcDrv( INT ac, UB *av[] );		/* rtcデバイスドライバSDI登録 */
IMPORT	ER	RtcDrvEnd( INT ac, UB *av[] );	/* rtcデバイスドライバ抹消 */

#endif	/* __RTCDRV_H__ */
