/* @@LICENSE@@ */

/*
 * libfixpt.h
 * 固定小数点演算ライブラリ
 */

#ifndef __LIBFIXPT_H__
#define __LIBFIXPT_H__

#ifdef __cplusplus
extern "C" {
#endif

#define FX_FRAC_BITS 14 /* 固定小数点数の小数部のビット幅 */

typedef int fx_frac_t; /* 固定小数点 (0x4000 倍) */

typedef short fx_angle_t; /* 角度 (1/10 単位) */

/* 固定小数点の乗算 */
extern fx_frac_t fx_mul(fx_frac_t, fx_frac_t);

/* 固定小数点の除算 */
extern fx_frac_t fx_div(fx_frac_t, fx_frac_t);

/* 2 のべき乗の近似値 */
extern fx_frac_t fx_exp2(fx_frac_t x);

/* cos の近似値 */
extern fx_frac_t fx_cos(fx_angle_t);

/* sin の近似値 */
extern fx_frac_t fx_sin(fx_angle_t);

/* atan2 の近似値 */
extern fx_angle_t fx_atan2(fx_frac_t, fx_frac_t);

#ifdef __cplusplus
}
#endif
#endif /* __LIBFIXPT_H__ */
