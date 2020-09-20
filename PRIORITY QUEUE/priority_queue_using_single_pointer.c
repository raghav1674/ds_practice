#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct node
{

    int priority; // higher the number , higher will be the priority .
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

bool isEmpty(PQ *front)
{

    return (front == NULL) ? true : false;
}

void enqueue(PQ **front, int data, int priority)
{

    PQ *temp = createNode(data, priority);

    if (isEmpty(*front)) // if empty then simply make the front and rear point to temp
    {
        *front = temp;
    }
    else if ((*front)->priority < temp->priority) // if the priority of front is less than the temp , then insert at the begining
    {

        temp->next = *front;
        *front = temp;
    }

    else
    { // else if the priority of temp is same or less than than the front
        if ((*front)->next == NULL)
        {

            (*front)->next = temp;
        }
        else
        {

            PQ *tNode, *prevNode;
            tNode = *front;
            while (tNode->next != NULL) // traversing till end to check if the priority of last element is same or greater than the newly created node
            {
                tNode = tNode->next;
            }
            if (tNode->priority >= temp->priority) // if the priority of last node is same of greater than the newly created element then insert it at the last
            {

                tNode->next = temp;
            }
            else // otherwise check till the element with less priority is found.
            {
                tNode = *front;
                while (tNode->priority >= temp->priority)
                {
                    prevNode = tNode;
                    tNode = tNode->next;
                }
                temp->next = prevNode->next;
                prevNode->next = temp;
            }
        }
    }
}

void display(PQ *front)
{
    printf("\n");
    if (isEmpty(front))
    {
        printf("QUEUE UNDERFLOW");
        return;
    }

    while (front)
    {

        printf("%d[[%d]]  ", front->data, front->priority);
        front = front->next;
    }
}

void dequeue(PQ **front)
{

    if (isEmpty(*front))
    {
        printf("QUEUE UNDERFLOW");
    }
    else if ((*front)->next == NULL)
    {

        *front = NULL;
    }
    else
    {
        PQ *toDelete = *front;
        *front = (*front)->next;
        free(toDelete);
    }
}

int main()
{

    PQ *front = NULL;

    enqueue(&front, 10, -1);
    enqueue(&front, 20, -1);
    enqueue(&front, 30, -1);
    enqueue(&front, 40, 2);
    enqueue(&front, 50, 5);
    enqueue(&front, 60, 5);
    enqueue(&front, 70, 1);
    enqueue(&front, 80, 4);
    enqueue(&front, 90, 3);
    enqueue(&front, 100, 2);
    enqueue(&front, 110, 9);
    enqueue(&front, 110, -100);
    enqueue(&front, 120, -100);
    dequeue(&front);
    dequeue(&front);
    dequeue(&front);

    display(front);

    return 0;
}
