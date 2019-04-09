#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    /* code */

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
        if (pid > 0)
        {
            int ret;
            waitpid(pid, &ret, 0);

            printf("child returned %d\n", ret);
        }
        else
        {
            execvp(cmd[0], cmd);

            fprintf(stderr, "Should not reach here\n");
            return -1;
        }
    }

    return 0;
}
