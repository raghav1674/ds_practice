#include <stdio.h>
#include <stdlib.h>

int size;

// bool datatype
typedef enum boolean
{
    false,
    true
} bool;



// Node structure
typedef struct Node
{

    int data;
    struct Node *next;

} NODE;


// global head pointer
NODE *head = NULL;


// check if the list is empty or not
bool isEmpty()
{
    return head == NULL ? true : false;
}

// returns the current elements in the list
int length()
{

    return size;
}


// prints the  elements in the list
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


// creates a new node
NODE* createNode(int data)
{

    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


// inserts the element with given data at the beginning of the list
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

// inserts the element with given data at the end of the list
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

// inserts the element with given data within the current size of that list
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


// deletes the element from the beginning of the list
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

// deletes the element from the given index of the list
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

// deletes the element from the end of the list
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


// returns 0 if element not found in the list otherwise returns 1
bool contains(int data)
{
    
    NODE *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return true;
        
        }
        temp = temp->next;
    }
    
     return false;
}

// returns the first index of the given element in the list , if not present returns -1

int firstIndexOf(int data)
{

    NODE *temp = head;
    int index, i = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
           
            return i;

        }
        i++;
        temp = temp->next;
    }
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
