#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_function(int roll_no)
{

    return (roll_no) % 100;
}

typedef struct stud
{

    int roll_no;
    char name[100];

} STUDENT;

void get_details(STUDENT s)
{

    printf("ROLL NO: %d\nNAME: %s\n\n", s.roll_no, s.name);
}
typedef struct node
{

    STUDENT data;
    struct node *next;

} NODE;

NODE *create_student_node(STUDENT student)
{

    STUDENT new_student;
    new_student.roll_no = student.roll_no;
    strcpy(new_student.name, student.name);

    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->data = new_student;

    return temp;
}

NODE *push_back(NODE *head, STUDENT new_student)
{

    NODE *new_node = create_student_node(new_student);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        NODE *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new_node;
    }
    return head;
}

void put(NODE **arr, STUDENT new_student)
{

    int index = hash_function(new_student.roll_no);

    arr[index] = push_back(arr[index], new_student);
}

 // TODOvoid get(int roll_no, NODE **arr)
// {

    


// }

int main()
{

    NODE *array[100];
    for (int i = 0; i < 100; ++i)
    {

        array[i] = NULL;
    }
    STUDENT s = {23, "Raghav"};
    STUDENT s1 = {122, "Ajay"};
    STUDENT s3 = {1122, " RAM"};
    STUDENT s4 = {22, "IAM"};

    put(array, s4);

    put(array, s1);

    put(array, s3);

    // get(1122, array);

    get(111223, array);
    get(122, array);

    return 0;
}
