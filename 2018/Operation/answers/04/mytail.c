#include <stdio.h>

#define N 3

static inline int max(int n, int m)
{
    return (n > m) ? n : m;
}

int main()
{
    char buf[N][1024];
    int i, j;

    for (i = 0; gets(buf[i % 3]); i++) {
        ;
    }

    for (j = max(0, i - N); j < i; j++) {        
        puts(buf[j % 3]);
    }

    return 0;
}
