#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int info;
	int pri;
	struct node *next;
};

void insert(struct node **s, int p, int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node)); // create a new node.
	temp->info = data;
	temp->pri = p;
	temp->next = NULL;


	//when Queue is empty
	if (*s == NULL)
	{

		*s = temp;
	}

	//when p is equal or less than exist priority

	else if ((*s)->pri >= p)
	{
		//when Queue has only one node

		if ((*s)->next == NULL)
		{

			(*s)->next = temp;
		}

		else 							// traverse till you reach a node with lesser priority than the element to be inseretd priority
		{

			struct node *t, *prev;
			t = *s;
			while (t->next != NULL) 	// traversing till end to check if the priority of last element is same or greater than the newly created node
			{
				t = t->next;
			}
			if (t->pri>=temp->pri) 		// if the priority of last node is same of greater than the newly created element then insert it at the last 
			{

				t->next = temp;
			}
			else     				  // otherwise check till the element with less priority is found.
			{
				t = *s;
				while (t->pri >= temp->pri)
				{
					prev = t;
					t = t->next;
				}
				temp->next = prev->next;
				prev->next = temp;
			}
		}
	
}

else 								// priority is greater than the front element ( just simply insert at the begining)
{
	
	temp->next = *s;
	*s = temp;
}
}

void delete (struct node **s)
{
	struct node *t;
	t = *s;
	*s = t->next;
	free(t);
}

//display function
void display(struct node **s)
{
	if (*s == NULL)
		printf("Queue is empty");
	else
	{
		struct node *t;
		t = *s;
		do
		{
			printf("data is %d and priority is %d\n", t->info, t->pri);
			t = t->next;
		} while (t != NULL);
	}
}

int menu()
{
	int choice;
	printf("1.insert data\n");
	printf("2.delete data\n");
	printf("3.display data\n\n");
	printf("enter your choice");
	scanf("%d", &choice);
	return (choice);
}

int main()
{
	struct node *front = NULL;
	while (1)
	{
		int data, p;
		switch (menu())
		{
		case 1:
			printf("enter data");
			scanf("%d", &data);
			printf("enter priority");
			scanf("%d", &p);
			insert(&front, p, data);
			break;
		case 2:
			delete (&front);
			break;
		case 3:
			display(&front);
			break;
		default:
			printf("enter invalid choice");
			exit(0);
			getch();
		}
		getch();
		system("cls");
	}
	return 0;
}
