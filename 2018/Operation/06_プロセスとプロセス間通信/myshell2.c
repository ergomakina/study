#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* code */

    while (1)
    {
        char command[128];
        printf("> ");
        fgets(command, 128, stdin);
        printf("command = %s", command);

        char *tp;
        tp = strtok(command, "|");

        char *tps;
        char *cmd1[9] = {};
        char *cmd2[9] = {};
        int lct = 0;
        tps = strtok(command, " ");
        cmd1[lct] = tps;
        while (tps != NULL)
        {
            lct++;
            tps = strtok(NULL, " ");
            if (tps != NULL)
            {
                cmd1[lct] = tps;
            }
        }

        while (tp != NULL)
        {
            tp = strtok(NULL, "|");
            if (tp != NULL)
            {
                char *tps2;
                lct = 0;
                tps2 = strtok(tp, " ");
                cmd2[lct] = tps2;
                while (tps2 != NULL)
                {
                    lct++;
                    tps2 = strtok(NULL, " ");
                    if (tps2 != NULL)
                    {
                        cmd2[lct] = tps2;
                    }
                }
            }
        }

        pid_t pid;
        int pipefd[2], ret;
        ret = pipe(pipefd);
        pid = fork();
        if (pid > 0)
        {
            /* Parent */
            close(pipefd[0]);

            close(STDOUT_FILENO);
            dup2(pipefd[1], STDOUT_FILENO);

            execvp(cmd1[0], cmd1);
        }
        else
        {
            /* Child */
            close(pipefd[1]);

            close(STDIN_FILENO);
            dup2(pipefd[0], STDIN_FILENO);

            execvp(cmd2[0], cmd2);
        }
    }

    return 0;
}
