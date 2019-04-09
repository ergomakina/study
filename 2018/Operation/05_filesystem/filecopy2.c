#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 8192

int main(int argc, char const *argv[])
{
    char buf[BUF_SIZE];
    int src, dst, n, i;
    src = open(argv[1], O_RDONLY);
    dst = open(argv[2], O_WRONLY);

    while ((n = read(src, buf, sizeof(buf))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            write(dst, buf, sizeof(buf));
        }
    }

    close(src);
    close(dst);
    return 0;
}
