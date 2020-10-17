#include <stdio.h>

int quick(int *arr, int left, int right)
{

    int loc = left; // the starting index we choose as the pivot element.
    int temp;

    while (left < right)
    { // if the left is equal than the right ie we have found the pivot position

        while (arr[loc] <= arr[right] && left < right)
        { // till the pivot element is less than the right elements decrease the right and if we don't find any element which is less than that then   left == right so we need to break out of this loop as the pivot element is in correct position.

            right--;
        }
        // check if the left is equal to the irght index it means that pivot element is in its correct position.

        if (left == right)
        {

            break;
        } // break;
        else
        {

            // swap the right element with the pivot as the pivot element is larger the element on its right.

            temp = arr[right];
            arr[right] = arr[loc];
            arr[loc] = temp;
            loc=right;
        }

        // same process for the left elements as the elements on the left of the pivot should be less than it.

        while (arr[loc] >= arr[left] && left < right)
        {

            left++; // till the pivot is greator than its left increase the value of left.
        }

        if (left == right) //it might be possible that the pivot element is its right position then left will become equal to the right element so we need to break of the loop.

        {
            break;
        }
        else
        {

            // swap the pivot element with the the left element.
            temp = arr[left];
            arr[left] = arr[loc];
            arr[loc] = temp;
            loc=left;
        }
    }
    return loc;
}

void quick_sort(int *arr, int left, int right)
{

    int partition_pos;

    partition_pos = quick(arr, left, right);
    // now check if there is atleast two elements in left and righ to call the quick_sort method.
    if (partition_pos > left+1) // the partition position  should be greator than the left value+1 becasue we need atleast two elements to perform sorting.
        quick_sort(arr, left, partition_pos - 1);
    if (partition_pos < right-1) // the partition position  should be lesser than the right value - 1  becasue we need atleast two elements to perform sorting.
        quick_sort(arr, partition_pos + 1, right);
}

int main(){

 int arr[] = {90, 10, 49, 1, 5, 2, 23, 1000, 100, 2010,0};
    int n = sizeof(arr) / sizeof(int);

    quick_sort(arr, 0,n-1);

    for (int i = 0; i < n; i++)
    {

        printf("%d  ", *(arr + i));
    }

}