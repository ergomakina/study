#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char *str[128];
    fp = fopen("/dev/random", "rb");
    fread(str, sizeof(str), 1, fp);
    printf("%s\n", str);
    return 0;
}