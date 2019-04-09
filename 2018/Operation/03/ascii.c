#include <stdio.h>
#include <ctype.h>

typedef struct dict
{
    int key;
    int value;
    //struct dict *next;
} DICT;

// int init()
// {
//     for (char moji = 'a'; moji <= 'z'; ++moji)
// }

int main(int argc, char const *argv[])
{
    // char *str = argv[1];
    // str[0] = tolower(str[0]);
    // printf("%s\n", str);
    // printf("%d\n", str[0]);
    // printf("%d\n", 'a');
    // printf("%c\n", 97);

    DICT dicts[26];
    for (char moji = 'a'; moji <= 'z'; ++moji)
    {
        char str = moji;
        int num = (int)str - 'a';
        dicts[num].key = str;
        dicts[num].value = 0;
    }
    for (char moji = 'a'; moji <= 'z'; ++moji)
    {
        if (isalpha(moji))
        {
            char str = tolower(moji);
            int num = (int)str - 'a';
            dicts[num].value += 1;
        }
    }
    for (char moji = 'a'; moji <= 'g'; ++moji)
    {
        if (isalpha(moji))
        {
            char str = tolower(moji);
            int num = (int)str - 'a';
            dicts[num].value += 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c: ", dicts[i].key);
        printf("%d\n", dicts[i].value);
    }
    return 0;
}
