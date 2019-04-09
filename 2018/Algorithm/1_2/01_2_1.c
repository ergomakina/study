#include <stdio.h>
#include <stdlib.h>

int loop(unsigned int a, unsigned int b, unsigned int r)
{
    r = a % b;
    a = b;
    b = r;
    if (r == 0)
    {
        return b;
    }
    else
    {
        loop(a, b, r);
    }
}

unsigned int gcd(unsigned int a, unsigned int b)
{
    if (a > b)
    {
        unsigned int c = a;
        a = b;
        b = c;
    }
    unsigned int r;
    return loop(a, b, r);
}

int main(int argc, char *argv[])
{
    unsigned int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    return gcd(a, b);
}