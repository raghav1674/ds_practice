#include <stdio.h>
#include <stdlib.h>

typedef struct BTnode
{

    int item;
    struct BTnode *left;
    struct BTnode *right;

} BST;

typedef struct node
{

    BST *data;
    struct node *next;

} STACK;

typedef enum
{
    false,
    true
} bool;

STACK *createNode(BST *data)
{

    STACK *temp = (STACK *)malloc(sizeof(STACK));

    temp->data = data;
    temp->next = NULL;

    return temp;
}

bool isEmpty(STACK *top)
{

    return (top == NULL) ? true : false;
}

void push(STACK **top, BST *data)
{

    STACK *temp = createNode(data);
    if (isEmpty(*top))
    {
        *top = temp;
    }
    else
    {

        temp->next = *top;
        *top = temp;
    }
}

void pop(STACK **top)
{

    if (!isEmpty(*top))
    {
        STACK *to_delete = *top;
        *top = (*top)->next;
        free(to_delete);
    }
}

BST *peek(STACK *top)
{

    if (!isEmpty(top))
    {

        return top->data;
    }
}