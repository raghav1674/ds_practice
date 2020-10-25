
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct edge{

int u,v;

}EDGE;


typedef struct node
{

    int vertex;
    struct node *next;
} Vertex;

Vertex *create_vertex(int value)
{

    Vertex *new_vertex = (Vertex *)malloc(sizeof(Vertex));

    new_vertex->vertex = value;
    new_vertex->next = NULL;

    return new_vertex;
}

void insert_vertex(Vertex **head, int value)
{

    Vertex *new_vertex = create_vertex(value);
    if (*head == NULL)
    {

        *head = new_vertex;
    }
    else
    {

        Vertex *temp_head = *head;
        while (temp_head->next != NULL)
        {

            temp_head = temp_head->next;
        }

        temp_head->next = new_vertex;
    }
}