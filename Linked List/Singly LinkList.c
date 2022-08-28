#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct Node *start = NULL;
struct Node *last = NULL;

void append(int item)
{
	struct Node *newNode;
	 newNode =(struct Node*)malloc(sizeof(struct Node));
	 newNode->data = item;
	 newNode->next = NULL;
	 
	  if(start == NULL)
	  {
	  	start = newNode;
	  	last = newNode;
	  }
	  else
	  {
	  	last->next = newNode;
	  	last = newNode;
	  }
}

void display()
{
	struct Node *i ;
	  i = start;
	  while( i != NULL )
	  {if(i->next == NULL)
	  {
	  		printf("| %d | %u  |\t",i->data,i->next);
	  }
	  else
	  	printf("| %d | %u  | --> \t",i->data,i->next);
	  	
	  	i = i->next;
	  }
}
void insertAtFirst(int item)
{

		
	
	struct Node* newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=item;
	newNode->next=NULL;
     if(start==NULL)
     {
     	start=newNode;
     	last=newNode;
	 }
	 else
	 {
	 	newNode->next=start;
	 	start=newNode;
	 }
     
}
void insertAfter(int sd,int item)
{
	  struct Node *current;
	   current = start;
	   while(current!=NULL && current->data != sd)
	   {
	   	 current = current->next;
	   }
	   if(current == NULL)
	   {
	   	printf("\n%d not found\n",sd);
	   	return;
	   }
	   
	   struct Node *newNode;
	   newNode = (struct Node*)malloc(sizeof(struct Node));
	   newNode->data = item;
	   newNode->next=NULL;
	    
		  if(current->next == NULL)
	      {
	      	last = newNode;
		  }
		  
	      newNode->next = current->next;
	      current->next = newNode;
	      
	  
	     
}

void insertBefore(int sd,int item)
{
	  struct Node *current,*previous;
	   current = start;
	   previous = NULL;
	   while(current!=NULL && current->data != sd)
	   {
	   	  previous = current;
	   	 current = current->next;
	   }
	   if(current == NULL)
	   {
	   	printf("\n%d not found\n",sd);
	   	return;
	   }
	   
	   struct Node *newNode;
	   newNode = (struct Node*)malloc(sizeof(struct Node));
	   newNode->data = item;
	   newNode->next=NULL;
	    
		  if(previous == NULL)
	      {
	          start = newNode;
		  }
		  else
		  {
		  	 previous->next = newNode;
		  }
		  newNode->next = current;
		   
}
void insertSort(int item)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = item;
	newNode->next = NULL;
	struct Node * current , * previous;
	if(start == NULL)
	{
		start = newNode;
		last  = newNode;
	}
	else
	{
		 current = start ;
		 previous = NULL;
		  while(current != NULL && item > current->data)
		  {
		  	previous = current;
		  	current = current->next;
		  }
		  
		  newNode->next = current;
		  if(previous!=NULL)
		  previous->next=newNode;
		  else
		  start=newNode;
		  
		  if(current == NULL)
		  {
		  	last = newNode;
		  }
		  
		 
	}
}
void deleteFirst()
{
	struct Node * ptr = start ;
	if(start == NULL)
	{
		return;
	}
	start = start->next;
	ptr->next = NULL ;
	if(start == NULL)
	{
		last = NULL;
	}
	free(ptr);
}
void deleteLast()
{
	   if(start == last)
	   {
	   	  if(start!=NULL)
	   	    free(start);
	   	    
	   	 start = last = NULL;
	   	 return ;
	   }
	   
	   struct Node *current = start;
	   while(current->next->next != NULL)
	   {
	   	 current=current->next;
	   }
	   
	   free(last);
	   last = current;
	   last->next = NULL;
	
}

