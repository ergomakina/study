#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *const str[] = {"/bin/echo", "foo", "bar", NULL};

    execv("/bin/echo", str);

    if (errno != 0)
        perror(strerror(errno));

    return -1;
}