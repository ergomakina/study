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

// 02課題５
EXPORT    INT    usermain( void ){
  _UW i;

  *(_UW*)(PE_CR) |= (1 << 2);
  *(_UW*)(PE_CR) |= (1 << 3);

  INT time = 1;
  *(_UW*)(PE_DATA) |= (1<<3);

  for(i=0;i<100000;i++){
    *(_UW*)(PE_DATA) |= (1<<2);
    tk_dly_tsk((10000-time)/1000);
    *(_UW*)(PE_DATA) &= ~(1<<2);
    tk_dly_tsk(time/1000);
    time += 1;
  }
  return 0;
}

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