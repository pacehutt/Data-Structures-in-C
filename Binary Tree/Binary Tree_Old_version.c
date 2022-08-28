#include "queue.h"

struct Node *root;
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

int main()
{
	createTree();
	Inorder(root);
}