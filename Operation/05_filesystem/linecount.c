#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char buf[8192];
    int i, j, fd, rlen, wlen;
    int counter = 0;

    for (i = 1; i < argc; i++)
    { /* skip argv[0] */
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
            goto error;

        for (;;)
        {
            rlen = read(fd, buf, sizeof(buf));
            if (rlen < 0)
                goto error;
            if (rlen == 0)
                break; /* end of file */

            for (j = 0; j < rlen;)
            {
                wlen = write(STDOUT_FILENO, buf + j, rlen - j);
                if (wlen < 0)
                    goto error;

                j += wlen;
                counter++;
            }
        }
        close(fd);
        printf("%d\n", counter);
    }

    return 0;

error:
    fprintf(stderr, "ERROR: %s\n", strerror(errno));
    if (fd >= 0)
        close(fd);
    return 1;
}
