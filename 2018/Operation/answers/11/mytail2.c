#include <sys/mman.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage()
{
    fprintf(stderr, "Usage: mytail2 (-n <count>) <file>\n");
    exit(1);
}

int main(int argc, char* argv[])
{
    int er, i, n, fd = -1;
    struct stat fileinfo;
    char* fname = NULL;
    int count = 3; /* default */
    char* map = NULL;
    
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && (i+1) < argc) {
            count = atoi(argv[i+1]);
            i++;
        }
        else if (argv[i][0] != '-' && !fname) {
            fname = argv[i];
        }
        else {
            usage();
        }
    }

    if (!fname || count <= 0) {
        usage();
    }
    
    fd = open(fname, O_RDONLY);
    if (fd < 0) goto error;

    er = fstat(fd, &fileinfo);
    if (er < 0) goto error;

    /* Map the whole file onto memory address
       (fileinfo->st_size contains the file size) */
    map = (char*)mmap(NULL, fileinfo.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == NULL) goto error;

    for (i = fileinfo.st_size - 2, n = 0; i >= 0; i--) {
        if (map[i] == '\n') {
            n++;
            if (n >= count) {
                i++;
                break;
            }
        }
    }

    if (i < 0) i = 0;
    fwrite(map + i, 1, fileinfo.st_size - i, stdout);

    munmap(map, fileinfo.st_size);
    close(fd);
    
    return 0;

 error:
    if (map) munmap(map, fileinfo.st_size);
    if (fd >= 0) close(fd);
    fprintf(stderr, "ERROR\n");
    return 1;
}
