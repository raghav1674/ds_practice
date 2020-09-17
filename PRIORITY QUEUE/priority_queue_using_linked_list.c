#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;


typedef struct node
{

    int priority;  // higher the number , higher will be the priority .
    int data;
    struct node *next;

} PQ;

PQ *createNode(int data, int priority)
{

    PQ *temp = (PQ *)malloc(sizeof(PQ));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

bool isEmpty(PQ *front, PQ *rear)
{

    return (rear == NULL) ? true : false;
}

void enqueue(PQ **front, PQ **rear, int data, int priority)
{

    PQ *temp = createNode(data, priority);

    if (isEmpty(*front, *rear))  // if empty then simply make the front and rear point to temp
    {
        *front = *rear = temp;
    }
    else if ((*front)->priority < temp->priority) // if the priority of front is less than the temp , then insert at the begining
    {

        temp->next = *front;
        *front = temp;
    }
    else if ((*rear)->priority >= temp->priority) // if the priority of rear is greater or equal than the temp , then insert at the end
    {

        (*rear)->next = temp;
        (*rear) = temp;
    }
    else
    {              // else if the priority of temp is same or less than than the front

        PQ *t = *front;
        PQ *afterNode = NULL;
        while (t->priority >= temp->priority)
        {

            afterNode = t;
            t = t->next;
        }
        temp->next = afterNode->next;
        afterNode->next = temp;
    }
}

void display(PQ *front, PQ *rear)
{
    printf("\n");
    if (isEmpty(front, rear)){
     printf("QUEUE UNDERFLOW");
        return;
    }

    while (front)
    {

        printf("%d[[%d]]  ", front->data,front->priority);
        front = front->next;
    }
}

void dequeue(PQ **front, PQ **rear){

   if (isEmpty(*front, *rear)){
   printf("QUEUE UNDERFLOW");
        
   }
   else if(*front==*rear){

       *front=*rear=NULL;

   }
   else{
   PQ* toDelete = *front;
    *front = (*front)->next;
    free(toDelete);
   }
 
}

int main()
{

    PQ *front = NULL;
    PQ *rear = NULL;

    enqueue(&front, &rear, 10, -1);
    enqueue(&front, &rear, 20, -2);
    enqueue(&front, &rear, 30, 1);
    enqueue(&front, &rear, 40, 2);
    enqueue(&front, &rear, 50, 5);
    enqueue(&front, &rear, 60, 5);
    enqueue(&front, &rear, 70, 1);
    enqueue(&front, &rear, 80, 4);
    enqueue(&front, &rear, 90, 3);
    enqueue(&front, &rear, 100, 2);
    enqueue(&front, &rear, 110, 9);
    enqueue(&front, &rear, 110, -100);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);

    display(front, rear);

    return 0;
}
