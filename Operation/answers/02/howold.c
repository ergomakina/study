#include <stdio.h>

int main(void)
{
    FILE* fp;
    int cnt;
    double up;

    fp = fopen("/proc/uptime", "r");
    if (!fp) {
        fprintf(stderr, "ERROR: fopen\n");
        return 1;
    }

    cnt = fscanf(fp, "%lf", &up);
    if (cnt != 1) {
        fprintf(stderr, "ERROR: fscanf\n");
        return 1;
    }   

    fclose(fp);

    printf("Up for %f seconds\n", up);

    return 0;
}
