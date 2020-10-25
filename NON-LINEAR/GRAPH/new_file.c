#include<stdio.h>
#include<stdlib.h>
struct Array
{
	int capacity;
	int lastIndex;
	int *ptr;
};
struct Array* createArray(int cap)
{
	struct Array *arr;
	arr=(struct Array*)malloc(sizeof(struct Array*));
	arr->capacity=cap;
	arr->lastIndex=-1;
	arr->ptr=(int*)malloc(sizeof(int)*cap);
	return arr;
}
void insert(struct Array* arr,int index,int data)
{
	int i;
	if(index<0 || index>arr->lastIndex+1)
		printf("Invalid Index");
	else if(arr->capacity==arr->lastIndex+1)
		printf("Overflow");
	else
	{
		for(i=arr->lastIndex;i>index;i--)
			arr->ptr[i+1];arr->ptr[i];
		arr->ptr[index]=data;
		arr->lastIndex+=1;
	}
}
void append(struct Array *arr,int data)
{
	if(arr->lastIndex+1==arr->capacity)
		printf("Overflow");
	else
	{
		arr->lastIndex+=1;
		arr->ptr[arr->lastIndex]=data;
	}
}
void deleteValue(struct Array *arr,int index)
{
	int i;
	if(arr->lastIndex==-1)
		printf("Underflow");
	if(index<0 || index>arr->lastIndex+1)
		printf("Invalid Index");
	for(i=index;i<arr->lastIndex;i++)
		arr->ptr[i]=arr->ptr[i+1];
	arr->lastIndex-=1;
}
void searchValue(struct Array *arr,int data)
{
	int i;
	for(i=0;i<=arr->lastIndex;i++)
	{
		if(arr->ptr[i]==data)
			break;
	}
	printf("Value found at Index= %d\n",i);
}
int getValue(struct Array *arr, int index)
{
	if(index<0 || index>arr->lastIndex+1)
		return 0;
	else
		return(arr->ptr[index]);
}
int count(struct Array *arr)
{
	return(arr->lastIndex+1);
}
void editValue(struct Array *arr,int index,int data)
{
	if(index<0 || index>arr->lastIndex+1)
		printf("Invalid Index");
	else
		arr->ptr[index]=data;
}
int menu()
{
	int choice;
	printf("\n1. Insert Value");
	printf("\n2. Append Value");
	printf("\n3. Print Array Values");
	printf("\n4. Delete Value");
	printf("\n5. Count Values");
	printf("\n6. Edit Value");
	printf("\n7. Exit\n");
	printf("\nEnter your Choice : \n");
	scanf("%d",&choice);
	return choice;
}
int main()
{
	int index,data,i;
	struct Array* arr;
	arr=createArray(10);
	while(1)
	{
		switch(menu())
		{
			case 1:
				printf("Enter Index and data to insert\n");
				scanf("%d%d",&index,&data);
				insert(arr,index,data);
				break;
			case 2:
				printf("Enter data to append\n");
				scanf("%d",&data);
				append(arr,data);
				break;
			case 3:
				printf("\n");
				for(i=0;i<count(arr);i++)
					printf(" %d",getValue(arr,i));
				
				break;
			case 4:
				printf("Enter index to delete value\n");
				scanf("%d",&index);
				deleteValue(arr,index);
				break;
			case 5:
				count(arr);
				break;
			case 6:
				printf("Enter index and new data to edit\n");
				scanf("%d%d",&index,&data);
				editValue(arr,index,data);
				break;
			case 7:
				printf("Thank You, Press any key to exit...\n");
				exit(0);
			default:
				printf("Invalid choice\n");
		}
		
	}
}
