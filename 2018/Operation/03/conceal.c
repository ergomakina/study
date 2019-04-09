#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char tmp[32];
    fgets(tmp, 32, stdin);
    fputs(tmp, stdout);
    for (int i = 0; i < 32; i++)
    {
        if (isdigit(tmp[i]))
        {
            fputs("*", stdout);
        }
        else
        {
            fputc(tmp[i], stdout);
        }
    }
    return 0;
}
