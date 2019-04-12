/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 2.0 Software Package
 *
 *    Copyright (C) 2006-2014 by Ken Sakamura.
 *    This software is distributed under the T-License 2.0.
 *----------------------------------------------------------------------
 *
 *    Released by T-Engine Forum(http://www.t-engine.org/) at 2014/09/01.
 *
 *----------------------------------------------------------------------
 *    Modifications: Adapted to the TMPM369-SK.
 *    Modified by UC Technology at 2014/06/06.
 *    Modified by UC Technology at 2014/06/11.
 *    Modified by UC Technology at 2014/06/12.
 *    Modified by UC Technology at 2014/06/16.
 *    Modified by UC Technology at 2015/06/04.
 *    Modifications: Adapted to the TMPM367.
 *    Modified by UC Technology at 2016/06/24.
 *
 *    UCT micro T-Kernel Version 2.00.18
 *    Copyright (c) 2014-2016 UC Technology. All Rights Reserved.
 *----------------------------------------------------------------------
 */

/*
 *	sysdef_depend.h
 *
 *	Definition about TMPM367FDFG
 *
 *	Included also from assembler program.
 */

#ifndef __TK_SYSDEF_DEPEND_H__
#define __TK_SYSDEF_DEPEND_H__

#include <tk/sysdepend/core/sysdef_depend.h>

/*
 * System control registers.
 */
#define	TX03_PERIPH_BASE	0x40000000	/* ペリフェラルレジスタベースアドレス */

/*
 * 入出力ポート関連レジスタ定義
 */
/* ポート毎のレジスタベースアドレス */
#define	TX03_PORTA_BASE		(TX03_PERIPH_BASE + 0x000C0000UL)
#define	TX03_PORTB_BASE		(TX03_PERIPH_BASE + 0x000C0100UL)
#define	TX03_PORTE_BASE		(TX03_PERIPH_BASE + 0x000C0400UL)
#define	TX03_PORTF_BASE		(TX03_PERIPH_BASE + 0x000C0500UL)
#define	TX03_PORTG_BASE		(TX03_PERIPH_BASE + 0x000C0600UL)
#define	TX03_PORTH_BASE		(TX03_PERIPH_BASE + 0x000C0700UL)
#define	TX03_PORTI_BASE		(TX03_PERIPH_BASE + 0x000C0800UL)
#define	TX03_PORTK_BASE		(TX03_PERIPH_BASE + 0x000C0A00UL)
#define	TX03_PORTL_BASE		(TX03_PERIPH_BASE + 0x000C0B00UL)

#define	PIO_DATA(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x00))	/* データレジスタ */
#define	PIO_CR(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x04))	/* 出力コントロールレジスタ */
#define	PIO_FR1(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x08))	/* ファンクションレジスタ１ */
#define	PIO_FR2(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x0C))	/* ファンクションレジスタ２ */
#define	PIO_FR3(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x10))	/* ファンクションレジスタ３ */
#define	PIO_FR4(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x14))	/* ファンクションレジスタ４ */
#define	PIO_FR5(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x18))	/* ファンクションレジスタ５ */
#define	PIO_FR6(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x1C))	/* ファンクションレジスタ６ */
#define	PIO_OD(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x28))	/* オープンドレインコントロールレジスタ */
#define	PIO_PUP(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x2C))	/* プルアップコントロールレジスタ */
#define	PIO_PDN(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x30))	/* プルダウンコントロールレジスタ */
#define	PIO_IE(n)		(*(_UB*)(TX03_PORT##n##_BASE + 0x38))	/* 入力コントロールレジスタ */

/*
 * UART registers
 */
/* UART毎のベースアドレス */
#define	UART0_BASE		(TX03_PERIPH_BASE + 0x000E1000UL)	/* SIO/UART */
#define	UART1_BASE		(TX03_PERIPH_BASE + 0x000E1100UL)
#define	UART2_BASE		(TX03_PERIPH_BASE + 0x000E1200UL)
#define	UART3_BASE		(TX03_PERIPH_BASE + 0x000E1300UL)
#define	UART4_BASE		(TX03_PERIPH_BASE + 0x00048000UL)	/* UART modem */
#define	UART5_BASE		(TX03_PERIPH_BASE + 0x00049000UL)

/* SIO/UART */
#define	UART_SCxEN(p)		(*(_UB*)(uart_reg_base[p] + 0x0000))	/* イネーブルレジスタ */
#define	UART_SCxBUF(p)		(*(_UB*)(uart_reg_base[p] + 0x0004))	/* 送受信バッファレジスタ */
#define	UART_SCxCR(p)		(*(_UB*)(uart_reg_base[p] + 0x0008))	/* コントロールレジスタ */
#define	UART_SCxMOD0(p)		(*(_UB*)(uart_reg_base[p] + 0x000C))	/* モードコントロールレジスタ０ */
#define	UART_SCxBRCR(p)		(*(_UB*)(uart_reg_base[p] + 0x0010))	/* ボーレートジェネレータコントロールレジスタ */
#define	UART_SCxBRADD(p)	(*(_UB*)(uart_reg_base[p] + 0x0014))	/* ボーレートジェネレータコントロールレジスタ２ */
#define	UART_SCxMOD1(p)		(*(_UB*)(uart_reg_base[p] + 0x0018))	/* モードコントロールレジスタ１ */
#define	UART_SCxMOD2(p)		(*(_UB*)(uart_reg_base[p] + 0x001C))	/* モードコントロールレジスタ２ */
#define	UART_SCxRFC(p)		(*(_UB*)(uart_reg_base[p] + 0x0020))	/* 受信FIFOコンフィグレジスタ */
#define	UART_SCxTFC(p)		(*(_UB*)(uart_reg_base[p] + 0x0024))	/* 送信FIFOコンフィグレジスタ */
#define	UART_SCxRST(p)		(*(_UB*)(uart_reg_base[p] + 0x0028))	/* 受信FIFOステータスレジスタ */
#define	UART_SCxTST(p)		(*(_UB*)(uart_reg_base[p] + 0x002C))	/* 送信FIFOステータスレジスタ */
#define	UART_SCxFCNF(p)		(*(_UB*)(uart_reg_base[p] + 0x0030))	/* FIFOコンフィグレジスタ */

/* イネーブルレジスタ */
#define	SCxEN_SIOENA		0x00000001UL	/* SIO動作（動作） */
#define	SCxEN_SIODISA		0x00000000UL	/* SIO動作（停止） */
/* 送受信バッファレジスタ */
#define	SCxBUF_TBRB_MASK	0x000000FFUL	/* 送受信バッファマスク */
/* コントロールレジスタ */
#define	SCxCR_RB8		0x00000080UL	/* 受信データビット8 */
#define	SCxCR_EVEN		0x00000040UL	/* パリティ種別（EVEN） */
#define	SCxCR_PE		0x00000020UL	/* パリティ付加（イネーブル） */
#define	SCxCR_OERR		0x00000010UL	/* バッファオーバーランエラー */
#define	SCxCR_PERR		0x00000008UL	/* パリティエラー */
#define	SCxCR_FERR		0x00000004UL	/* フレーミングエラー */
#define	SCxCR_SCLKS		0x00000002UL	/* 入力クロックエッジ選択（非UART用） */
#define	SCxCR_IOC		0x00000001UL	/* クロック選択（非UART用） */
#define	SCxCR_ERR		(SCxCR_OERR|SCxCR_PERR|SCxCR_FERR)	/* UARTエラーマスク */
/* モードコントロールレジスタ０ */
#define	SCxMOD0_TB8		0x00000080UL	/* 送信データビット8 */
#define	SCxMOD0_CTSE		0x00000040UL	/* CTS機能制御 */
#define	SCxMOD0_RXE		0x00000020UL	/* 受信イネーブル */
#define	SCxMOD0_WU		0x00000010UL	/* ウェイクアップイネーブル */
#define	SCxMOD0_SM_MASK		0x0000000CUL	/* 転送ビット長マスク */
#define	SCxMOD0_SMIO		0x00000000UL	/* 転送ビット長IOモード（非UART） */
#define	SCxMOD0_SM7		0x00000004UL	/* 転送ビット長7ビット */
#define	SCxMOD0_SM8		0x00000008UL	/* 転送ビット長8ビット */
#define	SCxMOD0_SM9		0x0000000CUL	/* 転送ビット長9ビット */
#define	SCxMOD0_SC_MASK		0x00000003UL	/* シリアル転送クロックマスク */
#define	SCxMOD0_SC_TB		0x00000000UL	/* シリアル転送クロックTBxOUT */
#define	SCxMOD0_SC_BAUD		0x00000001UL	/* シリアル転送クロックボーレートジェネレータ */
#define	SCxMOD0_SC_FSYS		0x00000002UL	/* シリアル転送クロック内部クロック */
#define	SCxMOD0_SC_SCLK		0x00000003UL	/* シリアル転送クロック外部クロック */
/* ボーレートジェネレータコントロールレジスタ */
#define	SCxBRCR_BRADDE		0x00000040UL	/* N+16分周機能イネーブル */
#define	SCxBRCR_BRCK_MASK	0x00000030UL	/* 入力クロック選択マスク */
#define	SCxBRCR_BRCK_T01	0x00000000UL	/* 入力クロックφT1 */
#define	SCxBRCR_BRCK_T04	0x00000010UL	/* 入力クロックφT4 */
#define	SCxBRCR_BRCK_T16	0x00000020UL	/* 入力クロックφT16 */
#define	SCxBRCR_BRCK_T64	0x00000030UL	/* 入力クロックφT64 */
#define	SCxBRCR_BRS_MASK	0x0000000FUL	/* 分周値設定マスク */
/* ボーレートジェネレータコントロールレジスタ２ */
#define	SCxBRADD_BRK_MASK	0x0000000FUL	/* 分周値計算のKの値マスク */
/* モードコントロールレジスタ１ */
#define	SCxMOD1_I2SC		0x00000080UL	/* IDLEモード時動作（動作） */
#define	SCxMOD1_FDXP_MASK	0x00000060UL	/* 転送モード設定マスク（非UART用） */
#define	SCxMOD1_TXE		0x00000010UL	/* 送信イネーブル */
#define	SCxMOD1_SINT_MASK	0x0000000EUL	/* 連続転送インターバルマスク（非UART用） */
/* モードコントロールレジスタ２ */
#define	SCxMOD2_TBEMP		0x00000080UL	/* 送信バッファエンプティフラグ */
#define	SCxMOD2_RBFLL		0x00000040UL	/* 受信バッファフルフラグ */
#define	SCxMOD2_TXRUN		0x00000020UL	/* 送信動作中フラグ */
#define	SCxMOD2_SBLEN		0x00000010UL	/* ストップビット長（0：1ビット、1：2ビット） */
#define	SCxMOD2_DRCHG		0x00000008UL	/* 転送方向（0：LSBFirst=UART） */
#define	SCxMOD2_WBUF		0x00000004UL	/* ダブルバッファイネーブル */
#define	SCxMOD2_SWRST1		0x00000002UL	/* ソフトウェアリセット第１動作 */
#define	SCxMOD2_SWRST2		0x00000001UL	/* ソフトウェアリセット第２動作 */
/* 受信FIFOコンフィグレジスタ */
#define	SCxRFC_RFCS		0x00000080UL	/* 受信FIFOクリア */
#define	SCxRFC_RFIS		0x00000040UL	/* 割込み発生条件選択 */
#define	SCxRFC_RIL_MASK		0x00000003UL	/* 受信割込みが発生するFIFOのfillレベルマスク */
/* 送信FIFOコンフィグレジスタ */
#define	SCxTFC_TFCS		0x00000080UL	/* 送信FIFOクリア */
#define	SCxTFC_TFIS		0x00000040UL	/* 割込み発生条件選択 */
#define	SCxTFC_TIL_MASK		0x000000U03L	/* 送信割込みが発生するFIFOのfillレベルマスク */
/* 受信FIFOステータスレジスタ */
#define	SCxRST_ROR		0x00000080UL	/* 受信FIFOオーバーラン */
#define	SCxRST_RLVL_MASK	0x00000007UL	/* 受信FIFOのfillレベルマスク */
/* 送信FIFOステータスレジスタ */
#define	SCxTST_TUR		0x00000080UL	/* 送信FIFOアンダーラン */
#define	SCxTST_TLVL_MASK	0x00000007UL	/* 送信FIFOのfillレベルマスク */
/* FIFOコンフィグレジスタ */
#define	SCxFCNF_RFST		0x00000010UL	/* 受信FIFO使用バイト数 */
#define	SCxFCNF_TFIE		0x00000008UL	/* 送信FIFO使用時の送信割込み許可 */
#define	SCxFCNF_RFIE		0x00000004UL	/* 受信FIFO使用時の受信割込み許可 */
#define	SCxFCNF_RXTXCNT		0x00000002UL	/* RXE/TXEの自動禁止 */
#define	SCxFCNF_CNFG		0x00000001UL	/* FIFOの許可 */
#define	SCxFCNF_DISABLE		0x00000000UL	/* FIFOを使用しない */

/* UART modem */
#define	UARTxDR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0000))	/* Data register */
#define	UARTxRSR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0004))	/* Receive status register */
#define	UARTxECR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0004))	/* Error clear register */
#define	UARTxFR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0018))	/* Flag register */
#define	UARTxILPR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0020))	/* IrDA low-power counter */
#define	UARTxIBDR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0024))	/* Integer baud rate register */
#define	UARTxFBDR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0028))	/* Fractional baud rate register */
#define	UARTxLCR_H(p) 		(*(_UW*)(uart_reg_base[p] + 0x002C))	/* Line control register */
#define	UARTxCR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0030))	/* Control register */
#define	UARTxIFLS(p) 		(*(_UW*)(uart_reg_base[p] + 0x0034))	/* Interrupt FIFO level select register */
#define	UARTxIMSC(p) 		(*(_UW*)(uart_reg_base[p] + 0x0038))	/* Interrupt mask set/clear register */
#define	UARTxRIS(p) 		(*(_UW*)(uart_reg_base[p] + 0x003C))	/* Raw interrupt status register */
#define	UARTxMIS(p) 		(*(_UW*)(uart_reg_base[p] + 0x0040))	/* Masked interrupt status register */
#define	UARTxICR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0044))	/* Interrupt clear register */
#define	UARTxDMACR(p) 		(*(_UW*)(uart_reg_base[p] + 0x0048))	/* DMA control register */

#define	UARTxDR_OE		(1 << 11)	/* R オーバーランエラー */
#define	UARTxDR_BE		(1 << 10)	/* R ブレークエラー */
#define	UARTxDR_PE		(1 << 9)	/* R パリティエラー */
#define	UARTxDR_FE		(1 << 8)	/* R フレーミングエラー */
#define	UARTxDR_DATA		(0xff)		/* RW 送受信データ */

#define	UARTxRSR_OE		(1 << 3)	/* R オーバーランエラー */
#define	UARTxRSR_BE		(1 << 2)	/* R ブレークエラー */
#define	UARTxRSR_PE		(1 << 1)	/* R パリティーエラー */
#define	UARTxRSR_FE		(1 << 0)	/* R フレーミングエラー */

#define	UARTxFR_RI		(1 << 8)	/* R Link indicator */
#define	UARTxFR_TXFE		(1 << 7)	/* R 送信エンプティ */
#define	UARTxFR_RXFF		(1 << 6)	/* R 受信フル */
#define	UARTxFR_TXFF		(1 << 5)	/* R 送信フル */
#define	UARTxFR_RXFE		(1 << 4)	/* R 受信エンプティ */
#define	UARTxFR_BUSY		(1 << 3)	/* R UART busy */
#define	UARTxFR_DCD		(1 << 2)	/* R Data carrier detect */
#define	UARTxFR_DSR		(1 << 1)	/* R Data set ready */
#define	UARTxFR_CTS		(1 << 0)	/* R Clear to send */

#define	UARTxLCR_H_SPS		(1 << 7)	/* RW スティックパリティ選択 */
#define	UARTxLCR_H_WLEN(n)	(((n)-5) << 5)	/* RW ワード長 (5～8bit) */
#define	UARTxLCR_H_FEN		(1 << 4)	/* RW イネーブルFIFO */
#define	UARTxLCR_H_STP2		(1 << 3)	/* RW ストップビット選択 */
#define	UARTxLCR_H_EPS		(1 << 2)	/* RW 偶数パリティ選択 */
#define	UARTxLCR_H_PEN		(1 << 1)	/* RW パリティイネーブル */
#define	UARTxLCR_H_BRK		(1 << 0)	/* RW 送信ブレーク */

#define	UARTxCR_CTSEN		(1 << 15)	/* RW CTS ハードウェアフロー制御イネーブル */
#define	UARTxCR_RTSEN		(1 << 14)	/* RW RTS ハードウェアフロー制御イネーブル */
#define	UARTxCR_RTS		(1 << 11)	/* RW 送信要求(RTS) */
#define	UARTxCR_DTR		(1 << 10)	/* RW データ送信準備完了 (DTS) */
#define	UARTxCR_RXE		(1 << 9)	/* RW 受信イネーブル */
#define	UARTxCR_TXE		(1 << 8)	/* RW 送信イネーブル */
#define	UARTxCR_SIRLP		(1 << 2)	/* RW IrDA 　SIR 低電力モード */
#define	UARTxCR_SIREN		(1 << 1)	/* RW SIR イネーブル */
#define	UARTxCR_UARTEN		(1 << 0)	/* RW UART イネーブル */

#define	UARTxIFLS_RXIFLSEL(n)	((n) << 3)	/* RW 受信割り込み FIFO レベル選択 */
#define	UARTxIFLS_TXIFLSEL(n)	((n) << 0)	/* RW 送信割り込み FIFO レベル選択 */
#define	UARTxIFLS_1_8		0		/* FIFO 1/8 */
#define	UARTxIFLS_1_4		1		/* FIFO 1/4 */
#define	UARTxIFLS_1_2		2		/* FIFO 1/2 */
#define	UARTxIFLS_3_4		3		/* FIFO 3/4 */
#define	UARTxIFLS_7_8		4		/* FIFO 7/8 */

#define	UARTxINT_OE		(1 << 10)	/* RW オーバーランエラー割り込み */
#define	UARTxINT_BE		(1 << 9)	/* RW ブレークエラー割り込み */
#define	UARTxINT_PE		(1 << 8)	/* RW パリティーエラー割り込み */
#define	UARTxINT_FE		(1 << 7)	/* RW フレーミングエラー割り込み */
#define	UARTxINT_RT		(1 << 6)	/* RW 受信タイムアウト割り込み */
#define	UARTxINT_TX		(1 << 5)	/* RW 送信割り込み */
#define	UARTxINT_RX		(1 << 4)	/* RW 受信割り込み */
#define	UARTxINT_DSR		(1 << 3)	/* RW DSR モデム割り込み */
#define	UARTxINT_DCD		(1 << 2)	/* RW DCD モデム割り込み */
#define	UARTxINT_CTS		(1 << 1)	/* RW CTS モデム割り込み */
#define	UARTxINT_RI		(1 << 0)	/* RW RIN モデム割り込み */

#define	UARTxDMACR_DMAONERR	(1 << 2)	/* RW DMA オンエラー */
#define	UARTxDMACR_TXDMAE	(1 << 1)	/* RW 送信DMA イネーブル */
#define	UARTxDMACR_RXDMAE	(1 << 0)	/* RW 受信 DMA イネーブル */

/*
 * I2C registers
 */
#define	I2C0_BASE		(TX03_PERIPH_BASE + 0x000E0000UL)
#define	I2C1_BASE		(TX03_PERIPH_BASE + 0x000E0100UL)
#define	I2C2_BASE		(TX03_PERIPH_BASE + 0x000E0200UL)

#define	I2C_SBIxCR0		0x0000		/* RW コントロールレジスタ0 */
#define	I2C_SBIxCR1		0x0004		/* RW コントロールレジスタ1 */
#define	I2C_SBIxDBR		0x0008		/* RW データバッファレジスタ */
#define	I2C_SBIxI2CAR		0x000C		/* RW I2C バスアドレスレジスタ */
#define	I2C_SBIxCR2		0x0010		/* W  コントロールレジスタ2 */
#define	I2C_SBIxSR		0x0010		/* R  ステータスレジスタ */
#define	I2C_SBIxBR0		0x0014		/* RW ボーレートレジスタ0 */

#define	I2C_SBIxCR0_SBIEN	(1 << 7)	/* RW シリアルバスインタフェース動作 */

#define	I2C_SBIxCR1_BC(n)	((n) << 5)	/* RW 転送ビット数の選択 */
#define	I2C_SBIxCR1_ACK		(1 << 4)	/* RW ACK */
#define	I2C_SBIxCR1_SCK(n)	((n) << 0)	/* W  内部SCL 出力クロックの周波数選択 */
#define	I2C_SBIxCR1_SWRMON	(1 << 0)	/* R  ソフトウエアリセット状態モニタ */

#define	I2C_SBIxCR2_MST		(1 << 7)	/* W マスタモード/スレーブモードの選択 */
#define	I2C_SBIxCR2_TRX		(1 << 6)	/* W 送信/受信の選択 */
#define	I2C_SBIxCR2_BB		(1 << 5)	/* W スタート/ストップ状態の発生 */
#define	I2C_SBIxCR2_PIN		(1 << 4)	/* W INTSBIx 割り込み要求解除 */
#define	I2C_SBIxCR2_SBIM(n)	((n) << 2)	/* W シリアルバスインタフェースの動作モード選択 */
#define	I2C_SBIxCR2_SBIM_SIO	I2C_SBIxCR2_SBIM(1)
#define	I2C_SBIxCR2_SBIM_I2C	I2C_SBIxCR2_SBIM(2)
#define	I2C_SBIxCR2_SWRST(n)	((n) << 0)	/* W ソフトウエアリセットの発生 */

#define	I2C_SBIxSR_MST		(1 << 7)	/* R マスタ/スレーブ選択状態モニタ */
#define	I2C_SBIxSR_TRX		(1 << 6)	/* R トランスミッタ/レシーバ選択状態モニタ */
#define	I2C_SBIxSR_BB		(1 << 5)	/* R I2C バス状態モニタ */
#define	I2C_SBIxSR_PIN		(1 << 4)	/* R INTSBIx 割り込み要求状態モニタ */
#define	I2C_SBIxSR_AL		(1 << 3)	/* R アービトレーションロスト検出モニタ */
#define	I2C_SBIxSR_AAS		(1 << 2)	/* R スレーブアドレス一致検出モニタ */
#define	I2C_SBIxSR_ADO		(1 << 1)	/* R ゼネラルコール検出モニタ */
#define	I2C_SBIxSR_LRB		(1 << 0)	/* R 最終受信ビットモニタ */

#define	I2C_SBIxBR0_I2SBI	(1 << 6)	/* RW IDLE モード時の動作 */

/*
 * SSP/SPI registers
 */
#define	SSP0_BASE		(TX03_PERIPH_BASE + 0x00040000UL)
#define	SSP1_BASE		(TX03_PERIPH_BASE + 0x00041000UL)
#define	SSP2_BASE		(TX03_PERIPH_BASE + 0x00042000UL)

#define	SSPxCR0			0x0000	/* 制御レジスタ０ */
#define	SSPxCR1			0x0004	/* 制御レジスタ１ */
#define	SSPxDR			0x0008	/* 送受信データレジスタ */
#define	SSPxSR			0x000c	/* ステータスレジスタ */
#define	SSPxCPSR		0x0010	/* クロックプリスケールレジスタ */
#define	SSPxIMSC		0x0014	/* 割込許可レジスタ */
#define	SSPxRIS			0x0018	/* マスク前の割込ステータスレジスタ */
#define	SSPxMIS			0x001c	/* マスク後の割込ステータスレジスタ */
#define	SSPxICR			0x0020	/* 割込クリアレジスタ */
#define	SSPxDMACR		0x0024	/* DMA 制御レジスタ */

#define	SSPxCR0_SCR(n)		((n) << 8)	/* RW シリアルクロックレート */
#define	SSPxCR0_SPH		(1 << 7)	/* RW クロックフェーズ */
#define	SSPxCR0_SPO		(1 << 6)	/* RW クロック極性 */
#define	SSPxCR0_FRF(n)		((n) << 4)	/* RW フレームフォーマット */
#define	SSPxCR0_FRF_SPI		SSPxCR0_FRF(0)
#define	SSPxCR0_DSS(n)		((n) << 0)	/* RW データサイズ */
#define	SSPxCR0_DSS_8		SSPxCR0_DSS(7)

#define	SSPxCR1_SOD		(1 << 3)	/* RW スレーブモード出力 */
#define	SSPxCR1_MS		(1 << 2)	/* RW マスタ／スレーブ選択 */
#define	SSPxCR1_SSE		(1 << 1)	/* RW SSP 許可 */
#define	SSPxCR1_LBM		(1 << 0)	/* RW ループバック */

#define	SSPxSR_BSY		(1 << 4)	/* R- ビジー */
#define	SSPxSR_RFF		(1 << 3)	/* R- 受信 FIFO フル */
#define	SSPxSR_RNE		(1 << 2)	/* R- 受信 FIFO 空でない */
#define	SSPxSR_TNF		(1 << 1)	/* R- 送信 FIFO フルでない */
#define	SSPxSR_TFE		(1 << 0)	/* R- 送信 FIFO 空 */

#define	SSPxIM_TX		(1 << 3)	/* 送信 FIFO 割込 */
#define	SSPxIM_RX		(1 << 2)	/* 受信 FIFO 割込 */
#define	SSPxIM_RT		(1 << 1)	/* 受信タイムアウト割込 */
#define	SSPxIM_ROR		(1 << 0)	/* 受信オーバーラン割込 */

#define	SSPxDMACR_TXDMAE	(1 << 1)	/* RW 送信 DMA 許可 */
#define	SSPxDMACR_RXDMAE	(1 << 0)	/* RW 受信 DMA 許可 */

/*
 * RTC
 */
#define	RTC_BASE		(TX03_PERIPH_BASE + 0x000cc000UL)

#define	RTCSECR			(RTC_BASE + 0x0000)	/* 秒 */
#define	RTCMINR			(RTC_BASE + 0x0001)	/* 分 */
#define	RTCHOURR		(RTC_BASE + 0x0002)	/* 時 */
#define	RTCDAYR			(RTC_BASE + 0x0004)	/* 曜日 */
#define	RTCDATER		(RTC_BASE + 0x0005)	/* 日 */
#define	RTCMONTHR		(RTC_BASE + 0x0006)	/* 月 / 12H/24H 選択 */
#define	RTCYEARR		(RTC_BASE + 0x0007)	/* 年 / うるう年 */
#define	RTCPAGER		(RTC_BASE + 0x0008)	/* 制御 */
#define	RTCRESTR		(RTC_BASE + 0x000c)	/* 制御 */

#define	RTCPAGER_INTENA		0x80	/* 割込許可 */
#define	RTCPAGER_ADJUST		0x10	/* 秒補正 */
#define	RTCPAGER_ENATMR		0x08	/* 時計許可 */
#define	RTCPAGER_ENAALM		0x04	/* アラーム許可 */
#define	RTCPAGER_PAGE		0x01	/* Page1 選択 */

#define	RTCRESTR_DIS1HZ		0x80	/* 1Hz 割込禁止 */
#define	RTCRESTR_DIS16HZ	0x40	/* 16Hz 割込禁止 */
#define	RTCRESTR_RSTTMR		0x20	/* 秒カウンタリセット */
#define	RTCRESTR_RSTALM		0x10	/* アラームリセット */
#define	RTCRESTR_DIS2HZ		0x04	/* 2Hz 割込禁止 */
#define	RTCRESTR_DIS4HZ		0x02	/* 4Hz 割込禁止 */
#define	RTCRESTR_DIS8HZ		0x01	/* 8Hz 割込禁止 */
#define	RTCRESTR_DISxHZ		0xc7	/* xHz 割込すべて禁止 */

/*
 * 割込み関連定義
 */
#define	SCx_RX_IRQ_NUMBER(n)	(16 + (n)*2)	/* n=0～3 : SIO/UART */
#define	SCx_TX_IRQ_NUMBER(n)	(17 + (n)*2)
#define	UARTx_IRQ_NUMBER(n)	(24 + (n)-4)	/* n=4～5 : UART modem */
#define	SBIx_IRQ_NUMBER(n)	(26 + (n))	/* n=0～2 : I2C/SIO */
#define	SSPx_IRQ_NUMBER(n)	(29 + (n))	/* n=0〜2 : SSP/SPI */

/*
 * 割込優先度 = INTPRI_GROUP(xxx_IRQ_PRI, xxx_IRQ_SUBPRI)
 *	xxx_IRQ_PRI	0～7	0:最優先 7:最低
 *	xxx_IRQ_SUBPRI	0	無意味
 */
#define	UART_RX_IRQ_PRI		2
#define	UART_TX_IRQ_PRI		2
#define	UART_RX_IRQ_SUBPRI	0
#define	UART_TX_IRQ_SUBPRI	0

#define	I2C_IRQ_PRI		5
#define	I2C_IRQ_SUBPRI		0

#define	SSP_IRQ_PRI		6
#define	SSP_IRQ_SUBPRI		0

/* ------------------------------------------------------------------------ */

/*
 * 割込み関連レジスタ定義
 */
#define	TX03_NVIC_BASE		0xE000E000UL				/* レジスタベースアドレス */
#define	NVIC_SETENA1		(*(_UW*)(TX03_NVIC_BASE + 0x100))	/* 割り込みイネーブルセットレジスタ1 */
#define	NVIC_CLRENA1		(*(_UW*)(TX03_NVIC_BASE + 0x180))	/* 割り込みイネーブルクリアレジスタ1 */

/*
 * Clock Control
 */
#define HISPEED_CLOCK_MHz	12

#define PLL_MODE_4X		4
#define PLL_MODE_6X		6

#define	CLOCK_fPLL		(HISPEED_CLOCK_MHz * PLL_MODE_6X * 1000000)
#define	CLOCK_fc		(CLOCK_fPLL)
#define	CLOCK_fgear		(CLOCK_fc / 2)
#define	CLOCK_fsys		(CLOCK_fgear)
#define	CLOCK_fperiph		(CLOCK_fgear)
#define	CLOCK_T0		(CLOCK_fperiph)

/*
 * クロック／モード制御（CG）関連レジスタ定義
 */
#define CLKCTRL_BASE		0x400F3000
#define CLKCTRL_CGSYSCR		(*(_UW*)(CLKCTRL_BASE + 0x0000))	/* システムコントロールレジスタ */
#define CLKCTRL_CGOSCCR		(*(_UW*)(CLKCTRL_BASE + 0x0004))	/* 発振コントロールレジスタ */
#define CLKCTRL_CGSTBYCR	(*(_UW*)(CLKCTRL_BASE + 0x0008))	/* スタンバイコントロールレジスタ */
#define CLKCTRL_CGPLLSEL	(*(_UW*)(CLKCTRL_BASE + 0x000C))	/* PLLセレクトレジスタ */
#define CLKCTRL_CGCKSTP		(*(_UW*)(CLKCTRL_BASE + 0x0018))	/* ペリフェラル用クロックストップレジスタ */
#define CLKCTRL_CGPROTECT	(*(_UW*)(CLKCTRL_BASE + 0x003C))	/* プロテクトレジスタ */
#define CLKCTRL_CGIMCGA	(*(_UW*)(CLKCTRL_BASE + 0x0040))	/* 割込みモードコントロールレジスタA */
#define CLKCTRL_CGIMCGB	(*(_UW*)(CLKCTRL_BASE + 0x0044))	/* 割込みモードコントロールレジスタB */
#define CLKCTRL_CGIMCGC	(*(_UW*)(CLKCTRL_BASE + 0x0048))	/* 割込みモードコントロールレジスタC */
#define CLKCTRL_CGIMCGD	(*(_UW*)(CLKCTRL_BASE + 0x004c))	/* 割込みモードコントロールレジスタD */
#define CLKCTRL_CGICRCG	(*(_UW*)(CLKCTRL_BASE + 0x0060))	/* 割込み要求クリアレジスタ */

/* PLL Selection */
#define	CLKCTRL_CGPLLSEL_4X		0x00005A0F
#define	CLKCTRL_CGPLLSEL_6X		0x00006296

#define CLKCTRL_CGPLLSEL_PLLSEL		0x00000001

/* Oscillation control */
#define CLKCTRL_CGOSCCR_ALWAYSWRITE	0x00000030

#define CLKCTRL_CGOSCCR_WUEON		0x00000001
#define CLKCTRL_CGOSCCR_WUEF		0x00000002
#define CLKCTRL_CGOSCCR_PLLON		0x00000004
#define CLKCTRL_CGOSCCR_WUPSEL_XT1	0x00000008

#define CLKCTRL_CGOSCCR_WUPT(usec,MHz)	( (usec * MHz) >> 4 ) << 20

/* ------------------------------------------------------------------------ */

/*
 * Watchdog Timer
 */
#define WDOG_BASE		0x400F2000

#define	WDOG_WDMOD		(WDOG_BASE + 0x0000)	/* Mode Reg. */
#define	WDOG_WDCR		(WDOG_BASE + 0x0004)	/* Control Reg. */

#define	WDOG_WDMOD_WDTE		0x00000080	/* Enable */
#define	WDOG_WDCR_DISABLE	0x000000B1	/* Disable Code */

/*
 * Programmable Motor Driver
 */
#define PMD_BASE	0x400f6000
#define PMD_MTPDMDEN	(*(_UW*)(PMD_BASE + 0x00))
#define PMD_MTPDPORTMD	(*(_UW*)(PMD_BASE + 0x04))
#define PMD_MTPDMDCR	(*(_UW*)(PMD_BASE + 0x08))
#define PMD_MTPDMDCNT	(*(_UW*)(PMD_BASE + 0x10))
#define PMD_MTPDMDPRD	(*(_UW*)(PMD_BASE + 0x14))
#define PMD_MTPDCMPU	(*(_UW*)(PMD_BASE + 0x18))
#define PMD_MTPDCMPV	(*(_UW*)(PMD_BASE + 0x1c))
#define PMD_MTPDCMPW	(*(_UW*)(PMD_BASE + 0x20))
#define PMD_MTPDMDOUT	(*(_UW*)(PMD_BASE + 0x28))
#define PMD_MTPDEMGREL	(*(_UW*)(PMD_BASE + 0x30))
#define PMD_MTPDEMGCR	(*(_UW*)(PMD_BASE + 0x34))
#define PMD_MTPDEMGSTA	(*(_UW*)(PMD_BASE + 0x38))

/* ------------------------------------------------------------------------ */

/*
 * Number of Interrupt vectors
 */
#define N_INTVEC		128	/* Number of Interrupt vectors */

/*
 * The number of the implemented bit width for priority value fields.
 */
#define INTPRI_BITWIDTH		3

/*
 * Force dispatch interrupt for micro T-Kernel
 * Use any unsed intterrupt number.
 */
#define INTNO_FORCE_DISPATCH	21	/* Serial transmission (channel 2) */

/*
 * Interrupt Priority Levels
 */
#define INTPRI_MAX_EXTINT_PRI	1	/* Highest Ext. interrupt level for disint() */
#define INTPRI_SYSTICK		1	/* SysTick */
#define INTPRI_FORCE_DISPATCH	6	/* Force Dispatch */
#define INTPRI_PENDSV		7	/* PendSV */

/* ------------------------------------------------------------------------ */

#endif /* __TK_SYSDEF_DEPEND_H__ */
