/*
 *    usermain.c (usermain)
 *    User Main
 */

#include <tk/tkernel.h>
#include <tm/tmonitor.h>
#include <libstr.h>
#include <device/gpiodrv.h>

#define PE_DATA 0x400C0400
#define PE_CR 0x400C0404

#define PA_DATA  0x400C0000
#define PACR     0x400C0004
#define PAIE     0x400C0038

#define PHCR    0x400C0704
#define PHIE    0x400C0710
#define PHCR    0x400C0738

#define MT2EN    0x400C7200 //動作許可・動作モード設定
#define MT2IGOCR 0x400C7240
#define MT2IGCR  0x400C7230
#define MT2RUN   0x400C7204 //開始1停止0
#define MT2IGRG2 0x400C7244 //OFF
#define MT2IGRG3 0x400C7248 //ON
#define MT2IGRG4 0x400C724C //周期

#define GPIO_H_BASE 0x400C0700 //GPIOポートHのベースアドレス
//GPIOポートH
#define PHCR (GPIO_H_BASE + 0x04)
#define PHFR3 (GPIO_H_BASE + 0x10)
#define PHIE (GPIO_H_BASE + 0x38)

//ADA
#define UNIT_A_BASE 0x40050000
#define ADACLK (UNIT_A_BASE+0x00)
#define ADAMOD0 (UNIT_A_BASE+0x04)
#define ADAMOD1 (UNIT_A_BASE+0x08)
#define ADAMOD2 (UNIT_A_BASE+0x0C)
#define ADAMOD3 (UNIT_A_BASE+0x10)
#define ADAMOD4 (UNIT_A_BASE+0x14)
#define ADAMOD5 (UNIT_A_BASE+0x18)
#define ADAMOD6 (UNIT_A_BASE+0x1C)
#define ADAREG00 (UNIT_A_BASE+0x34)
#define ADAREG01 (UNIT_A_BASE+0x38)
#define ADAREG02 (UNIT_A_BASE+0x3C)
#define ADAREG03 (UNIT_A_BASE+0x40)
#define ADAREG04 (UNIT_A_BASE+0x44)
#define ADAREG05 (UNIT_A_BASE+0x48)
#define ADAREG06 (UNIT_A_BASE+0x4C)
#define ADAREG07 (UNIT_A_BASE+0x50)

// 04課題３ マルチタスク
void bz_task(INT stacd, void *exinf){
  // SW3
  UW sw3;
  *(_UW*)(PACR) &= ~(1<<3); // GPIO portA
  *(_UW*)(PAIE) |= (1<<3); // GPIO portA

  *(_UW*)(PHCR) |= (1<<2);
  *(_UW*)(PHIE) &= ~(1<<2);
  *(_UW*)(PHCR) |= (1<<2);

  *(_UW*)(MT2EN) |= (1<<7|1<<0);
  *(_UW*)(MT2IGOCR) |= (1<<1);
  *(_UW*)(MT2IGOCR) &= ~(1<<5);
  *(_UW*)(MT2IGCR) &= ~(1<<6|1<<3|1<<2|1<<1|1<<0);
  *(_UW*)(MT2IGRG2) = 1;
  *(_UW*)(MT2IGRG3) = 9000;
  *(_UW*)(MT2IGRG4) = 18000;

  while (1){
    sw3 = *(_UW*)(PA_DATA) & (1<<3);
    if(sw3 == 0){
      *(_UW*)(MT2RUN) |= (1<<0 | 1<<2); //on
      tk_dly_tsk(2000);
      *(_UW*)(MT2RUN) &= ~(1<<0 | 1<<2); //off
    }
  }

  tk_ext_tsk(); //タスク終了
}
void led_task(INT stacd, void *exinf){
    //初期状態ではGPIOポートHが接続されている
    //一応...GPIOポートHの初期化
    *(_UW*)(PHFR3) |= (1<<2);
    *(_UW*)(PHIE) &= ~(1<<2);
    *(_UW*)(PHCR) |= (1<<2);

    //照度センサからの端子には、初期状態でAINA3の信号が割り当てられている
    //照度センサからの信号は、A/Dコンバータ Aユニットのアナログ入力AINA0に接続されている

    //ADAの初期化
    *(_UW*)(ADACLK) = 0x01;
    *(_UW*)(ADAMOD1) = 0x80;
    tk_dly_tsk(0.003);
    *(_UW*)(ADAMOD3) = 0x01;
    *(_UW*)(ADAMOD4) = 0x00;

    //LEDのPE3出力許可
    *(_UW*)(PE_CR) |= (1<<3);


    while(1){
        *(_UW*)(ADAMOD0) = 0x01; // A/D変換開始
        while(*(_UW*)(ADAMOD5) != 0x00){
            if(*(_UW*)(ADAMOD5) == 0x01){
                if(*(_UW*)(ADAREG00) < 1000000000){
                     *(_UW*)(PE_DATA) |= (1<<3); //high出力
                }else{
                    *(_UW*)(PE_DATA) &= ~(1<<3); //low出力
                }
            }
        }
        tk_dly_tsk(100);
    }
}

