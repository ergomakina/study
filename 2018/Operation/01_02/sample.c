#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char buf[64];
    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "w");
    while (!feof(fp1))
    {
        int n;
        n = fread(buf, sizeof(char), sizeof(buf), fp1);
        fwrite(buf, sizeof(char), n, fp2);
    }
    printf("%s\n", buf);
    fclose(fp1);
    fclose(fp2);
}