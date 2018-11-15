#include <stdio.h>
#include <ctype.h>

int main(void)
{
    for (;;) {
        int c = fgetc(stdin);
        if (c == EOF) break;

        fputc(isdigit(c) ? '*' : c, stdout);
    }
    
    return 0;
}
