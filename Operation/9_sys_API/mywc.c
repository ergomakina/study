#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int count_word(char *pre_word, char *cur_word)
{
    //ひとつ前の文字が空白か改行
    if (isspace(pre_word))
    {
        if (!isspace(cur_word))
        {
            //今の文字が英数字
            return 1;
        }
        return 0;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int fd;
    char *path = argv[1];
    int buf_size = 2048;
    char buf[buf_size];

    char pre_word = 'a';
    char cur_word;

    int num_line;
    int num_word;
    int num_size;

    fd = open(path, O_RDONLY);

    num_size = read(fd, buf, buf_size);

    printf("%c\n", pre_word);
    cur_word = buf[1];
    printf("%c\n", cur_word);

    for (int i = 0; i < num_size / 2; i++)
    {
        cur_word = buf[i];
        if (cur_word == EOF)
            break;
        if (cur_word == '\n')
        {
            num_line++;
            printf("%d\n", num_line);
        }
        num_word += count_word(&pre_word, &cur_word);
        pre_word = cur_word;
    }

    close(fd);

    printf("%d %d %d %s\n", num_line, num_word, num_size, path);
    return 0;
}
