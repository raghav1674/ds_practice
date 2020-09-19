#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Q
{
    int head, tail;
    int capacity;
    int *ptr;
};

struct Q *createqueue(int cap)
{
    struct Q *q;
    q = (struct Q *)malloc(sizeof(struct Q));
    q->capacity = cap;
    q->head = -1;
    q->tail = -1;
    q->ptr = (int *)malloc(sizeof(int) * cap);
    return q;
}

void insertattail(struct Q *q, int data)
{
    if (q->head == 0 && q->tail == q->capacity - 1 )
    {

        printf("queue is full");
        return;
    }
    if ((q->tail == q->capacity - 1))
        printf("\ncan't insert from the tail");
    else if (q->tail == -1)
    {
        q->tail++;
        q->head++;
        q->ptr[q->tail] = data;
    }

    else
    {
        q->tail++;

        q->ptr[q->tail] = data;
    }
}

void deleteattail(struct Q *q)
{

    if (q->tail == -1)
        printf("\nUnderflow");
    else if (q->head == q->tail)
        q->head = q->tail = -1;
    else
    {

        q->tail--;
    }
}

void deleteathead(struct Q *q)
{

    if (q->head == q->capacity)
        printf("\nUnderfloww");
    else if (q->head == q->tail)
        q->head = q->tail = -1;

    else
    {

        q->head++;
    }
}

void insertathead(struct Q *q, int data)

{

    if (q->head == 0 && q->tail == q->capacity - 1)
    {

        printf("queue is full");
        return;
    }
    if (q->head - 1 == -1)
        printf("\nCan't insert at the head");
    else if (q->head == -1 && q->tail == -1)
    {
        q->head++;
        q->tail++;
        q->ptr[q->head] = data;
    }

    else
    {

        q->head--;
        q->ptr[q->head] = data;
    }
}

void viewqueue(struct Q *q)
{
    if (q->tail == -1)
    {
        printf("\nEMPTY");
        return;
    }
    int i;
    for (i = q->head; i <= q->tail; i++)
    {
        printf("\nHEAD = %d\tTAIL = %d\n%d[INDEX-[%d]]\t", q->head, q->tail, q->ptr[i], i);
    }
}

int menu()
{
    int ch;
    printf("\n1.Insertion at tail");
    printf("\n2. Deletion at tail");
    printf("\n3.view queue");
    printf("\n4.insertion at head");
    printf("\n5.delteion at head");
    printf("\n6. Exit");
    printf("\n\nEnter the choice");
    scanf("%d", &ch);
    return ch;
}
int main()
{
    int cap, data;
    struct Q *q;
    printf("\nEnter the capacity of the queue");
    scanf("%d", &cap);
    q = createqueue(cap);

    while (1)
    {

        switch (menu())
        {
        case 1:
            printf("\nEnter the data");
            scanf("%d", &data);
            insertattail(q, data);
            break;

        case 2:
            deleteattail(q);
            break;
        case 3:
            viewqueue(q);
            break;
        case 4:
            printf("\nEnter the data");
            scanf("%d", &data);
            insertathead(q, data);
            break;
        case 5:
            deleteathead(q);
            break;
        case 6:
            exit(0);
        default:
            printf("\n\n\nWrong choice,try another");
            break;
        }
        getch();
        system("cls");
    }
}
