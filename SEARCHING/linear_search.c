#include <stdio.h>

int linear_search(int *arr, int element, int size)
{

    for (int i = 0; i < size; i++)
        if (arr[i] == element)
            return i;
    return -1;
}