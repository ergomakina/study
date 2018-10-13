#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ret = 0;
    char *cmdline = "/proc/uptime";

    ret = system(cmdline);

    if (ret != 0)
    {
        printf("error ! \n");
    }

    return 0;
}