#include <stdio.h>
#include <stdlib.h>


typedef struct node{

  char item;
  struct node* left;
  struct node* right;

}BT;

typedef struct STACK
{

    BT* data;
    struct STACK *next;

} STACK;

STACK *createSTACK(BT* data)
{

    STACK *temp = (STACK *)malloc(sizeof(STACK));
    temp->data = data;

    temp->next = NULL;

    return temp;
}

void push(STACK **top, BT* data)
{

    STACK *temp = createSTACK(data);
    temp->next = *top;
    *top = temp;
}

int isStackEmpty(STACK * top){

    return top == NULL?1:0;
}

void pop(STACK **top)
{

    if (*top)
    {
        STACK *temp = *top;

        *top = (*top)->next;
        free(temp);
    }
  
}

BT* peek(STACK *top)
{
    if (top)
        return top->data;
   
}




