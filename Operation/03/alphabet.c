#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int count[8][16];

    char tmp;

    int ddddd = 0;
    char test = 'a';
    while ((tmp = fgetc(stdin)) != EOF)
    {
        // fputc(tmp, stdout);
        printf("%d\n", (int)tmp);
        if (tmp == test)
        {
            ddddd++;
        }
    }
    // int dd[] = (int)test;
    printf("%d", ddddd);
    printf("\n");
    return 0;
}
