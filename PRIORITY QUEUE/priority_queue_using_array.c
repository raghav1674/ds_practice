#include <stdio.h>
#include <stdlib.h>

typedef enum bool
{
    false,
    true
} BOOL;

BOOL isCompleteEmpty(int *rear, int *front, int max_priority)
{

    for (int i = 0; i < max_priority; i++)
    {

        if (!(rear[i] == -1 && front[i] == -1))

            return false;
    }

    return true;
}

BOOL isCompleteFull(int *rear, int *front, int max_priority)
{

    for (int i = 0; i < max_priority; i++)
    {

        if (!(rear[i] == max_priority-1 ))

            return false;
    }

    return true;
}


BOOL isEmpty(int priority, int *rear)
{

    return (rear[priority] == -1) ? true : false;
}

BOOL isFull(int priority, int *rear, int max_priroity)
{

    return (rear[priority] == max_priroity - 1) ? true : false;
}

typedef struct prior_queue
{

    int **priority_queue;
    int *front;
    int *rear;
    int max_priority;

} PQ;

PQ *create_priority_queue(int max_priority)
{

    PQ *new_priority_queue = (PQ *)malloc(sizeof(PQ));

    new_priority_queue->max_priority = max_priority;
    new_priority_queue->front = (int *)malloc(sizeof(int) * max_priority);
    new_priority_queue->rear = (int *)malloc(sizeof(int) * max_priority);
    new_priority_queue->priority_queue = (int **)malloc(sizeof(int *) * max_priority);

    // square matrix

    for (int i = 0; i < max_priority; i++)
    {

        new_priority_queue->priority_queue[i] = (int *)malloc(sizeof(int) * max_priority);
        new_priority_queue->front[i] = -1; // initializing with -1
        new_priority_queue->rear[i] = -1;
    }

    return new_priority_queue;
}

void enqueue(int priority, int value, PQ *temp_priority_queue)
{

    if (isFull(priority, temp_priority_queue->rear, temp_priority_queue->max_priority))
    {

        printf("QUEUE WITHE PRIORITY NUMBER %d is Full.", priority);
        return;
    }
    else if (isEmpty(priority, temp_priority_queue->rear))
    {

        temp_priority_queue->rear[priority] = 0;
        temp_priority_queue->front[priority] = 0;
        temp_priority_queue->priority_queue[priority][0] = value;
    }
    else
    {
        temp_priority_queue->rear[priority] += 1;
        temp_priority_queue->priority_queue[priority][temp_priority_queue->rear[priority]] = value;
    }
}

void dequeue(PQ *temp_priority_queue)
{

    for (int cur = 0; cur < temp_priority_queue->max_priority; cur++)
    {

        if (!(isEmpty(temp_priority_queue->max_priority - 1 - cur, temp_priority_queue->rear)))
        {

            printf("%d ", temp_priority_queue->priority_queue[temp_priority_queue->max_priority - 1 - cur][temp_priority_queue->front[temp_priority_queue->max_priority - 1 - cur]]);
            temp_priority_queue->front[temp_priority_queue->max_priority - 1 - cur] += 1;

            if (temp_priority_queue->front[temp_priority_queue->max_priority - 1 - cur] == temp_priority_queue->max_priority)
            {

                temp_priority_queue->front[temp_priority_queue->max_priority - 1 - cur] = -1;
                temp_priority_queue->rear[temp_priority_queue->max_priority - 1 - cur] = -1;
            }
            return;
        }
    }
}
void display(PQ *temp_priority_queue)
{

    for (int i = 0; i < temp_priority_queue->max_priority; i++)
    {
        printf(" [%d] ", i);
        for (int j = 0; j < temp_priority_queue->max_priority; j++)
        {

            printf(" %d ", temp_priority_queue->priority_queue[i][j]);
        }
        printf("\n");
    }
}
int main()
{

    PQ *my_priority_queue = create_priority_queue(4);

    enqueue(0, 1, my_priority_queue);
    enqueue(1, 5, my_priority_queue);
    enqueue(2, 9, my_priority_queue);
    enqueue(3, 13, my_priority_queue);

    enqueue(0, 2, my_priority_queue);
    enqueue(1, 6, my_priority_queue);
    enqueue(2, 10, my_priority_queue);
    enqueue(3, 14, my_priority_queue);

    enqueue(0, 3, my_priority_queue);
    enqueue(1, 7, my_priority_queue);
    enqueue(2, 11, my_priority_queue);
    enqueue(3, 15, my_priority_queue);

    enqueue(0, 4, my_priority_queue);
    enqueue(1, 9, my_priority_queue);
    enqueue(2, 12, my_priority_queue);
    // enqueue(3, 16, my_priority_queue);

    enqueue(3, 17, my_priority_queue);

    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);

    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);

    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);

    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);
    dequeue(my_priority_queue);

    dequeue(my_priority_queue);

    display(my_priority_queue);

    return 0;
}