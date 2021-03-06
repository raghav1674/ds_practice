#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int lastIndex;
    int capacity;
    int *ptr;

} Array;

Array *createArray(int cap)
{

    Array *A = (Array *)malloc(sizeof(Array));
    A->capacity = cap;
    A->ptr = (int *)malloc(sizeof(int) * cap);
    A->lastIndex = 0;
    return A;
}

void doubleArray(Array *A)
{

    A->capacity = 2 * (A->capacity);
    int *arr = (int *)malloc((A->capacity) * sizeof(int));
    for (int i = 0; i < A->lastIndex; i++)
    {

        arr[i] = A->ptr[i];
    }
    free(A->ptr);
    A->ptr = arr;
}

void halfArray(Array *A)
{

    A->capacity = (A->capacity) / 2;
    int *arr = (int *)malloc((A->capacity) * sizeof(int));
    for (int i = 0; i < A->lastIndex; i++)
    {

        arr[i] = A->ptr[i];
    }
    free(A->ptr);
    A->ptr = arr;
}

void setValue(Array *A, int index, int data)
{

    if (A->capacity == A->lastIndex)

        doubleArray(A);

    if (index < 0 || index > A->lastIndex)
    {
        printf("INVALID INDEX\n");
    }
    else
    {

        for (int i = A->lastIndex; i >= index; i--)
        {

            A->ptr[i + 1] = A->ptr[i];
        }
        A->ptr[index] = data;
        A->lastIndex++;
    }
}

void append(Array *A, int data)
{

    if (A->lastIndex == A->capacity)

        doubleArray(A);

    A->ptr[A->lastIndex] = data;
    A->lastIndex++;
}

int count(Array *A)
{

    return A->lastIndex;
}

void editValue(Array *A, int index, int data)
{

    if (index < 0 || index >= A->lastIndex)
    {
        printf("INVALID INDEX\n");
    }

    else
    {

        A->ptr[index] = data;
    }
}

void getValue(Array *A, int index)
{

    if (index < 0 || index >= A->lastIndex)
    {

        printf("INVALID INDEX\n");
    }

    else
    {
        printf("%d\n", A->ptr[index]);
    }
}

void delete (Array *A, int index)
{

    if (index < 0 || index >= A->lastIndex)
    {

        printf("INVALID INDEX\n");
    }
    else
    {

        for (int i = index; i < A->lastIndex; i++)
        {

            A->ptr[i] = A->ptr[i + 1];
        }
        A->lastIndex--;

        if (A->lastIndex == (A->capacity) / 2)
        {

            halfArray(A);
        }
    }
}

void display(Array *A)
{

    for (int i = 0; i < A->lastIndex; i++)
    {
        printf("%d \n", A->ptr[i]);
    }
}

int search(Array *A, int data)
{

    for (int i = 0; i < A->lastIndex; i++)
    {

        if (A->ptr[i] == data)
        {

            return i;
        }
    }
    // NOT FOUND
    return -1;
}




int main()
{

    Array *arr = createArray(3);
      setValue(arr,0,0);
      append(arr,2);
      append(arr,3);
      
      
    display(arr);
    return 0;
}