EXPORT INT usermain(void){
    T_CTSK  bz_ctsk;
    ID      bz_tskid;
    T_CTSK led_ctsk;
    ID     led_tskid;
    bz_ctsk.tskatr  = TA_HLNG | TA_RNG0;
    bz_ctsk.task = bz_task;
    bz_ctsk.itskpri = 10;
    bz_ctsk.stksz = 1024;
    led_ctsk.tskatr = TA_HLNG | TA_RNG0;
    led_ctsk.task   = led_task;
    led_ctsk.itskpri = 10;
    led_ctsk.stksz = 1024;

    led_tskid = tk_cre_tsk(&led_ctsk);
    tk_sta_tsk(led_tskid,0);
    bz_tskid = tk_cre_tsk( &bz_ctsk );
    tk_sta_tsk(bz_tskid, 0);

    tk_slp_tsk(TMO_FEVR);
    return 0;
}

// 04課題２
// void led_task(INT stacd, void *exinf){
//     //初期状態ではGPIOポートHが接続されている
//     //一応...GPIOポートHの初期化
//     *(_UW*)(PHFR3) |= (1<<2);
//     *(_UW*)(PHIE) &= ~(1<<2);
//     *(_UW*)(PHCR) |= (1<<2);

//     //照度センサからの端子には、初期状態でAINA3の信号が割り当てられている
//     //照度センサからの信号は、A/Dコンバータ Aユニットのアナログ入力AINA0に接続されている

//     //ADAの初期化
//     *(_UW*)(ADACLK) = 0x01;
//     *(_UW*)(ADAMOD1) = 0x80;
//     tk_dly_tsk(0.003);
//     *(_UW*)(ADAMOD3) = 0x01;
//     *(_UW*)(ADAMOD4) = 0x00;

//     //LEDのPE3出力許可
//     *(_UW*)(PE_CR) |= (1<<3);


//     while(1){
//         *(_UW*)(ADAMOD0) = 0x01; // A/D変換開始
//         while(*(_UW*)(ADAMOD5) != 0x00){
//             if(*(_UW*)(ADAMOD5) == 0x01){
//                 if(*(_UW*)(ADAREG00) < 1000000000){
//                      *(_UW*)(PE_DATA) |= (1<<3); //high出力
//                 }else{
//                     *(_UW*)(PE_DATA) &= ~(1<<3); //low出力
//                 }
//             }
//         }
//     }
// }

// EXPORT INT usermain(void){
//     T_CTSK led_ctsk;
//     ID     led_tskid;

//     led_ctsk.tskatr = TA_HLNG | TA_RNG0;
//     led_ctsk.task   = led_task;
//     led_ctsk.itskpri = 10;
//     led_ctsk.stksz = 1024;

//     led_tskid = tk_cre_tsk(&led_ctsk);
//     tk_sta_tsk(led_tskid,0);

//     tk_slp_tsk(TMO_FEVR);
//     return 0;
// }

// 04課題１ ブザー制御
// void bz_task(INT stacd, void *exinf){
//   // SW3
//   UW sw3;
//   *(_UW*)(PACR) &= ~(1<<3); // GPIO portA
//   *(_UW*)(PAIE) |= (1<<3); // GPIO portA

//   *(_UW*)(PHCR) |= (1<<2);
//   *(_UW*)(PHIE) &= ~(1<<2);
//   *(_UW*)(PHCR) |= (1<<2);

//   *(_UW*)(MT2EN) |= (1<<7|1<<0);
//   *(_UW*)(MT2IGOCR) |= (1<<1);
//   *(_UW*)(MT2IGOCR) &= ~(1<<5);
//   *(_UW*)(MT2IGCR) &= ~(1<<6|1<<3|1<<2|1<<1|1<<0);
//   *(_UW*)(MT2IGRG2) = 1;
//   *(_UW*)(MT2IGRG3) = 9000;
//   *(_UW*)(MT2IGRG4) = 18000;

//   while (1){
//     sw3 = *(_UW*)(PA_DATA) & (1<<3);
//     if(sw3 == 0){
//       *(_UW*)(MT2RUN) |= (1<<0 | 1<<2); //on
//       tk_dly_tsk(2000);
//       *(_UW*)(MT2RUN) &= ~(1<<0 | 1<<2); //off
//     }
//   }

//   tk_ext_tsk(); //タスク終了
// }
// EXPORT INT usermain( void ){
//   T_CTSK  bz_ctsk;
//   ID      bz_tskid;

//   bz_ctsk.tskatr  = TA_HLNG | TA_RNG0;
//   bz_ctsk.task = bz_task;
//   bz_ctsk.itskpri = 10; //タスク優先度
//   bz_ctsk.stksz = 1024;

