#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int capacity;
    int front;
    int rear;
    int *ptr;

} QUEUE;

QUEUE *createQueue(int capacity)
{

    QUEUE *temp = (QUEUE *)malloc(sizeof(QUEUE));

    temp->capacity = capacity;
    temp->front = temp->rear = -1;
    temp->ptr = (int *)malloc(sizeof(int) * capacity);

    return temp;
}

void doublequeue(QUEUE *queue)
{
        printf("hello ");
    int *temp = (int *)malloc(sizeof(int) * (queue->capacity * 2));

    int i = queue->front;
    while (i != queue->rear)
    {

        // temp[(i + queue->capacity*2 )% queue->capacity*2] = queue->ptr[i% queue->capacity];

        temp[i] = queue->ptr[i % queue->capacity];
        i++;
    }
    temp[i] = queue->ptr[queue->rear];
    free(queue->ptr);
    queue->ptr = temp;
    queue->rear = i;
    // queue->front = queue->rear%queue->capacity + queue->capacity;
    queue->capacity *= 2;
    // for(int i=0;i<queue->capacity;i++)
    // printf("%d    ",queue->ptr[i]);
}

void enqueue(QUEUE *queue, int data)
{

    if ((queue->rear + 1) % queue->capacity == queue->front)
    {

        doublequeue(queue);
        queue->rear++;
    }
    else if (queue->rear == -1)
    {
        queue->front++;
        queue->rear++;
    }
    else
    {

        queue->rear = (queue->rear + 1) % queue->capacity;
    }

    queue->ptr[queue->rear] = data;
}

void dequeue(QUEUE *queue)
{

    if (queue->front==-1)
    {

        printf("QUEUE UNDERFLOW\n");
        return;
    }
    else if (queue->rear == queue->front)
    {

        queue->rear = queue->front = -1;
    }

    else
    {   
        printf("ho");
        queue->front = (queue->front + 1) % queue->capacity;
    }
}


void display(QUEUE *queue)
{

    int i = queue->front;
    while (i != queue->rear)
    {

        printf("%d ", queue->ptr[i % queue->capacity]);
        i++;
    }
    printf("%d ", queue->ptr[queue->rear]);
}

int main()
{

    QUEUE *queue = createQueue(5);
    enqueue(queue, 10);

    printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    
    enqueue(queue, 20);
    dequeue(queue);
    printf("FRONT--%d\n",queue->front);

    printf("REAR--%d\n",queue->rear);

    enqueue(queue, 30);
    printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    enqueue(queue, 40);
    printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);

    enqueue(queue, 50);
    printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    enqueue(queue, 60);
    printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    // dequeue(queue);
    //  printf("FRONT--%d\n",queue->front);
    // printf("REAR--%d\n",queue->rear);
    enqueue(queue, 70);
     printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    enqueue(queue, 80);
     printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    enqueue(queue, 90);
     printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);
    enqueue(queue, 100);
     printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);

    // dequeue(queue);
     enqueue(queue, 110);
      printf("FRONT--%d\n",queue->front);
    printf("REAR--%d\n",queue->rear);

    display(queue);
    return 0;
}