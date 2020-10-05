#include <stdio.h>

void insertion_sort(int *arr, int size)
{

    int element;
    for (int i = 1; i < size ; i++) // start from the second card , suppose first one is already sorted.
    {

        element = *(arr + i); // take that element
        int j=i-1; // the index from which to start comparing till 0
   
        for(;j>=0;j--){

            if(element<*(arr+j)){  // if the element just previous to current element is less than move that to element's position ie towars right otherwise break of loop.

                *(arr+j+1)=*(arr+j);

            }
            else{

               
                break;
            }
        }
        *(arr+j+1)=element; // insert the element at this index ,if element is smallest of all then the j=-1 ,and arr[-1+1]=arr[0]
}
}

int main()
{

    int arr[] = {30,40,20,2,5,99};
    int n = sizeof(arr) / sizeof(int);

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {

        printf("%d  ", *(arr + i));
    }
}
