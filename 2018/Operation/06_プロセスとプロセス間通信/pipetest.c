#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    pid_t pid;
    char buf[128];
    int pipefd[2], ret, i, len;

    ret = pipe(pipefd);
    if (ret < 0) {
        fprintf(stderr, "Pipe failed\n");
        return -1;
    }
    
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return -1;
    }

    if (pid > 0) {
        /* Parent */
        close(pipefd[0]);

        strcpy(buf, "hello");
        for (i = 0; i < strlen(buf); i += len) {
            len = write(pipefd[1], "hello", strlen(buf) + 1 - i);
            if (len <= 0) break;
        }
    }
    else {
        /* Child */
        close(pipefd[1]);

        for (;;) {
            len = read(pipefd[0], buf, sizeof(buf));
            if (len <= 0) break;
        }

        printf("buf = %s\n", buf);
    }

    return 0;
}
