#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    while (1)
    {
        char command[128];
        printf("> ");
        fgets(command, 128, stdin);

        char *tp;
        char *cmd[9];
        int lct = 0;
        tp = strtok(command, " ");
        cmd[lct] = tp;
        while (tp != NULL)
        {
            lct++;
            tp = strtok(NULL, " ");
            if (tp != NULL)
            {
                cmd[lct] = tp;
            }
        }
        cmd[lct] = NULL;

        pid_t pid = fork();
        int pipefd[2];
        pipe(pipefd);

        if (pid > 0)
        {
            /* Parent */
            close(pipefd[0]);
            write(pipefd[1], cmd, sizeof(cmd));
            int ret;
            waitpid(pid, &ret, 0);

            printf("child returned %d\n", ret);
        }
        else
        {
            /* Child */
            close(pipefd[1]);
            char *cmd[9];
            read(pipefd[0], cmd, sizeof(cmd));
            execvp(cmd[0], cmd);

            fprintf(stderr, "Should not reach here\n");
            return -1;
        }
    }
}
