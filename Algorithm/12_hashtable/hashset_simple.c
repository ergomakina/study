/* hashset_simple.c */

#include "set.h"
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef struct hashset_simple
{
    char *table[SIZE];
} hashset_simple;

int hash(char *str)
{
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum += str[i];
    }
    return sum % SIZE;
}

SET set_construct()
{
    hashset_simple *hashset = (hashset_simple *)malloc(sizeof(hashset_simple));
    for (int i = 0; i < SIZE; i++)
    {
        hashset->table[i] = NULL;
    }
    return (SET)hashset;
}

void set_free(SET set)
{
    hashset_simple *hashset = (hashset_simple *)set;
    for (int i = 0; i < SIZE; i++)
    {
        if (hashset->table[i] != NULL)
        {
            free(hashset->table[i]);
        }
    }
    free(hashset);
}

int set_insert(SET set, char *str)
{
    hashset_simple *hashset = (hashset_simple *)set;
    int h = hash(str);
    if (hashset->table[h] != NULL)
    {
        return 0;
    }

    char *str2 = (char *)malloc(strlen(str) + 1);
    strcpy(str2, str);

    hashset->table[h] = str2;

    return 1;
}

int set_delete(SET set, char *str)
{
    hashset_simple *hashset = (hashset_simple *)set;
    int h = hash(str);
    if (hashset->table[h] == NULL)
    {
        return 0;
    }

    if (strcmp(hashset->table[h], str) != 0)
    {
        return 0;
    }

    free(hashset->table[h]);
    hashset->table[h] = NULL;

    return 1;
}

int set_member(SET set, char *str)
{
    hashset_simple *hashset = (hashset_simple *)set;
    int h = hash(str);
    if (hashset->table[h] == NULL)
    {
        return 0;
    }
    if (strcmp(hashset->table[h], str) != 0)
    {
        return 0;
    }
    free(hashset->table[h]);
    return 1;
}
