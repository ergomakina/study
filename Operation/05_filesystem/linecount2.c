#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int count = 0;
    int fd, n, i;
    char buf[1024];
    fd = open(argv[1]);

    while ((n = read(fd, buf, sizeof(buf))) > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (buf[i] == '\n')
            {
                count++;
            }
        }
    }

    close(fd);

    printf("%d\n", ...);
    return 0;
}
