#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int coeff;
    int power;
    struct node *next;

} NODE;

NODE *create_node(int coeff, int power)
{

    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->coeff = coeff;
    temp->power = power;
    temp->next = NULL;

    return temp;
}

void push_back(NODE **head, int power, int coeff)
{

    NODE *temp = create_node(coeff, power);
    if (*head == NULL)
        *head = temp;
    else
    {

        NODE *temp_head = *head;
        while (temp_head->next != NULL)
            temp_head = temp_head->next;
        temp_head->next = temp;
    }
}

// int maximum_degree(NODE *head1, NODE *head2)
// {

//     NODE *temp1 = head1, *temp2 = head2;
//     int degree1 = 0, degree2 = 0;
//     while (temp1 != NULL)
//     {
//         if (degree1 < temp1->power)
//             degree1 = temp1->power;
//         temp1 = temp1->next;
//     }
//     while (temp2 != NULL)
//     {
//         if (degree2 < temp2->power)
//             degree2 = temp2->power;
//         temp2 = temp2->next;
//     }

//     return (degree1 >= degree2) ? degree1 : degree2;
// }

void add_polynomials(NODE *head1, NODE *head2, NODE **result)
{

   

    while (head1 && head2)
    {

        if ((head1->power == head2->power))
        {

            push_back(result, head1->power, (head1->coeff + head2->coeff));
            head1 = head1->next;
            head2 = head2->next;
        }

        else if (head1->power > head2->power)
        {
            push_back(result, head1->power, head1->coeff);
            head1 = head1->next;
        }
        else

        {

            push_back(result, head2->power, head2->coeff);
            head2 = head2->next;
        }
    }
    while(head1){

            push_back(result, head1->power, head1->coeff);
            head1 = head1->next;
        }
    while(head2){

            push_back(result, head2->power, head2->coeff);
            head2 = head2->next;

        }
    }



int main()
{

    NODE *head1 = NULL, *head2 = NULL, *result = NULL;

    push_back(&head1, 5, 3);
    push_back(&head1, 2, 2);
    // push_back(&head1, 1, -1);
    push_back(&head1, 0, 5);

    push_back(&head2, 3, 3);
    push_back(&head2, 2, 3);
    // push_back(&head2, 1, 4);
    push_back(&head2,0,5);

    add_polynomials(head1, head2, &result);

    while (result != NULL)
    {

        printf("%d^%d ", result->coeff, result->power);
        result = result->next;
    }
}