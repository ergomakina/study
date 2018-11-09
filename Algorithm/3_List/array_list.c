/* array_list.c */

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define INITIAL_SIZE 10

typedef struct array_list
{
    int *elements;
    long length;
    long max_length;
} array_list;

LIST list_construct()
{
    array_list *a_lst = (array_list *)malloc(sizeof(array_list));
    a_lst->elements = (int *)malloc(sizeof(int) * INITIAL_SIZE);
    a_lst->length = 0;
    a_lst->max_length = INITIAL_SIZE;

    return (LIST)a_lst;
}

void list_free(LIST lst)
{
    array_list *a_lst = (array_list *)lst;
    if (a_lst == NULL)
    {
        return;
    }
    if (a_lst->elements != NULL)
    {
        free(a_lst->elements);
    }
    free(a_lst);
}

void list_print(LIST lst)
{
    array_list *a_lst = (array_list *)lst;
    for (long i = 0; i < a_lst->length; i++)
    {
        if (i != a_lst->length - 1)
        {
            printf("%d -> ", a_lst->elements[i]);
        }
        else
        {
            printf("%d\n", a_lst->elements[i]);
        }
    }
}

void list_insert(LIST lst, POSITION pos, int value)
{
    array_list *a_lst = (array_list *)lst;
    long a_pos = (long)pos;
    if (a_lst == NULL)
    {
        return;
    }
    if ((a_pos < 0) || (a_pos > a_lst->length))
    {
        return;
    }
    if (a_lst->length == a_lst->max_length)
    {
        int *new_elements = (int *)malloc(sizeof(int) * a_lst->max_length * 2);
        for (int i = 0; i < a_lst->length; i++)
        {
            new_elements[i] = a_lst->elements[i];
        }
        free(a_lst->elements);
        a_lst->elements = new_elements;
        a_lst->max_length = a_lst->max_length * 2;
    }
    for (int i = a_lst->length; i > a_pos; i--)
    {
        a_lst->elements[i] = a_lst->elements[i - 1];
    }
    a_lst->elements[a_pos] = value;
    a_lst->length++;
}

void list_delete(LIST lst, POSITION pos)
{
    array_list *a_lst = (array_list *)lst;
    long a_pos = (long)pos;
    if (a_lst == NULL)
    {
        return;
    }
    if ((a_pos < 0) || (a_pos >= a_lst->length))
    {
        return;
    }
    for (int i = a_pos; i < a_lst->length - 1; i++)
    {
        a_lst->elements[i] = a_lst->elements[i + 1];
    }
    a_lst->length--;
}

int list_retrieve(LIST lst, POSITION pos)
{
    array_list *a_lst = (array_list *)lst;
    long a_pos = (long)pos;
    if (a_lst == NULL)
    {
        return 0;
    }
    if ((a_pos < 0) || (a_pos >= a_lst->length))
    {
        return 0;
    }
    return a_lst->elements[a_pos];
}

POSITION list_first(LIST lst)
{
    return (POSITION)0;
}

POSITION list_last(LIST lst)
{
    array_list *a_lst = (array_list *)lst;
    if (a_lst->length == 0)
    {
        return (POSITION)0;
    }
    return (POSITION)a_lst->length;
}

POSITION list_next(LIST lst, POSITION pos)
{
    array_list *a_lst = (array_list *)lst;
    long a_pos = (long)pos;
    a_pos++;
    return (POSITION)a_pos;
}

POSITION list_previous(LIST lst, POSITION pos)
{
    array_list *a_lst = (array_list *)lst;
    long a_pos = (long)pos;
    a_pos--;
    return (POSITION)a_pos;
}

POSITION list_get(LIST lst, long n)
{
    return (POSITION)n;
}