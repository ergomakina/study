#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1

int main(int argc, char* argv[])
{
    int srcfd = -1, dstfd = -1;
    char buf[BUF_SIZE];
    int i, rcnt, wcnt;

    if (argc != 3) {
        fprintf(stderr, "Usage: filecopy <src> <dest>\n");
        return 1;
    }

    srcfd = open(argv[1], O_RDONLY);
    if (!srcfd) goto error;
    
    dstfd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666);
    if (!dstfd) goto error;

    for (;;) {
        rcnt = read(srcfd, buf, sizeof(buf));
        if (rcnt < 0) goto error;
        if (rcnt == 0) break;

        for (i = 0; i < rcnt; ) {
            wcnt = write(dstfd, buf + i, rcnt - i);
            if (wcnt <= 0) goto error;

            i += wcnt;
        }
    }

    close(dstfd);
    close(srcfd);
    return 0;

 error:
    if (dstfd >= 0) close(dstfd);
    if (srcfd >= 0) close(srcfd);
    fprintf(stderr, "ERROR\n");
    return 1;
}
