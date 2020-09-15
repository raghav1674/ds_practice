#include <stdio.h>

#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct
{

    int capacity;
    int rear;
    int front;
    int *arr;

} QUEUE;

QUEUE *createQueue(int capacity)
{

    QUEUE *newQueue = (QUEUE *)malloc(sizeof(QUEUE));

    newQueue->rear = newQueue->front = -1;
    newQueue->capacity = capacity;
    newQueue->arr = (int *)malloc(sizeof(int) * (newQueue->capacity));

    return newQueue;
}

bool isEmpty(QUEUE *queue)
{

    return queue->rear == -1 ? true : false;
}

void display(QUEUE *queue)
{

    if (!isEmpty(queue))
    {
        int end = queue->rear < queue->front ? queue->capacity + queue->rear : queue->rear;
        for (int i = queue->front; i <= end; i++)
        {
            int index = i;
            if (i >= queue->capacity)
                index = i % queue->capacity;
            printf("%d ", queue->arr[index]);
        }
    }
    else
    {

        printf("QUEUE IS EMPTY.");
    }
}

bool isFull(QUEUE *queue)
{

    return (queue->rear + 1) % queue->capacity == queue->front ? true : false;
}

void enqueue(QUEUE *queue, int data)
{
    if (isFull(queue))
    {

        printf("QUEUE OVERFLOW.\n");
        // queue->rear++;
        return;
    }

    else if (isEmpty(queue))
    {
        // printf("---when empty-----\n");
        queue->front++;
        queue->rear++;
    }
    // else if (queue->rear == (queue->capacity - 1))
    // {
    //     // printf("---when reached the end-----\n");

    //     queue->rear = (queue->rear + 1) % queue->capacity;
    // }

    else
    {
        // printf("---normal insert-----\n");
        
        queue->rear = (queue->rear + 1) % queue->capacity;
        // queue->rear++;
    }

    queue->arr[queue->rear] = data;
}

void dequeue(QUEUE *queue)
{

    if (isEmpty(queue))
    {

        printf("QUEUE UNDERFLOW\n");
        return;
    }
    else if (queue->rear == queue->front)
    {
        // printf("---when one single element DQ-----\n");
        queue->rear = queue->front = -1;
    }
    // else if (queue->front == (queue->capacity - 1))
    // {
    //     // printf("---when reached the end DQ----\n");

    //     queue->front = (queue->front + 1) % queue->capacity;
    // }

    else
    {
        // printf("---normal delete NORMAL-----\n");
         queue->front = (queue->front + 1) % queue->capacity;
        // queue->front++;
    }
}

int main()
{

    QUEUE *queue = createQueue(4);

    enqueue(queue, 1);

    // enqueue(queue, 2);
    // enqueue(queue, 3);
    // enqueue(queue, 4);

    // // dequeue(queue);
    // dequeue(queue);

    // // dequeue(queue);
    // // dequeue(queue);
    // dequeue(queue);

    // enqueue(queue, 5);
    // enqueue(queue, 6);
    // enqueue(queue, 7);
    // enqueue(queue, 8);

    // dequeue(queue);
    // dequeue(queue);
    // dequeue(queue);
    // dequeue(queue);
    
    // printf("%d-full\n",isFull(queue));

    // printf("front--> %d\n", queue->front);
    // printf("REAR---> %d\n", queue->rear);
    display(queue);

    return 0;
}