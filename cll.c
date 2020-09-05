#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node *next;

} NODE;

NODE *createNode(int data)
{

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void addFirst(NODE **last, int data)
{

    NODE *temp = createNode(data);

    if (*last == NULL)
    {

        temp->next = temp;
        *last = temp;
    }
    else
    {

        temp->next = (*last)->next;
        (*last)->next = temp;
    }
}

void addLast(NODE **last, int data)
{

    NODE *temp = createNode(data);

    if (*last == NULL)
    {

        temp->next = temp;
        *last = temp;
    }
    else
    {

        temp->next = (*last)->next;
        (*last)->next = temp;
        *last = temp;
    }
}

NODE *search(NODE *last, int data)
{

    NODE *t = last;

    do
    {

        t = t->next;
        if (t->data == data)
        {

            return t;
        }
        t = t->next;

    } while (t->next != last->next);

    return NULL;
}

void display(NODE *last)
{

    NODE *temp = last;
    do
    {
        temp = temp->next;

        printf("%d ", temp->data);
    } while (temp != last);
}

void insertAfter(NODE **last, int previousData, int data)
{
    NODE *temp = createNode(data);
    NODE *t = *last;
    NODE *previous = search(t, previousData);

    if (previous)
    {
        if (previous->next == t->next)
        {

            addLast(last, data);
        }

        else
        {

            temp->next = previous->next;
            previous->next = temp;
        }
    }
}

void deleteLast(NODE **last)
{

    NODE *previous;
    NODE *t = (*last)->next;
    if (*last)
    {
        if (t == *last)
        {

            free(*last);
            *last = NULL;
        }
        while (t != *last)
        {
            previous = t;
            t = t->next;
        }

        previous->next = (*last)->next;
        free(t);
        *last = previous;
    }
}

void deleteFirst(NODE **last)
{

    NODE *temp = (*last)->next;
    if (temp == *last)
    {

        free(*last);
        *last = NULL;
    }
    (*last)->next = temp->next;
    free(temp);
}

void deleteAt(NODE **last, int data)
{

    NODE *t = *last;
    NODE *temp = search(t, data);
    if (temp)
    {

        if (temp->next == t->next)
        {

            deleteLast(last);
        }
        else
        {

            while (t->next != temp)
            {

                t = t->next;
            }

            t->next = temp->next;

            free(temp);
        }
    }
}


int main()
{

    NODE *last = NULL;
    addFirst(&last, 30);
    addFirst(&last, 40);
    addFirst(&last, 20);
    addFirst(&last, 10);
    addLast(&last, 70);

    // printf("%d ",searchNew(last,40)->data);
    // printf("%d", last->data);

    // insertAfter(&last, 70, 90);

    // deleteLast(&last);

    // deleteFirst(&last);

    deleteAt(&last, 30);
    display(last);

    return 0;
}