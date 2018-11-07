#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 800
#define SERVER_PORTNUM 9000
#define QUEUE_SIZE 1

int main(int argc, char const *argv[])
{
    int serv_sock;
    // create a socket
    if ((serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        goto ERROR;
    // initialize
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORTNUM);

    // bind
    if (bind(serv_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        goto ERROR;

    // listen
    if (listen(serv_sock, QUEUE_SIZE) < 0)
        goto ERROR;

    struct sockaddr_in client_addr;
    int client_sock;
    socklen_t addr_len = sizeof(client_addr);
    if ((client_sock = accept(serv_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0)
        goto ERROR;

    // receive message from the client
    char buf[BUF_SIZE];
    int received_byts = 0;
    printf("Received messages: ");
    while (1)
    {
        // receive messages from server
        if ((received_byts = recv(client_sock, buf, sizeof(buf) - 1, 0)) < 0)
            goto ERROR;
        else if (received_byts == 0)
            break;
        buf[received_byts] = '\0';
        printf("%s", buf);

        // send messages to the client
        int total_sent_size;
        for (total_sent_size = 0; total_sent_size < received_byts;)
        {
            int sent_size;
            if ((sent_size = recv(client_sock, buf, received_byts - total_sent_size, 0)) < 0)
                goto ERROR2;
            total_sent_size += sent_size;
        }
    }

    // close the client socket
    close(client_sock);

    // close the server socket
    close(serv_sock);
    return 0;

ERROR2:
    if (client_sock >= 0)
        close(client_sock);
ERROR:
    fprintf(stderr, "ERROR: %s\n", strerror(errno));
    if (serv_sock >= 0)
        close(serv_sock);
    return 1;
}
