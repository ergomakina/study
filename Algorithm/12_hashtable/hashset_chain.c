/* hashset_chain.c */

#include "set.h"
#include <string.h>
#include <stdlib.h>

#define SIZE 10

typedef struct hashset_node
{
    struct hashset_node *next;
    char *value;
} hashset_node;

typedef struct hashset_simple
{
    hashset_node *table[SIZE];
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

void set_free_node(hashset_node *node)
{
    if (node->next != NULL)
    {
        set_free_node(node->next);
    }
    free(node->value);
    free(node);
}

void set_free(SET set)
{
    hashset_simple *hashset = (hashset_simple *)set;
    for (int i = 0; i < SIZE; i++)
    {
        if (hashset->table[i] != NULL)
        {
            set_free_node(hashset->table[i]);
        }
    }
    free(hashset);
}

int set_insert(SET set, char *str)
{
    hashset_simple *hashset = (hashset_simple *)set;
    int h = hash(str);

    hashset_node *node = hashset->table[h];
    while (node != NULL)
    {
        if (strcmp(node->value, str) == 0)
        {
            return 0;
        }
        node = node->next;
    }

    hashset_node *new_node = (hashset_node *)malloc(sizeof(hashset_node));
    new_node->next = hashset->table[h];
    new_node->value = (char *)malloc(strlen(str) + 1);
    strcpy(new_node->value, str);

    hashset->table[h] = new_node;

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

    hashset_node *node = hashset->table[h];
    if (strcmp(node->value, str) == 0)
    {
        hashset->table[h] = node->next;
        free(node->value);
        free(node);
        return 1;
    }
    else
    {
        while (node->next != NULL)
        {
            hashset_node *next = node->next;
            if (strcmp(next->value, str) == 0)
            {
                node->next = next->next;
                free(next->value);
                free(next);
                return 1;
            }
            node = node->next;
        }
    }

    return 0;
}

int set_member(SET set, char *str)
{

    hashset_simple *hashset = (hashset_simple *)set;
    int h = hash(str);
    if (hashset->table[h] == NULL)
    {
        return 0;
    }

    hashset_node *node = hashset->table[h];
    if (strcmp(node->value, str) == 0)
    {
        return 1;
    }
    else
    {
        while (node->next != NULL)
        {
            hashset_node *next = node->next;
            if (strcmp(next->value, str) == 0)
            {
                return 1;
            }
            node = node->next;
        }
    }

    return 0;
}
