#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
	int data;
	struct Node *next;
};


int hash(int data)
{
   return data%10;
}

void insertSort(struct Node **head, int data)
{
	struct Node *temp=*head;
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	
	if(temp!=NULL){

	while(temp->next!=NULL && data > temp->next->data)
	{
		temp=temp->next;
	}
		
	}
	else
	{
		*head=newNode;
		return;
	}
	
	newNode->next=temp->next;
	temp->next=newNode;
	
//	printf("Here");
}

struct Node* searchList(struct Node *head,int key)
{
	struct Node *temp=head;
	
	while(temp!=NULL && key!=temp->data)
	{
		temp = temp->next;
	}
	
	if(temp==NULL)
	{
		return NULL;
	}
	else
	{
		return temp;
	}
}
void insertToHash(struct Node **HM,int data)
{
	 int index = hash(data);
     insertSort(&HM[index],data);
//      printf("%d\t",HM[index]->data);
}

//here it is taking the address of the struct  Node** which is an array of pointers and HM[index] is having the adress of the index's start which is start in this case as every numbered index 
int searchHash(struct Node **HM,int data)
{
     int index = hash(data);
     struct Node *res = searchList(HM[index], data);
//     printf("\n%d data searched",res->data);
     if(res==NULL)
     return INT_MAX;
   
     return res->data;
   
   
}
int main()
{
//	A 10 sized array of pointer is created which is our hashmap
	struct Node **A=(struct Node**)malloc(sizeof(struct Node*)*10);
	
	for(int i=0;i<10;i++)
	A[i]=NULL;
	
	int arr[]={2,4,1,55,67,89,10,44,23,105};
	insertToHash(A,33);
	insertToHash(A,4);
	insertToHash(A,21);
	insertToHash(A,41);
	insertToHash(A,44);

	int result = searchHash(A,41);
	if(result == INT_MAX)
	printf("DATA NOT FOUND!");
	else
	printf("The result is: %d",result);
	
	return 0;
}