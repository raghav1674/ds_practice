#include <stdio.h>
#include <stdlib.h>

typedef enum boolean
{

    false,
    true

} bool;

typedef struct queue_node
{

    int vertex_data;
    struct queue_node *next;

} QNODE;

QNODE *create_queue_node(int data)
{

    QNODE *new_queue = (QNODE *)malloc(sizeof(QNODE));
    new_queue->vertex_data = data;
    new_queue->next = NULL;

    return new_queue;
}

bool isEmpty(QNODE *rear)
{

    return (rear == NULL) ? true : false;
}

void enqueue(QNODE **front, QNODE **rear, int data)
{
    QNODE *new_node = create_queue_node(data);
    if (isEmpty(*rear))
    {

        *rear = new_node;
        *front = new_node;
    }
    else
    {

        (*rear)->next = new_node;
        (*rear) = new_node;
    }
}

void dequeue(QNODE **front, QNODE **rear)
{

    QNODE *temp_node;
    if (!isEmpty(*rear))
    {

        if (*front == *rear)
        {
            *front = NULL;
            *rear = NULL;
        }
        else
        {

            temp_node = *front;
            *front = (*front)->next;
        }
    }
}

int peek(QNODE *front, QNODE *rear)
{

    if (!isEmpty(rear))
        return (front->vertex_data);
}