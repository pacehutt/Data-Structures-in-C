#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
   struct Node *lchild;
   int data;
   struct Node *rchild;	
};
struct Node *root = NULL;
int maxLevel=0;
int sqn[30];
int preOrder[30],pr=0;
struct Node* InPre(struct Node*);
struct Node* InSuc(struct Node*);

struct Node* insertR(struct Node *p , int key)
     {
     	struct Node *newNode;
     	
     	 if(p == NULL)
     	 {
     	newNode=(struct Node*)malloc(sizeof(struct Node));
     	newNode->data = key;
     	newNode->lchild = newNode->rchild = NULL;
     	 return newNode;
		  }
		  
		  if(key > p->data)
		  {
		  	p->rchild = insertR(p->rchild,key);
		  }
		  else if( key < p->data)
		  {
		  	p->lchild = insertR(p->lchild,key);
		  }
		  return p;
	 }
void insert(int key)
{
	struct Node *c,*p,*newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->lchild = NULL;
	newNode->rchild = NULL;
	
	if(root == NULL)
	{
		root = newNode;
		return;
	}
	
	c = root;
	p = NULL;
	while(c != NULL)
	{
		p = c;
		if(key > c->data)
		   c=c->rchild;
		else if(key < c->data)
		   c=c->lchild;
		else
		   return;
	}
	
	if(key > p->data)
	{
		p->rchild = newNode;
	}
	else
	{
		p->lchild = newNode;
	}
}
void inorder(struct Node *p)
{
	if(p)
	{
		inorder(p->lchild);
		printf("%d   ",p->data);
		inorder(p->rchild);
	}
}
void preorder(struct Node *p)
{
	if(p)
	{
		printf("%d   ",p->data);
		*(preOrder+pr)=p->data;
		pr++;
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void postorder(struct Node *p)
{
	if(p)
	{
		
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d   ",p->data);
	}
}

struct Node* searchRecur(struct Node *p , int key)
{
	if(p == NULL)
	 return NULL;
	else if(p->data == key)
	   return p;
	else if(key > p->data)
	      return searchRecur(p->rchild,key);
	else
	      return searchRecur(p->lchild,key); 
}
struct Node* searchIter(struct Node *p , int key)
{
	while(p != NULL)
	{
		 if(key > p->data)
		 {
		 	p=p->rchild;
		 }
		 else if(key < p->data)
		 {
		 	p=p->lchild;
		 }
		 else
		 {
		 	return p;
		 }
	}
	
	return NULL;
}


void leftView(struct Node *root,int level)
{
	
	if(root==NULL)
	return;
	
	if(maxLevel<level)
	{
		printf(" %d ",root->data);
		maxLevel=level;
	}
	
	leftView(root->lchild,level+1);
	leftView(root->rchild,level+1);
	
	
	
}


void rightView(struct Node *root,int level)
{
	
	if(root==NULL)
	return;
	
	if(maxLevel<level)
	{
		printf(" %d ",root->data);
		maxLevel=level;
	}
	
	leftView(root->rchild,level+1);
	leftView(root->lchild,level+1);
	
}
struct Node* deletenode(struct Node *p , int key)
{
	struct Node *q;
	if(p == NULL)
	{
		return NULL;
	}
	if(p->lchild == NULL && p->rchild ==NULL)
	{
		if(p == root)
		 {
		 	root = NULL;
		 }
		free(p);
		return NULL;
	}
	if(key < p->data)
	{
		p->lchild = deletenode(p->lchild,key);
	}
	else if(key > p->data)
	{
		p->rchild = deletenode(p->rchild,key);
	}
	else
	{
		if(Height(p->lchild) > Height(p->rchild))
		{
			q=InPre(p->lchild);
			p->data = q->data;
		    p->lchild=deletenode(p->lchild,q->data);
		}
		else
		{
			q =InSuc(p->rchild);
			p->data = q->data;
			p->rchild=deletenode(p->rchild,q->data);
		}
	}
	return p;
}
struct Node* InPre(struct Node *p)
{
	while(p  && p->rchild!=NULL)
	{
		p=p->rchild;
	}
	return p;
}
struct Node* InSuc(struct Node *p)
{
	while(p  && p->lchild!=NULL)
	{
		p=p->lchild;
	}
	return p;
}
int Height(struct Node *rt)
{
	int x,y;
	if(rt == NULL) return 0;
	x = Height(rt->lchild);
	y = Height(rt->rchild);
	
	  return (x > y) ? x+1 : y+1;
	
}

/*
void deleteNode(int del_data)
{
	struct Node *p=NULL,*c;
	int flag=0;
	c=root;
	while(c!=NULL)
	{
		
		
		if(del_data>c->data)
		{
			p=c;
		c=c->rchild;
		}
		else if(del_data<c->data)
		{
			p=c;
		c=c->lchild;
		}
		else 
		{
			flag=1;
			break;
		}
	}
	    if(flag==1)
	    {
	    	if(c->lchild==NULL && c->rchild==NULL)
	    	{
	    		if(c->data>p->data)
	    		p->rchild=NULL;
	    		else
	    		p->lchild=NULL;
	    		
	    		c=NULL;
	    		free(c);
	    		printf("Leaf Node %d Deleted..",del_data);
			}
			else if(c->lchild == NULL)
			{
				if(c->data>p->data)
				p->rchild=c->rchild;
				else
				p->lchild=c->rchild;
				
				c=NULL;
				free(c);
				printf("Node %d with only Right Child Deleted..",del_data);
				
			}
			else if(c->rchild == NULL)
			{
				if(c->data>p->data)
				p->rchild=c->lchild;
				else
				p->lchild=c->lchild;
				
				c=NULL;
				free(c);
				printf("Node %d with only Left Child Deleted..",del_data);
				
			}
			else
			{
//				Here we are finding the In-Order Successor of Node C which means the smallest node in the right sub-tree
				struct Node *temp1,*temp2;
				temp1=NULL;
				temp2=c->rchild;
				while(temp2->lchild!=NULL)
				{
					temp1=temp2;
					temp2=temp2->lchild;
				}
				
				if(temp2!=c->rchild)
				{
					
				
				c->data = temp2->data;
				if(temp2->rchild != NULL)
				{
				temp1->lchild=temp2->rchild;
				temp2=NULL;
				free(temp2);	
			
					printf("\n Two Childs Condition 1 executed and \n Node %d with Two Childs Deleted..",del_data);
				}
				else
				{
				
				temp2=NULL;
				free(temp2);	
					printf("\n Two Childs Condition 2 executed and \n Node %d with Two Childs Deleted..",del_data);
				}
				}
				else
				{
					if(temp2->rchild != NULL)
					{
						c->rchild=temp2->rchild;
						free(temp2);
						printf("\n Two Childs Condition 3 executed and \n Node %d with Two Childs Deleted..",del_data);
					}
					else
					{
						c->rchild=NULL;
						c->data=temp2->data;
						free(temp2);
						printf("\n Two Childs Condition 4 and \n Node %d with Two Childs Deleted..",del_data);
						
					}
				}	
				
				
				
			}
	    	
		}
		else
		printf("Data Not Found!!");
	}
	*/

	


int main()
{

	
	 struct Node *r;
	int ch;
int key,i=0;
		int k=0;

	while(1)
	{
		
	
	printf("\nMenu:\n");
	printf("0:Exit\n");
	printf("1:Recursion Insert\n");
	printf("2:Iteration Insert\n");
	printf("3:Display Pre-Order:\n");
	printf("4:Display Post-Order:\n");
	printf("5:Display In-Order:\n");
	printf("6:Recursion Search:\n");
	printf("7:Iteration Search :\n");
	printf("8:Display Left View of the Tree :\n");
	printf("9:Display Right View of the Tree :\n");
	printf("10:Check if the Pre-order is same as given sequence:\n");
	printf("11:Delete Data :\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
	case 0: return 0;
	case 1: 
	printf("\nEnter Data:");
		scanf("%d",&key);
		*(sqn+i)=key;
		i++;
    root=insertR(root,key);
    break;
	
		case 2: 
	printf("\nEnter Data:");
		scanf("%d",&key);
			*(sqn+i)=key;
		i++;
    insert(key);
    break;    
    case 3: 
	pr=0;
	preorder(root);
    break;
	case 4: postorder(root);
    break;
	case 5: inorder(root);
    break;
	case 6:
    		printf("\nEnter Search Data:");
		scanf("%d",&key);
    	struct Node *r = searchRecur(root,key);
	if(r!=NULL)
	{
		printf("\n%d found by recursion ",r->data);
	}
	else
	{
		printf("\n data is not found !!");
	}
	
	break;
	case 7: 
	   
		printf("\nEnter Search Data:");
		scanf("%d",&key);
    	r = searchIter(root,key);
	if(r!=NULL)
	{
		printf("\n%d found by iteration ",r->data);
	}
	else
	{
		printf("\n data is not found !!");
	}
	
	break;
	case 8: 
	maxLevel=0;
	leftView(root,1);
		case 9: 
	maxLevel=0;
	rightView(root,1);
	
	break;
	case 10:
		preorder(root);
		for(k=0;k<i;k++)
	   {
	   	printf("\n %d  ",*(preOrder+k));
	   	if(*(sqn+k)!=*(preOrder+k))
	   	{
	   		printf("Input Sequence not equal to pre-order!!");
	   		break;
		   }
		}
		if(k>=i)	
		printf("Input Sequence is equal to pre-order!!");
		
		break;
		case 11:
		printf("\nEnter Data:");
		scanf("%d",&key);
		deletenode(root,key);
			
			break;
	default:return 0;

	}
	
}
	return 0;
}