#include <stdio.h>
#include <stdlib.h>

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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFirst(NODE **start, int data)
{

    NODE *temp = createNode(data);

    if (*start == NULL)
    {

        (*start) = temp;
        temp->next = temp->prev = temp;
    }

    else
    {

        temp->next = *start;

        temp->prev = (*start)->prev;

        (*start)->prev->next = temp;

        (*start) = (*start)->prev = temp;
    }
}

void display(NODE *start)
{

    if (start == NULL)
    {

        printf("List is empty");
    }
    else
    {
        NODE *t = start;

        do
        {

            printf("%d ", t->data);
            t = t->next;
        } while (t != start);
    }
}

void insertLast(NODE **start, int data)
{

    NODE *temp = createNode(data);

    if (*start == NULL)
    {

        (*start) = temp;
        temp->next = temp->prev = temp;
    }

    temp->next = (*start);
    (*start)->prev->next = temp;
    temp->prev = (*start)->prev;
    (*start)->prev = temp;
}

void deleteFirst(NODE **start)
{

    if (*start == NULL)
    {

        printf("List is empty");
    }

    else if (*start == (*start)->next)
    {
        free(*start);
        *start = NULL;
    }
    else
    {
        (*start)->next->prev = (*start)->prev;

        (*start)->prev->next = (*start)->next;
        
        (*start) = (*start)->next;
    }
}

void deleteLast(NODE **start)
{

    if (*start == NULL)
    {

        printf("List is empty\n");
    }

    else if (*start == (*start)->next)
    {
        free(*start);
        *start = NULL;
    }

    else
    {
        NODE *t = (*start)->prev;

        (*start)->prev = t->prev;

        t->prev->next = t->next;

        free(t);
    }
}

NODE *search(NODE *start, int data)
{

    NODE *t = start;
    do
    {

        if (t->data == data)
            return t;
        t = t->next;

    } while (t != start);
    return NULL;
}


void insertAfter(NODE** start,int previousData,int data){


NODE* previousNode = search(*start,previousData);
NODE*temp = createNode(data);
if(previousData){

     temp->next = previousNode->next;
     previousNode->next->prev = previousNode->next = temp;
     temp->prev = previousNode;
      
   
}

}


void delete(NODE**  start,int data){


    NODE* toDelete = search(*start,data);

    if(toDelete){

        if(toDelete == *start){

            deleteFirst(start);
        }
        else{

        toDelete->prev->next=toDelete->next;
        toDelete->next->prev=toDelete->prev;
        free(toDelete);
    }
    }
}

int main()
{

    NODE *start = NULL;

    insertFirst(&start, 10);

    // insertFirst(&start, 20);

    // deleteLast(&start);
    // insertFirst(&start, 30);

    // display(start);

    // deleteLast(&start);
    // insertLast(&start, 40);
    insertLast(&start, 30);

   insertAfter(&start,30,20);
    // deleteFirst(&start);
    delete(&start,10);

    printf("   %d    ",start->next->data);

    // printf("%d",start->prev->prev->prev->data);

    display(start);


    // printf("%d",search(start,340)->data);

    return 0;
}