void reverse()
{
	  struct Node *p,*q,*r;
	   p = start;
	   q = NULL;
	   r = NULL;
	   
	   while(p != NULL)
	   {
	   	  r = q;
	   	  q = p;
	   	  p = p->next;
	   	  q->next = r;
	   }
	   last = start ;
	   start = q;
}
int search(int sd)
{
	struct Node *c = start;
	while(c != NULL)
	{
		if(c->data == sd)
		{
			return 1;
		}
		c=c->next;
	}
	return 0;
}
void deleteAny(int sd)
{
	struct Node *c,*p;
	c = start;
	p = NULL;
	while(c != NULL && c->data != sd)
	{
		p = c;
		c = c->next;
	}
	
	if(p == NULL)
	{
		start = start->next;
		  if(start == NULL)
		  {
		  	 last = NULL;
		  }
		c->next=NULL;
		free(c);
		return;
	}
	p->next = c->next;
	c->next = NULL;
	free(c);
	if(p->next==NULL)
	{
		last = p;
	}
}

int countNode()
{
	struct Node *i = start ;
	int count = 0;
	while(i != NULL)
	{
		count++;
		i=i->next;
	}
	return count;
}
void insertAtAnyPos(int d,int pos)
{
	struct Node *c,*p;
	int count = 1;
	c=start;
	p=NULL;
	while(count < pos)
	{
		p = c;
		c = c->next;
		count++;
	}
	
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = d;
	newNode->next = NULL;
	if(p == NULL)
	{
		newNode->next = c;
		start  = newNode;
		 if(last == NULL)
		 {
		    last = newNode;
		 }
	}
	else if(c == NULL)
	{
		p->next = newNode;
		last = newNode;
	}
	else
	{
	p->next = newNode;
	newNode->next = c;
	}

}
int main()
{ int ch;
int data;
int sdata;
	while(1)
	{
		
	
	printf("\nMenu:\n");
	printf("1:Append\n");
	printf("2:Display\n");
	printf("3:Exit\n");
	printf("4:Insert At First:\n");
	printf("5:Insert After :\n");
	printf("6:Insert Before:\n");
	printf("7:Insert Sort :\n");
	printf("8:Delete First :\n");
	printf("9:Delete Last :\n");
	printf("10:Reverse :\n");
	printf("11:Delete Any :\n");
	printf("12:Insert At Any Position:\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: 
		
		printf("\nEnter Data:");
		scanf("%d",&data);
		append(data);
		break;
	    case 2:
	    	printf("\n");
	    	display();
	    	break;
	    case 3: exit(0);
		break;	
		case 4:
			printf("\nEnter Data:");
		scanf("%d",&data);
		insertAtFirst(data);
		break;
		case 5:
			printf("\nEnter Search Data:");
		    scanf("%d",&sdata);
		    printf("\nEnter Data:");
	    	scanf("%d",&data);
		    insertAfter(sdata,data);
		break;
		case 6:
			printf("\nEnter Search Data:");
		    scanf("%d",&sdata);
		    printf("\nEnter Data:");
	    	scanf("%d",&data);
		    insertBefore(sdata,data);
		break;
		case 7:
			printf("\nEnter Data:");
		scanf("%d",&data);
		insertSort(data);
		break;
		case 8:
		
		 deleteFirst();
		break;
		case 9:
		
		 deleteLast();
		break;
		case 11:
		 printf("\nEnter Data:");
		 scanf("%d",&data);
		  if( search(data) )
		    {
		    	deleteAny(data);
			}
		 else
		    {
		    	 printf("\n%d Element Not Found",data);
			}
		break;
		case 10:
			reverse();
			break;
		case 12:
			     printf("\nEnter Position ::");
			     scanf("%d",&sdata);
			      if(sdata < 1 || sdata > countNode()+1)
			          printf("\nInvalid Position!!\nAllowed Position Range :1 to %d",countNode()+1);
			      else
			          {
			          	printf("\nEnter Data:");
		                scanf("%d",&data);
			          	insertAtAnyPos(data,sdata);
					  }
					break;  
			          
		default:printf("Invalid choice!!");
	
	}
}	
	getch();
	return 0;
}