#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char buf[1024];
    char *cmd[64], *p;
    pid_t pid;
    int i, status;

    for (;;) {
        printf("> ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        
        for (i = 0; i < sizeof(cmd)/sizeof(cmd[0]) - 1; ) {
            char* token = strtok_r((i == 0) ? buf : NULL, " \n\r\t", &p);
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
            execvp(cmd[0], cmd);
            return -1;
        }
    }

    return 0;
}
