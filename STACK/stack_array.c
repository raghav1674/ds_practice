#include <stdio.h>

#include <stdlib.h>

typedef struct
{

    int capacity;
    int *arr;
    int top;

} STACK;

STACK *createStack(int capacity)
{

    STACK *array = (STACK *)malloc(sizeof(STACK));
    array->top = -1;
    array->capacity = capacity;
    array->arr = (int *)malloc(sizeof(int) * capacity);

    return array;
}

void push(STACK *array, int data)
{

    if (array->top == array->capacity-1)
    {
        printf("STACK OVERFLOW");
        exit(0);
    }
    else
    {

        array->top++;
        array->arr[array->top] = data;
    }
}

void pop(STACK *array)
{

    if (array->top == -1)
    {

        printf("STACK UNDERFLOW");
        exit(0);
    }
    else
    {

        array->top--;
    }
}

int peek(STACK *array)
{
     if (array->top == -1)
    {

        printf("STACK IS EMPTY");
        exit(0);
    }

    return array->arr[array->top];
}

int main()
{

    STACK *stack = createStack(4);
    push(stack, 10);

   
    push(stack,20);
    push(stack,20);
    push(stack,20);
    pop(stack);
    push(stack,20);
     
    
     
    // printf("%d ",value);

    return 0;
}
//here is code there i am implent using c++ 
#include <bits/stdc++.h> 
#include <iostream>
  
using namespace std; 
  
#define MAX 1000 
  
class Stack { 
    int top; 
  
public: 
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
int Stack::peek() 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        int x = a[top]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    class Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.pop() << " Popped from stack\n"; 
  
    return 0; 
} 
