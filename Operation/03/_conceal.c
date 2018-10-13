#include <stdio.h>
#include <stdlib.h>

//int isdigit();

int main(int argc, char *argv[])
{
    printf("%d", argc);
    printf("%s", argv[1]);
    FILE *fp = fopen(argv[1], "r");
    for (;;)
    {
        char tmp = fgetc(fp);
        if (tmp == EOF)
        {
            break;
        }
        putchar(tmp);
    }
    fclose(fp);
}