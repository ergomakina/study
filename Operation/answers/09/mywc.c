#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUF_SIZE 8192

int main(int argc, char* argv[])
{
    int fd = -1;
    int i, lines, words, chars, rcnt;
    char prev, buf[BUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: mywc <file> \n");
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) goto error;

    lines = words = chars = 0;
    prev = ' ';
    
    for (;;) {
        rcnt = read(fd, buf, sizeof(buf));
        if (rcnt < 0) goto error;
        if (rcnt == 0) break;
        chars += rcnt;

        for (i = 0; i < rcnt; i++) {
            if (buf[i] == '\n') {
                lines++;
            }

            if (isspace(prev) && !isspace(buf[i])) {
                words++;
            }
            
            prev = buf[i];
        }
    }
    close(fd);

    if (prev == '\n') lines++;
    printf("%4d %4d %4d %s\n", lines, words, chars, argv[1]);
    
    return 0;

 error:
    if (fd >= 0) close(fd);
    fprintf(stderr, "ERROR\n");
    return 1;
}
