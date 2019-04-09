#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    char *cmd[64], *p, *cmdline, *redirect;
    pid_t pid;
    int i, status, fd;

    for (;;) {
        printf("> ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }

        cmdline = strtok_r(buf, ">", &p);
        redirect = strtok_r(NULL, ">", &p);
        
        for (i = 0; i < sizeof(cmd)/sizeof(cmd[0]) - 1; ) {
            char* token = strtok_r((i == 0) ? cmdline : NULL, " \t\r\n", &p);
            if (!token) break;

            cmd[i++] = token;
        }
        cmd[i] = NULL;
        if (i < 1) continue;

        pid = fork();
        if (pid > 0) {
            /* Parent */
            wait(&status);
        }
        else {
            /* Child */
            if (redirect) {
                char* token = strtok_r(redirect, " \t\r\n", &p);
                if (!token) return -1;
                
                fd = open(token, O_CREAT|O_TRUNC|O_WRONLY, 0666);
                if (fd < 0) return -1;

                close(STDOUT_FILENO);
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }
            
            execvp(cmd[0], cmd);
            return -1;
        }
    }

    return 0;
}
