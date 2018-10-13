#include <stdio.h>

int isalnum();

int main()
{
    FILE *fp;
    char buf[128];

    fp = fopen("/dev/random", "rb");
    fread(buf, sizeof(buf), 1, fp);
    for (int i = 0; i < sizeof(buf); i++)
    {
        if (isalnum(buf[i]))
            printf("%c", buf[i]);
    }
    printf("\n");
    return 0;
}