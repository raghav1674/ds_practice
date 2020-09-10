#include <stdio.h>

#include <stdlib.h>

typedef struct
{

    int capacity;
    int *arr;
    int top;

} STACK;

STACK *createStack(int capacity)
{

    STACK *array = (STACK *)malloc(sizeof(STACK));
    array->top = -1;
    array->capacity = capacity;
    array->arr = (int *)malloc(sizeof(int) * capacity);

    return array;
}

void doubleArray(STACK *array)
{

    array->capacity = 2 * array->capacity;

    int *newArray = (int *)malloc(sizeof(int) * array->capacity);

    for (int i = 0; i <=array->top; i++)
    {

        newArray[i] = array->arr[i];
    }

    array->arr = newArray;
}

void halfArray(STACK *array)
{

    array->capacity = array->capacity / 2;

    int *newArray = (int *)malloc(sizeof(int) * array->capacity);

    for (int i = 0; i <= array->top; i++)
    {

        newArray[i] = array->arr[i];
    }

    array->arr = newArray;
}

void push(STACK *array, int data)
{

    if (array->top == array->capacity - 1)
    {

        doubleArray(array);
    }

    array->top++;
    array->arr[array->top] = data;
}

void pop(STACK *array)
{

    if (array->top == -1)
    {

        printf("STACK UNDERFLOW");
        exit(0);
    }
    else
    {

        array->top--;
    }
    if (array->top == (array->capacity / 2) - 1)
        halfArray(array);
}

int peek(STACK *array)
{

    return array->arr[array->top];
}

int main()
{

    STACK *stack = createStack(4);

    push(stack, 10);

    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    printf("%d  ", stack->capacity);
    push(stack, 50);
    push(stack, 60);
    push(stack, 70);
    push(stack, 80);
    printf("%d  ", stack->capacity);
    push(stack, 90);

    printf("%d  ", stack->capacity);

    pop(stack);

    printf("%d  ", stack->capacity);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    
    pop(stack);

    pop(stack);

    printf("%d  ", stack->capacity);

    printf("%d ",peek(stack));
    // push(stack,20);
    pop(stack);

    printf("%d ",peek(stack));


    printf("%d  ", stack->capacity);

    return 0;
}
