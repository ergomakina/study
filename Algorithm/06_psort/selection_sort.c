/* selection_sort.c */

#include "sort.h"

void sort(T *list, int length, Comparefn compare)
{
    /* Assignment 6-1 */
    for (int i = 0; i < length - 1; i++)
    {
        T root = list[i];
        T min = list[i];
        int min_index;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (compare(min, list[i + j]) > 0)
            {
                // min > tmp
                min = list[i + j];
                min_index = i + j;
            }
            else
            {
                break;
            }
        }
        list[i] = min;
        list[min_index] = root;
    }
}
