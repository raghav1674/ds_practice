#include <stdlib.h>
#include <stdio.h>

typedef enum boolean
{

    false,
    true

} bool;

typedef struct stack_node
{

    int vertex_data;
    struct stack_node *next;

} SNODE;

SNODE *create_stack_node(int data)
{

    SNODE *new_stack = (SNODE *)malloc(sizeof(SNODE));
    new_stack->vertex_data = data;
    new_stack->next = NULL;

    return new_stack;
}

bool isEmpty(SNODE *top)
{

    return (top == NULL) ? true : false;
}

void push(SNODE **top, int value)
{

    SNODE *new_node = create_stack_node(value);
    if (isEmpty(*top))
        *top = new_node;
    else
    {

        new_node->next = *top;
        *top = new_node;
    }
}

void pop(SNODE **top)
{

    if (!isEmpty(*top))
    {

        SNODE *temp_top = *top;
        *top = (*top)->next;

        free(temp_top);
    }
}

int peek(SNODE *top)
{

    if (!isEmpty(top))
        return top->vertex_data;
}