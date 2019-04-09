#include <stdio.h>

int main()
{
    int i;
    char s[256];
    
    for (i = 0;; i++) {
        if (!gets(s)) break;
        printf("%6d\t%s\n", i, s);
    }

    return 0;
}
