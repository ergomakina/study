#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return -1;
    }

    if (pid > 0) {
        /* Parent */
        int ret;
        waitpid(pid, &ret, 0);

        printf("child returned %d\n", ret);
        return 0;
    }
    else {
        /* Child */
        char* cmd[] = {"ls", "-al", NULL};
        execvp(cmd[0], cmd);

        fprintf(stderr, "Should not reach here\n");
        return -1;
    }    
}
