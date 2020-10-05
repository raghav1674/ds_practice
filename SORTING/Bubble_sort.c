#include <stdio.h>

typedef enum
{
    false,
    true
} bool;

void bubble_sort(int *arr, int size) // this is the logic of comparing two elements and then swaping it . but we have to repeat this until all the elements are not sorted.
{
    int temp;
    bool is_swap;

    for (int j = 0; j < size; j++)
    {
        is_swap = false;

        for (int i = 0; i < size - j - 1; i++)
        {

            if (*(arr + i) > *(arr + i + 1))

            {
                is_swap = true;

                temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
            }
        }
        if (!is_swap)  // to stop the pass when no swap is done.
        {

            break;
        }
    }
}
int main(){

    int arr[] = {90, 10, 49, 1, 5, 2, 23,1000,100,2010};
    int n = sizeof(arr) / sizeof(int);

    bubble_sort(arr,n);

    for(int i = 0; i < n; i++){
       
       
        printf("%d  ",*(arr+i));
    }

}