#include <stdio.h>
#include <string.h>

int main()
{
    int count[26];
    int i;

    memset(count, 0, sizeof(count));
    
    for (;;) {
        int c = fgetc(stdin);
        if (c == EOF) break;

        if (c >= 'a' && c <= 'z') count[c-'a']++;
        else if (c >= 'A' && c <= 'Z') count[c-'A']++;
    }

    for (i = 0; i < sizeof(count)/sizeof(count[0]); i++) {
        printf("%c : %d\n", 'a' + i, count[i]);
    }
    
    return 0;
}
