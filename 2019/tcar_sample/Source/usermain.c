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

EXPORT    INT    usermain( void )
{
  while (True){
    (volatile int)(PE_CR) |= (1<<2);
    sleep(1);
    (volatile int)(PE_DATA) |= (1<<2);
   }

  return 0;
}