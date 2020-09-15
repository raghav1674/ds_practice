#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node *next;

} QUEUE;

QUEUE *createQueue(int data)
{

    QUEUE *newQueue = (QUEUE *)malloc(sizeof(QUEUE));
    newQueue->data = data;
    newQueue->next = NULL;
    return newQueue;
}

void enqueue(QUEUE **front, QUEUE **rear, int data)
{

    QUEUE *temp = createQueue(data);

    if (*rear == NULL)
    {

        *front = *rear = temp;
    }
    else
    {

        (*rear)->next = temp;
        *rear = temp;
    }
}

void dequeue(QUEUE **front, QUEUE **rear)
{

    if (*front == NULL)
    {

        printf("QUEUE UNDERFLOW\n");
        return;
    }
    else if (*front == *rear)
    {
        *front = *rear = NULL;
    }
    else
    {

        QUEUE *temp = *front;
        *front = (*front)->next;
    }
}

void display(QUEUE *front)
{
    if (front == NULL)
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    while (front)
    {

        printf("%d ", front->data);
        front = front->next;
    }
}

int main()
{

    QUEUE *front = NULL, *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);
    enqueue(&front, &rear, 60);

    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);

    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    
    display(front);

    return 0;
}