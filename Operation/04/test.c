#include <stdio.h>

int main(void)
{
    FILE *fp;
    char *fname = "test.txt";
    fpos_t pos;

    fp = fopen(fname, "rb");
    if (fp == NULL)
    {
        printf("%sファイルが開けません\n", fname);
        return -1;
    }
    int BUF_SIZE = 256;
    char buf[BUF_SIZE];
    fseek(fp, 0, SEEK_END);
    for (int i = 1; fgets(buf, sizeof(BUF_SIZE), fp); i++)
    {
        printf("%s", buf);
    }
    fgetpos(fp, &pos);
    printf("ファイル位置は %dです\n", pos);

    rewind(fp);
    fgetpos(fp, &pos);
    printf("ファイル位置は %dです\n", pos);

    fclose(fp);
    return 0;
}