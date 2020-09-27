#include <stdio.h>
#include <stdlib.h>

#include "stack.c"

BT *createBTNode(char item)
{

    BT *temp = (BT *)malloc(sizeof(BT));
    temp->item = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int isEmpty(BT *root)
{

    return root == NULL ? 1 : 0;
}

void BTtraversal(BT *root)
{

    if (isEmpty(root)) //if empty
    {
        printf("EMPTY TREE");
        return;
    }
    STACK *top = NULL;

    push(&top, root); // first push the root to teh stack

    while (!isStackEmpty(top)) // traverse till the stack is empty
    {
        root = peek(top); // then get the address of the node from teh stack which is at the top

        printf("%c ", root->item); // print it's item value.

        pop(&top); // pop it.

        if (root->right) // check if it's right exists or not. if exists push it to the stack
        {
            push(&top, root->right);
        }
        if (root->left) //  check if it's left exists or not. if exists push it to the stack
        {
            push(&top, root->left);
        }
    }
}

void BTtraversalRec(BT *root)
{

    if (root == NULL)
        return;

    printf("%c ", root->item); // first print the value of the item to which root is pointing.

    BTtraversal(root->left); // pass the left to the traversal call

    BTtraversal(root->right); // after the left has been done then call function by pasing the left node address.
}
// FUNCTION CALL STACKS

/*  
   
   
   push(a) -> push(b) ->push(d) -> pop(d) -> push(e) -> push(h) -> pop(h) -> pop(e) -> pop(b) 

   push(c) -> push(f) -> push(m) -> pop(m) ->push(k) ->pop(k)->pop(f) ->push(g) ->pop(g) -> pop(c) -> pop(a).


*/
int main()
{

    BT *root = NULL, *lroot = NULL, *rroot = NULL;
    root = createBTNode('a');

    lroot = createBTNode('b');
    rroot = createBTNode('c');
    root->left = lroot;
    root->right = rroot;

    lroot->right = createBTNode('e');
    lroot->left = createBTNode('d');
    rroot->right = createBTNode('g');

    rroot->left = createBTNode('f');

    lroot->right->left = createBTNode('h');
    rroot->left->left = createBTNode('m');
    rroot->left->right = createBTNode('k');
    BTtraversalRec(root);

    return 0;
}
