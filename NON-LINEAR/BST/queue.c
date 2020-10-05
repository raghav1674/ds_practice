#include <stdio.h>
#include <stdlib.h>

#include "stack.c"



typedef struct Qnode
{

    BST *data;

    struct Qnode *next;

} QUEUE;

QUEUE *createQueueNode(BST *data)
{

    QUEUE *temp = (QUEUE *)malloc(sizeof(QUEUE));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

bool isQueueEmpty(QUEUE *rear)
{

    return rear == NULL ? true : false;
}

void enqueue(QUEUE **front, QUEUE **rear, BST *data)
{

    QUEUE *temp = createQueueNode(data);

    if (isQueueEmpty(*rear))
    {

        *front = *rear = temp;
    }
    else
    {

        (*rear)->next = temp;
        (*rear) = temp;
    }
}

void dequeue(QUEUE **front, QUEUE **rear)
{

    if (!isQueueEmpty(*rear))
    {

        if (*front == *rear)
        {
            *front = *rear = NULL;
        }
        else
        {

            QUEUE *temp = *front;
            *front = (*front)->next;
            free(temp);
        }
    }
}

BST* peekQueue(QUEUE* front,QUEUE* rear){


 if(!isQueueEmpty(rear)){

     return front->data;
 }

}