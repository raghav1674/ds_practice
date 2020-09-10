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

void push(STACK *array, int data)
{

    if (array->top == array->capacity-1)
    {
        printf("STACK OVERFLOW");
        exit(0);
    }
    else
    {

        array->top++;
        array->arr[array->top] = data;
    }
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
}

int peek(STACK *array)
{
     if (array->top == -1)
    {

        printf("STACK IS EMPTY");
        exit(0);
    }

    return array->arr[array->top];
}

int main()
{

    STACK *stack = createStack(4);
    push(stack, 10);

   
    push(stack,20);
    push(stack,20);
    push(stack,20);
    pop(stack);
    push(stack,20);
     
    
     
    // printf("%d ",value);

    return 0;
}
