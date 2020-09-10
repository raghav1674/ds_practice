#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node *prev;
    struct node *next;

} NODE;

NODE *createNode(int data)
{

    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = temp->prev = NULL;
}

void push(NODE **top, int data)
{

    NODE *temp = createNode(data);
    if(*top)
    (*top)->prev = temp;

    temp->next = *top;
    *top = temp;
}

void pop(NODE **top)
{
    if(*top){
    NODE *temp = *top;

    if(temp->next!=NULL)
    temp->next->prev = NULL;

    *top = temp->next;
    free(temp);
}
else{

    printf("STACK UNDERFLOW");
    exit(0);
}
}

int peek(NODE *top)
{

    if (top)
        return top->data;
    else
    {
        printf("STACK IS EMPTY.");
        exit(0);
    }
}


int main()
{

    NODE *top = NULL;

    push(&top, 10);
    // push(&top, 20);
   
    pop(&top);

    printf("%d", peek(top));
    return 0;
}