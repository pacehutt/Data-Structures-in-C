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

struct Node* insertR(struct Node *p , int key)
     {
     	struct Node *newNode;
     	
     	 if( p == NULL)
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
int Height(struct Node *rt)
{
	int x,y;
	if(rt == NULL) return 0;
	x = Height(rt->lchild);
	y = Height(rt->rchild);
	
	  return (x > y) ? x+1 : y+1;
	
}

int main()
{
	root=insertR(root,10);
	root=insertR(root,5);
	root=insertR(root,20);
	root=insertR(root,15);
	root=insertR(root,30);
	root=insertR(root,12);
	
	inorder(root);
	printf("\n");
	deletenode(root,20);
	
	inorder(root);
	
	struct Node *r = searchRecur(root,70);
	if(r!=NULL)
	{
		printf("\n%d found by recursion ",r->data);
	}
	else
	{
		printf("\n data is not found !!");
	}
	
	  int ans = Height(root);
	  printf("\nHeight = %d",ans);
	return 0;
}