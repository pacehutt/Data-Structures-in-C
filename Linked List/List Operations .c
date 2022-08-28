#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    
	int data;
	struct Node *next;
};
struct Node *list1= NULL;
struct Node *list2 = NULL;

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

deleteMid(struct Node **p)
{
	struct Node *c=*(p);
	int i=0,mid;
	while(c)
	{
		i++;
		c=c->next;
		
	}
			printf("\n%d no of terms\n",i);
	
		struct Node *cur,*prev;
		cur=*(p);
		printf("current data %d\n",cur->data);
	if(i%2!=0)
	{
		mid=i/2;
		i=0;
    }
    else
    {
    	mid=(i/2)+1;
    	i=1;
    }
    	while(i!=mid)
		{
			i++;
			prev=cur;
			cur=cur->next;
		}
		
		prev->next=cur->next;
			cur->next=NULL;
			free(cur);
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
     
    slow->next = reverse(&(slow->next));
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

altMerge(struct Node **list1,struct Node **list2)
{
	    int flag=0;
		struct Node *p1=*(list1);
		struct Node *p2=p1;
	while(p2)
	{
		if(flag==0)
		{
		p2=p1->next;
		if(*(list2)!=NULL)
		{
		p1->next = *(list2);
		*(list2)=(*list2)->next;
		p1=p1->next;	
			}	
	    
		flag=1;
		}
		else
		{
			p1->next=p2;
			p1=p1->next;
	
		
			flag=0;
		}
		
	}
	p1->next=NULL;
}

int main()
{
	 struct Node *poly3 = NULL;
	create(&list1);
    display(list1);
    printf("\n");

    create(&list2);
    display(list2);

//   deleteMid(&list1);
//   display(list1);
    altMerge(&list1,&list2);
    printf("\nAfter MErge List 1\n");
    display(list1);
    printf("\nAfter merge list 2\n");
	 display(list2);
    
     
	getch();
	return 0;
}