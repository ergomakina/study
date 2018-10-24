#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    const char *n = argv[1];   // -n
    const char *num = argv[2]; // 3
    int line = 0;
    const char *arv = "-n";
    printf("%s ", n);
    printf("%s\n", num);

    // if (strcmp(n, arv)) {
    //     return 0;
    // }
    FILE *fp = stdin;
    const int BUF_SIZE = 256;
    char buf[BUF_SIZE];
    fpos_t pos;
    fgetpos(fp, &pos);
    printf("ファイル位置は %dです\n", pos);
    for (int i = 1; fgets(buf, sizeof(BUF_SIZE), fp); i++)
    {
        line++;
    }
    fgetpos(fp, &pos);
    printf("ファイル位置は %dです\n", pos);
    rewind(fp);
    fgetpos(fp, &pos);
    printf("ファイル位置は %dです\n", pos);
    for (int i = 1; fgets(buf, sizeof(buf), fp); i++)
    {
        printf("%s", buf);
        if (line - i < 4)
        {
        }
    }
    printf("line : %d\n", line);
    return 0;
}
