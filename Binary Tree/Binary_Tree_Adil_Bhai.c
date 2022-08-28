#include "stackQueue.h"


//stackQueue.h and queue.h header files must be in the current dir to execute this
//all the pre-defined header files are already included in the stackQueue.h so no need to include them here 


//Node,Queue and Stack are defined in the stackQueue.h file
struct Node *root = NULL;
void createTree()
{
	struct Queue q;
	int x;
	createQueue(&q,100);
	struct Node *t,*p;
	printf("\nEnter Root Value :: ");
	scanf("%d",&x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q,root);
	
	while(!isEmptyQueue(q))
	{
		p=dequeue(&q);
		printf("Enter Left Child Of %d :: ",p->data);
		scanf("%d",&x);
		if(x != -1)
		{
			t=(struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q,t);
		}
		printf("Enter Right Child Of %d :: ",p->data);
		scanf("%d",&x);
		if(x != -1)
		{
			t=(struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q,t);
		}
	}
	
	
}
void Inorder(struct Node *rt)
{
	if(rt != NULL)
	{
		Inorder(rt->lchild);
		printf("%d  ",rt->data);
		Inorder(rt->rchild);
	}
}
void IPreorder(struct Node *t)
{
	struct Stack s;
	createStack(&s,100);
	while( t || !isEmptyStack(s))
	{
		if(t)
		{
			push(&s,t);
			printf("%d\t",t->data);
			t=t->lchild;
		}
		else
		{
			t=pop(&s);
			t=t->rchild;
		}
	}
}
void preorder(struct Node *rt)
{
	if(rt)
	{
		printf("%d\t",rt->data);
		preorder(rt->lchild);
		preorder(rt->rchild);
	}
}
int count(struct Node *p)
{
	int x=0 , y=0;
	if(p == NULL)
	   return 0;
	x = count(p->lchild);
	y = count(p->rchild);
	return x+y+1;
}
int countNDZ(struct Node *p)
{
	int x =0 , y=0;
	if(p == NULL)
	   return 0;
	x = countNDZ(p->lchild);
	y = countNDZ(p->rchild);
	if(!p->lchild && !p->rchild)
	   return x+y+1;
	else
	   return x+y;
	
}
int countNDZM(struct Node *p)
{
	if(p == NULL)
	   return 0;
	
	if(!p->lchild && !p->rchild)
	   return 1;
	else
	   return countNDZM(p->lchild)+countNDZM(p->rchild);
	
}
int countND2(struct Node *p)
{
	int x = 0 , y =0 ;
	if(p == NULL)
	  return 0;
	x=countND2(p->lchild);
	y=countND2(p->rchild);
	if(p->lchild  &&  p->rchild)
	   return x+y+1;
	else
	   return x+y;
}
int countND1or2(struct Node *p)
{
	int x = 0 , y =0 ;
	if(p == NULL)
	  return 0;
	x=countND1or2(p->lchild);
	y=countND1or2(p->rchild);
	if(p->lchild  ||  p->rchild)
	   return x+y+1;
	else
	   return x+y;
}
int countND1(struct Node *p)
{
	int x = 0 , y =0 ;
	if(p == NULL)
	  return 0;
	x=countND1(p->lchild);
	y=countND1(p->rchild);
	if(p->lchild!=NULL  ^  p->rchild!=NULL)
	   return x+y+1;
	else
	   return x+y;
}
int sum(struct Node *p)
{
	if(p == NULL)
	  return 0;
	return sum(p->lchild)+sum(p->rchild)+p->data;
}


int Height(struct Node *p)
{
	int x = 0 , y = 0;
	if(p == NULL)
	   return 0;
	   
	x = Height(p->lchild);
	y = Height(p->rchild);
	if(x > y)
	  return x+1;
	return y+1;   
}
int main()
{
	createTree();
	Inorder(root);
//	printf("\n");
//	IPreorder(root);
//	printf("\n");
//	preorder(root);
	printf("\n");
	printf("Count = %d \n Height = %d \n Sum = %d",count(root),Height(root),sum(root));
	printf("\nCount Leaf Node = %d ",countNDZ(root));
    printf("\nCount Leaf Node Degree 2 = %d ",countND2(root));
	printf("\nCount Leaf Node from Mafiz version= %d ",countNDZM(root));	
	printf("\nCount deg 1 or 2= %d ",countND1or2(root));
	printf("\nCount deg 1 = %d ",countND1(root));	
}