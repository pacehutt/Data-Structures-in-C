#include "stackQueue.h"


//Node,Queue and Stack are defined in the stackQueue.h file

//stackQueue.h and queue.h header files must be in the current dir to execute this
//all the pre-defined header files are already included in the stackQueue.h so no need to include them here 
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


int count_leaves(struct Node *p)
{

	if(p==NULL)
	return 0;
    
	else if(p->lchild==NULL && p->rchild==NULL)
	return 1;
	
	else
	return count_leaves(p->lchild)+count_leaves(p->rchild);



}	
	
	
	

int main()
{
	createTree();
//	Inorder(root);
//	printf("\n");
	IPreorder(root);
//	printf("\n");
//	preorder(root);
	printf("\n");
	printf("\n No. of Leaf Nodes: Efficient = %d \t",count_leaves(root));
//	printf("Count = %d \n Height = %d \n Sum = %d",count(root),Height(root),sum(root));
		
}