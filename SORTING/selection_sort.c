
#include <stdio.h>

int min(int *arr, int start, int size)
{

    int min_index = start;

    for (int i = start; i < size; i++)
    {

        if (*(arr + min_index) > *(arr + i))
            min_index = i;
    }

    return min_index;
}

void selection_sort(int *arr, int size) // select the minimum and swap.
{
    int min_index = 0;
    int temp;
    for (int i = 0; i < size; i++)
    {

        min_index = min(arr, i, size);

        temp = arr[i];

        arr[i] = arr[min_index];

        arr[min_index] = temp;
    }
}

int main(){

    int arr[] = {90, 10, 49, 1, 5, 2, 23,1000,100,2010};
    int n = sizeof(arr) / sizeof(int);

    selection_sort(arr,n);

    for(int i = 0; i < n; i++){
       
       
        printf("%d  ",*(arr+i));
    }

}