//   bz_tskid = tk_cre_tsk( &bz_ctsk );
//   tk_sta_tsk(bz_tskid, 0);

//   tk_slp_tsk(TMO_FEVR);
//   return 0;
// }

// 03課題２
//  EXPORT INT usermain( void ){
//   *(_UW*)(PHFR3) |= (1<<2);
//   *(_UW*)(PHIE) &= ~(1<<2);
//   *(_UW*)(PHCR) |= (1<<2);
//   *(_UW*)(MT2EN) |= (1<<7|1<<0);
//   *(_UW*)(MT2IGOCR) |= (1<<1); 
//   *(_UW*)(MT2IGOCR) &= ~(1<<5); 
//   *(_UW*)(MT2IGCR) &= ~(1<<6|1<<3|1<<2|1<<1|1<<0);
//   *(_UW*)(MT2IGRG2) = 1;
//   *(_UW*)(MT2IGRG3) = 9000;
//   *(_UW*)(MT2IGRG4) = 17027;
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2);

//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 15335;
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2); 
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 13643;
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2); 
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 12887; 
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2); 
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 11483; 
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2); 
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 10223;
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2); 
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 9107;
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2); 
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   *(_UW*)(MT2IGRG4) = 8603;
//   *(_UW*)(MT2RUN) |= (1<<0|1<<2);
//   tk_dly_tsk(500);
//   *(_UW*)(MT2RUN) &= ~(1<<0|1<<2);
//   return 0;
// }

// 03課題１
// EXPORT INT usermain( void ){
//   *(_UW*)(PHCR) |= (1<<2);
//   *(_UW*)(PHIE) &= ~(1<<2);
//   *(_UW*)(PHCR) |= (1<<2);
//   *(_UW*)(MT2EN) |= (1<<7|1<<0);
//   *(_UW*)(MT2IGOCR) |= (1<<1);
//   *(_UW*)(MT2IGOCR) &= ~(1<<5);
//   *(_UW*)(MT2IGCR) &= ~(1<<6|1<<3|1<<2|1<<1|1<<0);
//   *(_UW*)(MT2IGRG2) = 1;
//   *(_UW*)(MT2IGRG3) = 9000;
//   *(_UW*)(MT2IGRG4) = 18000;
//   *(_UW*)(MT2RUN) |= (1<<0 | 1<<2);
//   tk_dly_tsk(1000);
//   *(_UW*)(MT2RUN) &= ~(1<<0 | 1<<2);
//   return 0;
// }

// 02課題５
// EXPORT    INT    usermain( void ){
//   _UW i;

//   *(_UW*)(PE_CR) |= (1 << 2);
//   *(_UW*)(PE_CR) |= (1 << 3);

//   INT time = 1;
//   *(_UW*)(PE_DATA) |= (1<<3);

//   for(i=0;i<100000;i++){
//     *(_UW*)(PE_DATA) |= (1<<2);
//     tk_dly_tsk((10000-time)/1000);
//     *(_UW*)(PE_DATA) &= ~(1<<2);
//     tk_dly_tsk(time/1000);
//     time += 1;
//   }
//   return 0;
// }

// 02課題４
// INT func(INT a){
//   return a*2;
// }
// EXPORT    INT    usermain( void ){
//   INT i;

//   i = 0;
//   i = func(i);
//   tm_printf("i = %d\n", i);

//   return 0;
// }

// 02課題３
// INT a = 0;
// EXPORT    INT    usermain( void ){
//   INT i, j;

//   for(i=0;i<10;i++){
//     for(j=0;j<10;j++){
//       a = i + j;
//     }
//   }
//   return 0;
// }

// 02課題２
// EXPORT    INT    usermain( void ){
//   _UW i;

//   *(_UW*)(PE_CR) |= (1 << 2);
//   *(_UW*)(PE_CR) |= (1 << 3);

//   while(1){
//     *(_UW*)(PE_DATA) &= ~(1<<2);
//     *(_UW*)(PE_DATA) |= (1<<3);
//     tk_dly_tsk(500);
//     *(_UW*)(PE_DATA) |= (1<<2);
//     *(_UW*)(PE_DATA) &= ~(1<<3);
//     tk_dly_tsk(500);
//   }
//   return 0;
// }

// 02課題１
// EXPORT    INT    usermain( void ){
//   ID tskid;

//   tskid = tk_get_tid();
//   tm_printf("Task ID: %d\n", (INT)tskid);

//   return 0;
// }

// EXPORT    INT    usermain( void )
// {
//   while (True){
//     (volatile int)(PE_CR) |= (1<<2);
//     sleep(1);
//     (volatile int)(PE_DATA) |= (1<<2);
//    }

//   return 0;
// }

// EXPORT    INT    usermain( void ){
//   tm_printf("hello\n");

//   return 0;
// }