#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct node
{

    int data;
    struct node *next;

} DEQUEUE;

DEQUEUE *createNode(int data)
{

    DEQUEUE *temp = (DEQUEUE *)malloc(sizeof(DEQUEUE));

    temp->data = data;

    temp->next = NULL;
}

bool isEmpty(DEQUEUE *head, DEQUEUE *tail)
{

    return (tail == NULL && head == NULL) ? true : false;
}

void enqueue_head(DEQUEUE **head, DEQUEUE **tail, int data)
{

    DEQUEUE *temp = createNode(data);
    if (isEmpty(*head, *tail))
        *head = *tail = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void enqueue_tail(DEQUEUE **head, DEQUEUE **tail, int data)
{

    DEQUEUE *temp = createNode(data);
    if (isEmpty(*head, *tail))
        *head = *tail = temp;
    else
    {
        (*tail)->next = temp;
        *tail = temp;
    }
}

void dequeue_head(DEQUEUE **head, DEQUEUE **tail)
{

    if (isEmpty(*head, *tail))
    {

        printf("QUEUE UNDERFLOW");
        return;
    }
    else if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {

        DEQUEUE *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void dequeue_tail(DEQUEUE **head, DEQUEUE **tail)
{

    if (isEmpty(*head, *tail))
    {

        printf("QUEUE UNDERFLOW");
        return;
    }
    else if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {

        DEQUEUE *temp = *head, *t,*d;
        while (temp->next != NULL)
        { 
            
           
             t=temp;
             temp = temp->next;
        }
        d = temp;
       
        t->next = NULL;
        *tail = t;

        free(d);
    }
}

void display(DEQUEUE *head, DEQUEUE *tail)
{

    if (isEmpty(head, tail))
    {
        printf("QUEUE UNDERFLOW");
        return;
    }
    while (head)
    {

        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{

    DEQUEUE *head = NULL;
    DEQUEUE *tail = NULL;

    enqueue_head(&head, &tail, 20);
    enqueue_head(&head, &tail, 10);
    enqueue_head(&head,&tail,10);
    enqueue_head(&head,&tail,10);


    enqueue_tail(&head,&tail,40);
    enqueue_tail(&head,&tail,50);
    dequeue_head(&head,&tail);
    dequeue_tail(&head,&tail);

    display(head, tail);

    return 0;
}