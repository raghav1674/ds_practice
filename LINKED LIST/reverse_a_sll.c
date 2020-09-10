#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef struct node
{

  int data;

  struct node *next;

} NODE;

void reverse(NODE **start)
{

    NODE *previous = *start;
    NODE *current = previous->next;
    NODE *next = previous->next;

   (*start)->next=NULL;

while(current!=NULL){
   
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
}

*start=previous;

}