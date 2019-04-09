#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LIST reverse(LIST lst)
{
    LIST reversed_lst = list_construct();

    POSITION original = list_first(lst);
    POSITION reversed = list_first(reversed_lst);

    while (original != list_last(lst))
    {
        long int tmp = list_retrieve(lst, original);
        list_insert(reversed_lst, reversed, tmp);

        original = list_next(lst, original);
    }

    return reversed_lst;
}

int main(int argc, char *argv[])
{
    LIST original_lst = list_construct();
    POSITION p = list_first(original_lst);

    for (int i = 0; i < 20; i++)
    {
        list_insert(original_lst, p, rand() % 10);
    }

    printf("\n");
    printf("original_lst: ");
    list_print(original_lst);
    LIST reversed_lst = list_construct();
    reversed_lst = reverse(original_lst);
    printf("reversed_lst: ");
    list_print(reversed_lst);
    printf("\n");
    return 0;
}