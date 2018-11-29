#include <stdio.h>      //printf(), fprintf(), perror()
#include <sys/socket.h> //socket(), bind(), accept(), listen()
#include <arpa/inet.h>  // struct sockaddr_in, struct sockaddr, inet_ntoa()
#include <stdlib.h>     //atoi(), exit(), EXIT_FAILURE, EXIT_SUCCESS
#include <string.h>     //memset()
#include <unistd.h>     //close()

int main(int argc, char const *argv[])
{
    const char *optstring = "46::";
    int opt = getopt(argc, argv, optstring);
    int sock0;
    int len;
    int sock;
    struct addrinfo hints, *res = NULL, *r;

    sock0 = socket(AF_INET, SOCK_STREAM, 0);

    if (opt == '4')
    {
        struct sockaddr_in addr;
        struct sockaddr_in client;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(10001);
        addr.sin_addr.s_addr = INADDR_ANY;
    }
    else if (opt == '6')
    {
        struct sockaddr_in6 addr;
        struct sockaddr_in6 client;
        addr.sin6_family = AF_INET6;
        addr.sin6_port = htons(10001);
        addr.sin6_addr.s_addr = INADDR_ANY;
    }
    else
    {
        printf("default -4\noption -4(IPv4) or -6(IPv6)\n");
        struct sockaddr_in addr;
        struct sockaddr_in client;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(10001);
        addr.sin_addr.s_addr = INADDR_ANY;
    }

    bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

    listen(sock0, 5);

    while (1)
    {
        len = sizeof(client);
        sock = accept(sock0, (struct sockaddr *)&client, &len);
        char msg[8];
        sprintf(msg, "%d", ntohs(client.sin_port));
        send(sock, "Your address is ", sizeof("Your address is "), 0);
        send(sock, inet_ntoa(client.sin_addr), sizeof(inet_ntoa(client.sin_addr)), 0);
        send(sock, " at port ", sizeof(" at port "), 0);
        send(sock, msg, sizeof(msg), 0);
        send(sock, "\n", sizeof("\n"), 0);

        close(sock);
    }

    close(sock0);

    return 0;
    return 0;
}