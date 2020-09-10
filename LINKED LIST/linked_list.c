#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef struct node
{

  int data;

  struct node *next;

} NODE;

NODE *createNode(int data)
{

  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  temp->data = data;
  temp->next = NULL;
}

void addFirst(NODE **start, int data)
{

  NODE *temp = createNode(data);

  temp->next = *start;
  *start = temp;
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
  }
}

NODE *search(NODE *start, int prevdata)
{

  while (start != NULL)
  {

    if (start->data == prevdata)
      return start;
    // printf("hello ");
    start = start->next;
  }

  return NULL;
}

void insertAfter(NODE *start, int previousData, int data)
{

  NODE *t = search(start, previousData);
  //  printf("inside next %d   ",t->data);

  if (t)
  {

    NODE *newNode = createNode(data);

    newNode->next = t->next;
    t->next = newNode;
  }
  else
  {

    printf("\nNo such Node with the value of %d\n", previousData);
    exit(0);
  }
}

void deleteFirst(NODE **start)
{

  if (*start == NULL)
  {
    printf("No Node to delete");
    exit(0);
  }
  else
  {

    NODE *temp = *start;
    *start = (*start)->next;

    free(temp);
  }
}

void deleteLast(NODE **start)
{
  if (*start == NULL)
  {
    printf("No Node to delete");
    exit(0);
  }

  else if ((*start)->next == NULL)
  {
    free(start);
    *start = NULL;
    printf("List is Empty\n");
  }
  else
  {
    NODE *t;
    NODE *temp = *start;
    while (temp->next != NULL)
    {
      t = temp;
      temp = temp->next;
    }

    t->next = NULL;
    free(temp);
  }
}

void delete (NODE **start, int data)
{

  NODE *temp = *start;

  NODE *t = search(temp, data);

  if (t)
  {
    if (t == *start)
    {

      *start = t->next;
      free(t);
    }
    else
    {

      while (temp->next != t)
      {
        temp = temp->next;
      }
      temp->next = t->next;
      free(t);
    }
  }
}

void display(NODE *start)
{

  if (start == NULL)
    printf("List is Empty.\n");
  else
  {
    while (start != NULL)
    {

      printf("%d ", start->data);
      start = start->next;
    }
  }
}



int menu()
{

  int choice;
  printf("\nPRESS 1: TO INSERT AT THE BEGINNING \n");
  printf("PRESS 2: TO INSERT AT THE END \n");
  printf("PRESS 3: TO INSERT AFTER A GIVEN DATA \n");
  printf("PRESS 4: TO DELETE FROM THE BEGINNING \n");
  printf("PRESS 5: TO DELETE FROM THE BEGINNING \n");
  printf("PRESS 6: TO DELETE THE NODE WITH GIVEN DATA \n");
  printf("PRESS 7: TO VIEW THE LIST. \n");
  printf("PRESS 8: TO EXIT THE PROGRAM. \n");

  printf("\nENTER YOU CHOICE: ");
  scanf("%d", &choice);
  return choice;
}

int main()
{

  NODE *start = NULL;

  while (1)
  {

    int prevData;
    int data;
    switch (menu())
    {

    case 1:
      printf("Enter the data to insert at the beginning: \n");
      scanf("%d", &data);
      addFirst(&start, data);
      break;
    case 2:
      printf("Enter the data to insert at the end: \n");
      scanf("%d", &data);
      addLast(&start, data);
      break;
    case 3:
      printf("Enter the data to insert: \n");
      scanf("%d", &data);
      printf("Enter the data after which you want to insert: \n");
      scanf("%d", &prevData);
      insertAfter(start, prevData, data);
      break;
    case 4:
      deleteFirst(&start);
      printf("Data at the beginning is deleted.\n");
      break;
    case 5:
      deleteLast(&start);
      printf("Data at the last is deleted.\n");
      break;
    case 6:
      printf("Enter the data to delete : \n");
      scanf("%d", &data);
      delete (&start, data);
      break;

    case 7:
      printf("Current List: \n");
      display(start);
      printf("\n");
      break;
    case 8:
      printf("Thanks for choosing our program.\n");
      exit(0);
    }
    getch();
    system("cls");
  }

  // addFirst(&start, 20);

  // //  display(start);
  // addFirst(&start, 30);

  // addLast(&start, 80);

  // insertAfter(start, 20, 40);

  // // addLast(&start, 90);

  // deleteFirst(&start);

  // deleteLast(&start);

  // delete(&start, 20);
  // delete(&start, 40);

  // display(start);

  return 0;
}