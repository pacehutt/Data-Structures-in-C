#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *last = NULL;
void append(int item)
{
	struct Node *newNode;
	    newNode=(struct Node*)malloc(sizeof(struct Node));
	    newNode->data=item;
	    newNode->next=NULL;
	    
	    if(last == NULL)
	    {
	    	//last=newNode;
	    	//last->next=newNode;
	    	
	    	
	    	  //last = newNode;
	    	  //last->next=last;
	    	
	    	newNode->next = newNode;
	    	last=newNode;
		}
		else
		{
			newNode->next=last->next;
			last->next = newNode;
			last=newNode;
		}
}
void deleteAny(int sd)
{
	struct Node *c,*p;
	c=last->next;
	p=last;
	int flag = 0;
	
	do
	{
		if(c->data != sd)
		{
		p=c;
		c=c->next;
		}
		else
		  {
		  	flag = 1;
		  	break;
		  }
		
	}
	while(c != last->next);
	
	if(flag == 0)
	{
		printf("\n %d DATA NOT FOUND!!\n",sd);
		return;
	}
	p->next=c->next;
	c->next=NULL;
	if(c == last)
	{
		last = p;
	}
	if(c == last && p == last)
	{
		last = NULL;
	}
	free(c);
	
	
	
		
}
void insertAtFirst(int item)
{
	struct Node *newNode;
	newNode =(struct Node*)malloc(sizeof(struct Node));
	newNode->data=item;
	newNode->next=NULL;
	
	if(last == NULL)
	{
		newNode->next=newNode;
		last = newNode;
	}
	else
	{
		newNode->next = last->next;
		last->next=newNode;
	}
}

void insertAfter(int sd , int item)
{
	struct Node *c;
	int flag = 0;
	  if(last == NULL)
	  {
	  	printf(" EMPTY LIST !! ");
	  	return;
	  }
	
	   c  = last->next;
	 
	 do
	 {
	 	if(c->data != sd)
	 	{
	 		c=c->next;
		 }
		 else
		 {
		 	flag = 1;
		 	break;
		 }
	 }
	 while(c!=last->next);
	 
	 if(flag == 0)
	 {
	 	printf("\n%d not found!!\n",sd);
	 }
	 else
	 {
	 	struct Node *newNode;
	 	newNode = (struct Node*)malloc(sizeof(struct Node));
	 	newNode->data = item;
	 	newNode->next = NULL;
	 	
	 	newNode->next = c->next;
	 	c->next=newNode;
	 	
	 	if(c == last)
	 	{
	 		last = newNode;
		 }
	 }
	 
	 
	 
}

void display()
{
	if(last == NULL)
	{
		printf("LIST IS EMPTY");
		return;
	}
	struct Node  *i = last->next;
	printf("\nfirst node address :: %u \n",last->next);
	do
	{
		printf("|%d|%u|-->",i->data,i->next);
		i=i->next;
	}while(i!=last->next);
}
int main()
{

      while(1)
      {
      	printf("\n0.Exit");
      	printf("\n1.Append\n");
      	printf("2.Insert After\n");
      	printf("3.Insert Before\n");
      	printf("4.Delete Any\n");
      	printf("5.Display\n");
      	
      	
      	int c;
      	scanf("%d",&c);
      	switch (c)
      	{
      		case 1: 
      		  printf("\nEnter Data:");
			  scanf("%d",&c);
			  append(c);
			  break;
			case 2: 
			  printf("\nEnter search Data:");
			  scanf("%d",&c);
			  printf("\nEnter new Data:");
			  int t;
			  scanf("%d",&t);
			  insertAfter(c,t);
			  break;
			case 3: 
			  printf("\nEnter Data:");
			  scanf("%d",&c);
			  insertAtFirst(c);
			  break;
			case 4: 
			 printf("\nEnter Data:");
			  scanf("%d",&c);
			  deleteAny(c);
			  break;
			case 5:
			 display(); 
			  break;
			default:
			  return 0;    
			      
			    
		  }
      	
	  }
	  
	return 0;
}