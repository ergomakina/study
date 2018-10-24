#include <stdio.h>
#include <stdint.h>
#define REG_PKCR (*((volatile uint32_t *)0x400C0A04))
#define REG_PKDATA (*((volatile uint32_t *)0x400C0A00))

int main(int argc, char const *argv[])
{
    for (;;)
    {
        volatile uint32_t data = REG_PKDATA;

        if (data & (1 << 4))
        {
            printf("H\n");
        }
        else
        {
            printf("L\n");
        }
    }
    return 0;
}
