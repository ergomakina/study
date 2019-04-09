#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct dict
{
    int key;
    int value;
} DICT;

void init(DICT dicts[])
{
    for (char str = 'a'; str <= 'z'; ++str)
    {
        int num = (int)str - 'a';
        dicts[num].key = str;
        dicts[num].value = 0;
    }
}

int main(int argc, char const *argv[])
{
    DICT dicts[26];

    // init list
    init(dicts);

    // read
    char tmp;
    while ((tmp = fgetc(stdin)) != EOF)
    {
        if (isalpha(tmp))
        {
            char str = tolower(tmp);
            int num = (int)str - 'a'; // 0 <= num <= 25
            dicts[num].value += 1;
        }
    }

    // print
    for (int i = 0; i < 26; i++)
    {
        printf("%c : ", dicts[i].key);
        printf("%d\n", dicts[i].value);
    }
    return 0;
}

//gcc -o alphabet alphabet.c
//man 3 printf | ./alphabet
