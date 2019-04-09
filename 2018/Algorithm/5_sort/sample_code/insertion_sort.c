/* insertion_sort.c */

#include "sort.h"
#include <stdio.h>

void sort(int *list, int length)
{
    for (int i = 1; i < length; i++)
    {
        int c = 0;
        int target = list[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (target < list[j])
            {
                list[j + 1] = list[j];
                c = 1;
            }
            else
            {
                break;
            }
        }
        list[j + 1] = target;
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