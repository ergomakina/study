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

#ifndef __SDISAMPLEDEV_H__
#define __SDISAMPLEDEV_H__

#include <basic.h>
#include <device/common.h>
//#include <tmpm440_XXX.h>		/* CMSIS driver			*/

#ifdef __cplusplus
extern "C" {
#endif

/* SSデバイス名称 */
#define	SS_DEVNM	"ssname"

/* 属性データ番号 */
typedef enum {
	/* 共通属性 */
	DN_SSEVENT = TDN_EVENT,		/* RW : 事象通知用 MBF ID	*/
	/* 個別属性 */
	DN_SSATR_1 = (-100),		/* RW : 個別属性１		*/
	DN_SSATR_2 = (-101),		/* RW : 個別属性２		*/
	/* 機種依存機能 */
	DN_SSREG_1 = (-200),		/* RW : 機種依存の機能１	*/
	DN_SSREG_2 = (-201)		/* RW : 機種依存の機能２	*/
} SsDataNo;

/* 属性データ用構造体の例 */
typedef struct {			/* DN_SSATR_1 : 個別属性１	*/
	W	atr11;
	W	atr12;
	W	atr13;
	W	atr14;
} SS_ATR1;

typedef struct {			/* DN_SSATR_2 : 個別属性２	*/
	W	atr21;
	W	atr22;
	W	atr23;
	W	atr24;
} SS_ATR2;

typedef	struct {			/* 事象通知用 MBF 構造体	*/
	T_DEVEVT_ID	h;
	/* 必要なら以下にデータを追加してもよい */
} SS_MBF;

/* ユーザーアプリ用関数宣言 */
IMPORT	ER	SdiSampleDrv( INT ac, UB *av[] );	/* XxxDrv()	*/

/* ユーザーアプリ・デバイスドライバ間共通変数 */
IMPORT	ID	SS_mbfid;		/* 事象通知用 MBF ID		*/

#ifdef __cplusplus
}
#endif

#endif	/* __SDISAMPLEDEV_H__ */
