#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum bool
{

    false,
    true
} BOOL;

typedef struct node
{

    char data[2];
    struct node *next;

} NODE;

NODE *create_node(char *data)
{

    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    strcpy(new_node->data, data);
    new_node->next = NULL;

    return new_node;
}

void push_back(NODE **head, char *data)
{

    NODE *new_node = create_node(data);
    if (*head == NULL)
        *head = new_node;
    else
    {
        NODE *temp = *head;
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = new_node;
    }
}