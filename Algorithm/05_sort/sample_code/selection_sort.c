/* selection_sort.c */

#include "sort.h"
#include <stdio.h>

void sort(int *list, int length)
{
    for (int i = 0; i < length; i++)
    {
        int c = 0;
        int min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (list[j] < list[min_index])
            {
                min_index = j;
                c = 1;
            }
        }
        int tmp = list[i];
        list[i] = list[min_index];
        list[min_index] = tmp;

        if (c == 1)
        {
            for (int k = 0; k < length; k++)
            {
                printf("%d", list[k]);
                if (k < length - 1)
                {
                    printf(",");
                }
            }
            printf("\n");
        }
    }
}
