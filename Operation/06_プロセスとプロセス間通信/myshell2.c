#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    pid_t pid;
    int pipefd[2], ret;

    ret = pipe(pipefd);
    if (ret < 0)
    {
        fprintf(stderr, "Pipe failed\n");
        return -1;
    }

    pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return -1;
    }

    if (pid > 0)
    {
        /* Parent */
        close(pipefd[0]);

        close(STDOUT_FILENO);
        dup2(pipefd[1], STDOUT_FILENO);

        char *cmd[] = {"ls", "-al", NULL};
        execvp(cmd[0], cmd);
    }
    else
    {
        /* Child */
        close(pipefd[1]);

        close(STDIN_FILENO);
        dup2(pipefd[0], STDIN_FILENO);

        char *cmd[] = {"cat", "-n", NULL};
        execvp(cmd[0], cmd);
    }

    while (1)
    {
        char command[128];
        printf("> ");
        fgets(command, 128, stdin);
        printf("command = %s", command);
        char *tp;

        /* ' | 'を区切りに文字列を抽出 */
        tp = strtok(command, "|");
        puts(tp);
        while (tp != NULL)

        {
            tp = strtok(NULL, "|");
            if (tp != NULL)
            {
                puts(tp);
                execvp(tp, cmd);
            }
        }
    }

    return 0;
}
