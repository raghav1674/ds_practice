#include <stdio.h>
#include <stdlib.h>

int size;


typedef enum boolean
{
    false,
    true
} bool;




typedef struct Node
{

    int data;
    struct Node *next;

} NODE;

NODE *head = NULL;

bool isEmpty()
{
    return head == NULL ? true : false;
}

int length()
{

    return size;
}

void display()
{

    NODE *temp = head;

    if (isEmpty())
    {
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

NODE* createNode(int data)
{

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void addFirst(int data)
{

    NODE *newNode = createNode(data);
    if (isEmpty())
    {

        head = newNode;
        size++;
        return;
    }

    newNode->next = head;
    head = newNode;
    size++;
}

void addLast(int data)
{

    NODE *newNode = createNode(data);
    if (isEmpty())
    {

        head = newNode;
        size++;
        return;
    }
    NODE *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

void insert(int data, int index)
{

    NODE *newNode = createNode(data);
    NODE *temp = head;
    int i = 0;
    if (index < 0 || index >= size)
    {
        printf("INDEX_OUT_OF_BOUND\nThe specified index is either negative or greater than than the current length of list.\nCurrent length of the list is %d", size);
        return;
    }

    if (index == 0)
    {
        addFirst(data);
        return;
    }
    while (i < index - 1)
    {

        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    size++;
}

void removeFirst()
{
    
    if (isEmpty())
    {
        printf("List is empty.\n");
        return;
    }

    NODE *temp = head;
    head = head->next;

    free(temp);
    size--;
}


void removeAt(int index){

  NODE* temp=head;
  NODE* ptr;
  int i=0;
  if (index < 0 || index >= size)
    {
        printf("INDEX_OUT_OF_BOUND\nThe specified index is either negative or greater than than the current length of list.\nCurrent length of the list is %d\n", size);
        return;
    }
  if(index==0){
      removeFirst();
    
      return;
  }
  if(!isEmpty()){
  while(i<index-1){
    
    temp=temp->next;
  
    i++;
  } 
 ptr=temp->next;
 temp->next=ptr->next;
 free(ptr);
 size--;

}


}


void removeLast()
{

    if(size == 1 || isEmpty()){

        removeFirst();
        return;
    }   
    NODE *ptr;
    NODE *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    ptr = temp->next;

    temp->next = NULL;

    free(ptr);
    size--;
}

bool contains(int data)
{
    bool isPresent = false;
    NODE *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            isPresent = true;
            break;
        }
        temp = temp->next;
    }
    if (isPresent)
        return true;
    else
        return false;
}

int firstIndexOf(int data)
{
    bool isPresent = false;
    NODE *temp = head;
    int index, i = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            isPresent = true;
            index = i;

            break;
        }
        i++;
        temp = temp->next;
    }
    if (isPresent)
        return index;
    else
        return -1;
}



int main()
{
    addLast(200);
    // addFirst(10);
    // addLast(401);
    // insert(801, 1);
    insert(801, 0);]

    addFirst(901);
    addFirst(901);
    addFirst(901);
    // removeAt(0);
    
    // printf("%d\n",contains(1));
     printf("%d\n",indexOf(901));

    // removeLast();
    // removeLast();
  
    // removeLast();

 
    // removeFirst();
    // removeFirst();
    printf("%d\n", length());
    display();
}
