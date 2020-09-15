#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int capacity;
    int top1;
    int top2;
    int *ptr;

} TWS;

int size_right_stack(TWS* stack){

    return stack->capacity-stack->top2;
}

int size_left_stack(TWS* stack){

    return stack->top1+1;
}

TWS *createTwoWayStack(int capacity)
{

    TWS *temp = (TWS *)malloc(sizeof(TWS));

    temp->capacity = capacity;
    temp->top1 = -1;
    temp->top2 = capacity;
    temp->ptr = (int *)malloc(sizeof(int) * capacity);
}

void push_left(TWS *stack, int data)
{

    if (stack->top1 + 1 == stack->top2)
    {

        printf("OVERFLOW STACK LEFT\n");
        return;
    }

    stack->top1 += 1;
    stack->ptr[stack->top1] = data;
}

void push_right(TWS *stack, int data)
{

    if (stack->top2 - 1 == stack->top1)
    {

        printf("OVERFLOW STACK RIGHT\n");
        return;
    }
    stack->top2 -= 1;
    stack->ptr[stack->top2] = data;
}

void display_right_stack(TWS *stack)
{

    if (stack->top2 == stack->capacity)
    {

        printf("EMPTY RIGHT STACK\n");
        return;
    }

    for (int i = stack->capacity - 1; i >= stack->top2; i--)
        printf("%d ", stack->ptr[i]);
}

int peek_right_stack(TWS* stack){

    if(stack->top2!=stack->capacity)
    return stack->ptr[stack->top2];
}


int peek_left_stack(TWS* stack){

    if(stack->top1!=-1)
    return stack->ptr[stack->top1];
}

void display_left_stack(TWS *stack)
{

    if (stack->top1 == -1)
    {

        printf("EMPTY LEFT STACK\n");
        return;
    }

    for (int i = 0; i <= stack->top1; i++)
        printf("%d ", stack->ptr[i]);
}

void pop_right(TWS *stack)
{

    if (stack->top2 == stack->capacity)
    {

        printf("RIGHT STACK UNDERFLOW\n");
        return;
    }

    stack->top2++;
}

void pop_left(TWS *stack)
{

    if (stack->top1 == -1)
    {

        printf("LEFT STACK UNDERFLOW\n");
        return;
    }

    stack->top1--;
}

int main()
{

    TWS *stack = createTwoWayStack(10);

    push_right(stack, 10);
    push_right(stack, 20);
    push_right(stack, 30);
    push_right(stack, 40);
    push_right(stack, 50);
    push_left(stack, 60);
    push_left(stack, 70);
    push_left(stack, 80);
    push_left(stack, 90);
    push_left(stack, 100);
    
    printf("SIZE OF LEFT STACK : %d\n",size_left_stack(stack));
    printf("SIZE OF RIGHT STACK : %d\n",size_right_stack(stack));

    pop_left(stack);

    printf("SIZE OF LEFT STACK : %d\n",size_left_stack(stack));
    printf("SIZE OF RIGHT STACK : %d\n",size_right_stack(stack));
   

    display_left_stack(stack);

    display_right_stack(stack);

    printf("\nLEFT STACK TOP-MOST ELEMENT: %d\n",peek_left_stack(stack));
    printf("RIGHT STACK TOP-MOST ELEMENT: %d\n",peek_right_stack(stack));

    return 0;
}