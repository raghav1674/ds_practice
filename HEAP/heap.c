#include <stdio.h>
#include <stdlib.h>

typedef struct array
{

    int last_index;
    int capacity;
    int *arr;

} HEAP;

HEAP *create_heap(int capacity)
{

    HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
    heap->arr = (int *)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->last_index = -1;

    return heap;
}

void insert(HEAP *heap, int index, int data)
{

    if (index <= heap->last_index + 1 && index >= 0)
    {
        int temp;
        int parent_index = (index - 1) / 2;
        temp = data;
        while (temp > heap->arr[parent_index] && index != 0)
        {

            heap->arr[index] = heap->arr[parent_index];
            index = parent_index;
            parent_index = (index - 1) / 2;
        }
        heap->arr[index] = data;
        heap->last_index++;
    }
}
int delete (HEAP *heap)
{
    if (heap->last_index < 0)
        return -1;
    int item = heap->arr[0]; // always return the top most element.
    int temp = heap->arr[heap->last_index];  // put the lastindex value to the zeroth index and then decrement lastindex as one element has been deleted.
    heap->arr[0] = temp;

    int index = 0;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    heap->last_index--;
    if (heap->last_index == -1) // only one element in the heap.
    {

        return item;
    }
    else
    {

        while (left < heap->last_index && right < heap->last_index)
        {

            if (temp >= heap->arr[left]  && temp >= heap->arr[right]) // temp is teh biggest so no need to do anything.
                break;
            else if (heap->arr[left] > heap->arr[right])
            { // if left is greater than the right;
                heap->arr[index] = heap->arr[left];
                index = left;
            }
            else
            {

                heap->arr[index] = heap->arr[right];
                index = right;
            }

            left = (2 * index + 1);
            right = (2 * index + 2);
        }
    }

    heap->arr[index]=temp;  // put the temp value at its correct position.

    return item;
}


void display(HEAP *heap)
{

    for (int i = 0; i <= heap->last_index; i++)
    {

        printf("%d ", heap->arr[i]);
    }
}

int main()
{

    HEAP *my_heap = create_heap(10);
    insert(my_heap, 0, 20);
    insert(my_heap, 1, 35);
    insert(my_heap, 2, 90);
    insert(my_heap, 3, 40);
    insert(my_heap, 4, 10);
    insert(my_heap, 5, 60);
    insert(my_heap, 6, 25);
    insert(my_heap, 7, 70);
    insert(my_heap, 8, 66);

   
    // insert(my_heap,9,20);

    display(my_heap);


    printf("\n%d ",delete(my_heap));
 
    printf("\n%d ",delete(my_heap));
   
    printf("\n%d ",delete(my_heap));
    
    printf("\n%d ",delete(my_heap));
   
    printf("\n%d ",delete(my_heap));
    printf("\n%d ",delete(my_heap));
    printf("\n%d ",delete(my_heap));
    printf("\n%d ",delete(my_heap));
    printf("\n%d ",delete(my_heap));
   
    return 0;
}