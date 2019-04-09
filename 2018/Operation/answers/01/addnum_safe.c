#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    char s[10]; /* intentionally made small */
    int i, len;
    bool cont;

    i = 1;
    cont = false;
    
    while (fgets(s, sizeof(s), stdin)) {
        if (!cont) {
            printf("%6d\t", i);
            i++;
        }
        printf("%s", s);

        len = strlen(s);
        cont = (len > 0 && s[len-1] != '\n');
    }

    return 0;
}
