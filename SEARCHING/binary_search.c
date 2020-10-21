#include <stdio.h>

int binary_search(int *arr, int element, int l, int r)
{
    int mid = (l + r) / 2;
    if (l <= r) // till there is one element or r==l and l==r
    {

        // calculate the mid.

        if (arr[mid] == element)

            return mid;

        if (arr[mid] < element) // if the mid is lesser than the element, search on the right side

             binary_search(arr, element, mid + 1, r);

        if(arr[mid]>element)

             binary_search(arr, element, l, mid - 1); // else on the left side.
    }

    return mid;
}

int main()
{

    int arr[10] = {10,11,12,15,19};
    printf("\n %d ", binary_search(arr, 11, 0, 4));
    return 0;
}