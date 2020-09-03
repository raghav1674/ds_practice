

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{

    int data;
    struct node *next;
    struct node *prev;

} NODE;

NODE *createNode(int data)
{

    NODE *newNode = (NODE *)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void display(NODE *start)
{

    if (start)
    {

        while (start != NULL)
        {
            printf("%d ", start->data);
            start = start->next;
        }
    }

    else
    {
        printf("List is empty\n");
    }
}

void addFirst(NODE **start, int data)
{

    NODE *temp = createNode(data);
    if (*start == NULL)
    {

        *start = temp;
    }
    else
    {

        temp->next = *start;
        (temp->next)->prev = temp;
        *start = temp;
    }
}

void addLast(NODE **start, int data)
{

    NODE *t;
    NODE *temp = createNode(data);
    if (*start == NULL)
    {
        *start = temp;
    }
    else
    {

        t = *start;
        while (t->next != NULL)
        {

            t = t->next;
        }

        t->next = temp;
        temp->prev = t;
    }
}

NODE *search(NODE *start, int data)
{

    while (start != NULL)
    {
        if (start->data == data)
        {
            return start;
        }
        start = start->next;
    }

    return NULL;
}

void insertAfter(NODE *start, int previousData, int data)
{

    NODE *temp = createNode(data);
    NODE *previousNode = search(start, previousData);

    if (previousNode)

    {

        if (previousNode->next != NULL)

            (previousNode->next)->prev = temp;

        temp->next = previousNode->next;
        temp->prev = previousNode;
        previousNode->next = temp;
    }
    else
    {

        printf("No node is present with the value of %d\n", previousData);
    }
}

void deleteFirst(NODE **start)
{

    if (*start == NULL)
    {

        printf("List is empty.\n");
    }
    else
    {

        NODE *temp = *start;
        *start = (*start)->next;
        if (*start)
        {

            (*start)->prev = NULL;
        }
        free(temp);
    }
}

void deleteLast(NODE **start)
{

    if (*start == NULL)
    {

        printf("List is empty\n");
    }
    else if ((*start)->next == NULL)
    {

        free(*start);
        *start = NULL;
    }

    else
    {
        NODE *temp, *t1;

        temp = *start;
        while (temp->next != NULL)
        {

            t1 = temp;
            temp = temp->next;
        }

        t1->next = NULL;

        free(temp);
    }
}

void delete(NODE **start, int data)
{

    NODE *t = *start;
    NODE *toDelete = search(t, data);
    if (toDelete)
    {
        if (*start == toDelete)
        {

            *start = toDelete->next;
            free(toDelete);
        }
        else
        {

            while (t != toDelete)
            {

                t = t->next;
            }

            (t->prev)->next = t->next;
            if (t->next)
                (t->next)->prev = t->prev;
            free(t);
        }
    }

    else
    {

        printf("No such node with the value of %d\n", data);
    }
}

int main()
{

    NODE *start = NULL;

    addFirst(&start, 80);

    addLast(&start, 70);

    insertAfter(start, 70, 100);

    deleteFirst(&start);

    deleteLast(&start);

    delete (&start, 100);

    display(start);

    return 0;
}