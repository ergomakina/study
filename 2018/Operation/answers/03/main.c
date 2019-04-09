#include <stdio.h>

extern int sum(int m, int n);

int main()
{
    printf("sum(20, 30) = %d\n", sum(20, 30));
    return 0;
}
