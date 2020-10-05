#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

BST *createBSTNode(int item)
{

    BST *temp = (BST *)malloc(sizeof(BST));
    temp->item = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void insert(BST **root, int data)
{
    BST *temp = createBSTNode(data);

    BST *ptr = *root;

    if (*root == NULL) // if one node
    {

        *root = temp;
    }
    else
    {
        while (1)
        { // we are travsing till infinitely

            if (ptr->item > data) // if the element to be inserted has less value go  to the left
            {
                if (ptr->left) // if left is not null then keep traversing to the left
                    ptr = ptr->left;
                else
                { // if its null then insert the node
                    ptr->left = temp;
                    break;
                }
            }
            else if (ptr->item < data)
            { // /if the element to be inserted has greater value go  to the right

                if (ptr->right) // if left is not null then keep traversing to the right

                    ptr = ptr->right;

                else
                { // if its null then insert the node

                    ptr->right = temp;
                    break;
                }
            }
            else
            {
                free(temp); // if duplicate then free the memory

                // printf("Already present with value %d......", data);
                break;
            }
        }
    }
}

bool isBSTEmpty(BST *root)
{

    return (root == NULL) ? true : false;
}

// iterative preorder
void preorder(BST *root)
{

    if (isBSTEmpty(root))
    {
        return;
    }

    STACK *top = NULL;

    push(&top, root);
    while (!isEmpty(top))
    {
        root = peek(top);
        printf("%d  ", root->item);
        pop(&top);
        if (root->right)
        {

            push(&top, root->right);
        }
        if (root->left)
        {

            push(&top, root->left);
        }
    }
}

// recursive preorder

void preorderRec(BST *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d   ", root->item);
    preorderRec(root->left);

    preorderRec(root->right);
}

// void inorder(BST *root)
// {
//     if (isBSTEmpty(root))
//         return;

//     STACK *top = NULL;
//     push(&top, root);
//     while (isEmpty(top))
//     {

//         if (root->left)
//         {

//             push(&top, root->left);
//             root = root->left;
//         }

//         else
//         {

//             root = peek(top);
//             printf("%d  ", root->item);

//             pop(&top);

//             if (root->right)
//                 root = root->right;
//             else
//                 root = peek(top);
//         }
//     }
// }

void levelorder_L_R(BST *root)
{

    QUEUE *front = NULL, *rear = NULL;


    if (isBSTEmpty(root)) 
    {

        return;
    }
    enqueue(&front, &rear, root); // inserting the root in the queue .

    while (!isQueueEmpty(rear))
    {

        root = peekQueue(front, rear); // getting the root and then printing the item to which it points

        printf("%d ", root->item);

        dequeue(&front, &rear);

        if (root->left) // then checking if its left child exists then insert into the queue
        {

            enqueue(&front, &rear, root->left);
        }
        if (root->right)//after left then right as its queue we want to print Left to right and queue follows FIFO.
        {

            enqueue(&front, &rear, root->right);
        }

        // then dequeuing the left pointer ,printing the value it stores and then check its left and  root and follow same procedure.
    }
}



void levelorder_R_L(BST *root)
{

    QUEUE *front = NULL, *rear = NULL;
    if (isBSTEmpty(root))
    {

        return;
    }
    enqueue(&front, &rear, root);

    while (!isQueueEmpty(rear))
    {

        root = peekQueue(front, rear);

        printf("%d ", root->item);

        dequeue(&front, &rear);

        if (root->right)
        {

            enqueue(&front, &rear, root->right);
        }
        if (root->left)
        {

            enqueue(&front, &rear, root->left);
        }
    }
}
int main()
{

    BST *root = NULL;

    // insertRec(&root, 40);
    // insertRec(&root, 2);

    insert(&root, 40);
    insert(&root, 20);
    insert(&root, 10);
    insert(&root, 30);
    insert(&root, 50);
    insert(&root, 90);

    insert(&root, 2);
    // insert(&root, 0);
    // insert(&root, 100);
    // insert(&root, 101);
    // insert(&root, 99);
    insert(&root, 100);
    // insert(&root, 89);
    // preorder(root);
    levelorder_R_L(root);
    puts("");
    levelorder_L_R(root);

    return 0;
}
