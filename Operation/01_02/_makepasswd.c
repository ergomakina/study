#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ret = 0;
    char *cmdline = " env LC_ALL=C tr -dc a-zA-Z0-9 < /dev/urandom | fold -w 20 | head -1";
    ret = system(cmdline);

    if (ret != 0)
    {
        printf("error ! \n");
    }

    return 0;
}