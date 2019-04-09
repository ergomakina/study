#include <stdio.h>
#include <string.h>

int main()
{
    FILE* fp = NULL;
    unsigned int cnt, i, w, len;
    static const char* chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char buf[10];

    fp = fopen("/dev/random", "rb");
    if (!fp) goto error;
    
    cnt = fread(&w, sizeof(int), 1, fp);
    if (cnt != 1) goto error;

    len = 5 + (w % 5);

    for (i = 0; i < len; i++) {
        cnt = fread(&w, sizeof(int), 1, fp);
        if (cnt != 1) goto error;

        buf[i] = chrs[w % strlen(chrs)];
    }
    buf[i] = '\0';
    
    puts(buf);

    return 0;

 error:
    if (fp) fclose(fp);
    fprintf(stderr, "ERROR\n");
    return 1;
}
