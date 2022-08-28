#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct Node
{
    
	int data;
	struct Node *next;
};

struct Node* reverse(struct Node*);

void create(struct Node **p)
{
	struct Node *t,*last=NULL;
	int n,c,i;
	printf("\nEnter How Many Terms ?");
	scanf("%d",&n);
	
	for( i = 1 ; i <= n ; i++)
	{
		printf("\nTerm %d : ",i);
		t = (struct Node*)malloc(sizeof(struct Node));
		printf("\nEnter Data :");
		scanf("%d",&c);
	
		
		t->data=c;
		t->next=NULL;
		if(*(p) == NULL)
		{
			*(p)=last=t;
		}
		else
		{
			last->next = t;
			last = t;
		}
	}
	
}
void display(struct Node *p )
{
	struct Node *i ;
	  i = p;
	  if(!i)
	  {
	  	printf("\nList is Empty!\n");
	  	return;
	  }
	  while( i != NULL )
	  {
	  
	  if(i->next == NULL)
	  {
	  		printf("| %d | %u  |\t",i->data,i->next);
	  }
	  else
	  	printf("| %d | %u  | --> \t",i->data,i->next);
	  	
	  	i = i->next;
	  }
}

	
int palindrome(struct Node *head)
{
	struct Node *slow,*fast,*temp;
	slow=fast=head;

	
	while(fast->next && fast->next->next) 
	{
		slow=slow->next;
		fast=fast->next->next;
	}
//	When fast reaches last node or 2nd last node slow reaches the mid
//    Reverse the list from mid+1
     
    slow->next = reverse(slow->next);
  
    slow=slow->next;
    temp=head;
    while(slow!=NULL)
    {
    	if(slow->data!=temp->data)
    	return 0;
    	
    	slow=slow->next;
    	temp=temp->next;
    	
	}
    
    return 1;
   
	
}
	
struct Node* reverse(struct Node *head)
{
	  struct Node *p,*q,*r;
	   p = head;
	   q = NULL;
	   r = NULL;
	   
	   while(p != NULL)
	   {
	   	  r = q;
	   	  q = p;
	   	  p = p->next;
	   	  q->next = r;
	   }
	   head = q;
	   return head;
}
int main()
{
	struct Node *list=NULL;
	create(&list);
	display(list);
	
	
	if(palindrome(list))
	printf("\nList is Palindrome!");
	else
	printf("\nList is not palindrome!");
	
	
	return 0;
}