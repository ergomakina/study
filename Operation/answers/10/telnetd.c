#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    struct sigaction sigchld_action;
    struct addrinfo hints, *res = NULL, *r;
    int sockfd, er;

    /* Handle children without calling waitpid(2) */
    memset(&sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = SIG_IGN;
    sigchld_action.sa_flags = SA_NOCLDWAIT;
    sigemptyset(&sigchld_action.sa_mask);
    er = sigaction(SIGCHLD, &sigchld_action, NULL);
    if (er != 0) goto error;

    /* Resolve addresses */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; /* address for bind(2) */
    er = getaddrinfo("localhost", "10023", &hints, &res);
    if (er != 0) goto error;

    /* Try to connect to any one of the addresses got */
    for (r = res; r != NULL; r = r->ai_next) {
        sockfd = socket(r->ai_family, r->ai_socktype, r->ai_protocol);
        if (sockfd < 0) continue;

        er = bind(sockfd, r->ai_addr, r->ai_addrlen);
        if (er < 0) {
            close(sockfd);
            sockfd = -1;
            continue;
        }

        /* Successfully connected */
        break;
    }
    if (sockfd < 0) goto error;

    freeaddrinfo(res);
    res = NULL;

    er = listen(sockfd, 5);
    if (er < 0) goto error;

    for (;;) {
        int pid;
        struct sockaddr_storage addr;
        socklen_t addrlen;
        int clientfd;
    
        addrlen = sizeof(addr);
        er = accept(sockfd, (struct sockaddr*)&addr, &addrlen);
        if (er < 0) goto error;
        clientfd = er;

        pid = fork();
        if (pid < 0) goto error;

        if (pid > 0) {
            /* Parent */
            close(clientfd);

            /* By using signal handler, waitpid can be omitted here */
            // waitpid(pid, NULL, 0);
        }
        else {
            char* cmd[] = {"/bin/sh", "-i", NULL};
            /* Child */
            close(sockfd);

            close(STDIN_FILENO);
            close(STDOUT_FILENO);
            close(STDERR_FILENO);
            dup2(clientfd, STDIN_FILENO);
            dup2(clientfd, STDOUT_FILENO);
            dup2(clientfd, STDERR_FILENO);
            close(clientfd);

            execvp(cmd[0], cmd);
            return -1;
        }
    }

    /* Never reached */
    close(sockfd);
    return 0;

 error:
    if (res) freeaddrinfo(res);
    if (sockfd >= 0) close(sockfd);
    return -1;
}
