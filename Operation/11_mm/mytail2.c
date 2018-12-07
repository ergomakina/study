#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

#define FILE_SIZE 1024

int main(int argc, char const *argv[])
{
    int fd, n;
    char *map;
    long page_size, map_size;
    char path[] = argv[3];

    if (strcmp(argv[1], "-n") == 0)
    {
        n = atoi(argv[2]);
    }
    else
    {
        printf("arg error.\n");
        return 0;
    }

    fd = open(path, O_RDONLY);

    if (fd < 0)
    {
        printf("Error : can't open file\n");
        return -1;
    }

    /* ページサイズからマッピング時のサイズを計算 */
    page_size = getpagesize();
    map_size = (FILE_SIZE / page_size + 1) * page_size;

    /* メモリ上にマッピング。今回は文字列データとして扱えるようにする */
    map = (char *)mmap(NULL, map_size, PROT_READ, MAP_SHARED, fd, 0);

    if (mmap == MAP_FAILED)
    {
        printf("Error : mmap failed\n");
        return -1;
    }

    /* ファイルの中身をはき出す */
    printf("%s", map);
    printf("map_size: %d", map_size);

    close(fd);
    munmap(map, map_size);

    return 0;
}