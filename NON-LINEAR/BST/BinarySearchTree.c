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

    if (*root == NULL) // if no node
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

    printf("%d [%p]  ", root->item, root);
    preorderRec(root->left);

    preorderRec(root->right);
}

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
        if (root->right) //after left then right as its queue we want to print Left to right and queue follows FIFO.
        {

            enqueue(&front, &rear, root->right);
        }

        // then dequeuing the left pointer ,printing the value it stores and then check its left and  root and follow same procedure.
    }
}

void delete_zero(BST **root, BST *parent, BST *ptr)
{

    if (parent == NULL)
    { // only one node is present ie the root node.

        free(ptr);
        *root = NULL;
    }
    else
    { // it is not the root node , but now we have to check whether the node to be deleted is the left one or the right one.

        if (parent->left == ptr)
        {
            parent->left = NULL;
            free(ptr);
        }
        else
        {

            parent->right = NULL;
            free(ptr);
        }
    }
}

void delete_one(BST **root, BST *parent, BST *ptr)
{

    if (parent == NULL) // it means it is the root node which is to be deleted , so we need to check  whether its child is left or right
    {
        if (ptr->left)
        {
            *root = ptr->left;
        }

        else
        {

            *root = ptr->right;
        }
        free(ptr);
    }
    else
    {

        // now i have to check whether the node is the left node or the right node which is to be deleted.

        if (parent->left == ptr) // now if that node is the left child then further we have to check if that node which is to be deleted has the right or the left child.
        {

            if (ptr->left) // check if the left node of the node to be deleted exists or not.
            {
                parent->left = ptr->left;
                free(ptr);
            }
            else
            {

                parent->left = ptr->right;
                free(ptr);
            }
        }
        else
        { // check if the node to be deleted is the right node.

            if (ptr->left) // check if the node of the node to be deleted exists or not.
            {
                parent->right = ptr->left;
                free(ptr);
            }
            else
            {

                parent->right = ptr->right;
                free(ptr);
            }
        }
    }
}

void delete (BST **root, int data)
{

    BST *ptr = *root, *parentptr = NULL;
    if (*root == NULL)
        printf("UNDERFLOW");
    else
    {

        while (ptr)
        {
            // search for the node to be deleted

            if (ptr->item == data)
            { //if the node to be deleted us the root node

                break;
            }
            else
            { // we need to check which is the node to delete whether it is in the left or the right

                if (ptr->item > data)
                { // if the data of the node to be deleted in less than the root got to tehb left node and search for it.

                    if (ptr->left)
                    {                    // if the left node is there or not.
                        parentptr = ptr; // parentptr points to the parent of the node to be deleted so that we can make chanegs in them while deleting the node whose address is in the ptr pointer.
                        ptr = ptr->left;
                    }
                }
                else
                {

                    if (ptr->right)
                    {
                        parentptr = ptr;
                        ptr = ptr->right;
                    }
                }
            }
        }
    }
    // now i have to check whether the node to be deleted has how many children?

    if (ptr->left == NULL && ptr->right == NULL) // checking for no left and right child
        delete_zero(root, parentptr, ptr);
    else if (ptr->left == NULL || ptr->right == NULL) // checking if one of the is present if both not present then the first condition sis satisfied.
        delete_one(root, parentptr, ptr);
    else
    { // it means it has both the left and right child

        BST *pred, *parentpred; // here pred denotes the predecessor of the node to be deleted which means the node with the value just smaller than the node'data value to be deleted.

        // move to the left and then go upto the right child of that left subtree is present .

        parentpred = ptr;
        pred = ptr->left;
        while (pred->right)
        {

            parentpred = pred;
            pred = pred->right;
        }

        // now we have to replace the value of the node to be deleted with its pred's value and then check if that pred has any child it cannot ahve the two childs as it is the right most child.

        ptr->item = pred->item;
        if (ptr->left) // if the left child is present then we have to call the deletone child otherwise the deletezero
            delete_one(root, parentpred, pred);
        else
            delete_zero(root, parentpred, pred);
    }

    // printf("%p to be deleted  ",parentptr); // i got the node to be deleted.
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
    // levelorder_R_L(root);
    // puts("");
    // levelorder_L_R(root);

    preorderRec(root);
    delete (&root, 40);
    puts("");
    preorderRec(root);
    delete (&root, 30);
    puts("");
    preorderRec(root);
    delete (&root, 50);
    delete (&root, 100);
    delete (&root, 2);
    delete (&root, 10);
    delete (&root, 20);
    delete (&root, 90);
    puts("");
    preorderRec(root);
    puts("");
    




    return 0;
}
