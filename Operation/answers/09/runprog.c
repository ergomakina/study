#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t pid;

    if (argc <= 1) {
        fprintf(stderr, "Usage: runprog <program> ...\n");
        return 1;
    }
    
    pid = fork();
    if (pid < 0) goto error;
    
    if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
    }
    else {
        execvp(argv[1], argv + 1);

        /* Should not reach here */
        return 1;
    }
    
    return 0;

 error:
    fprintf(stderr, "ERROR\n");
    return 1;
}
