#include"queue.h"

struct Stack
{
	int top;
	int size;
	struct Node **S;
};

void createStack(struct Stack *s,int sz)
{
	s->top=-1;
	s->size=sz;
	s->S=(struct Node**)malloc(sizeof(struct Node*)*sz);
}

void push(struct Stack *s, struct Node *key)
{
      if(s->top==s->size)
      {
      	printf("Stack Overflow\n");
      	return;
	  }
	  
	  s->top++;
	  s->S[s->top]=key;
	  
	  
}
struct Node* pop(struct Stack *s)
{
	struct Node *x=NULL;
	if(s->top==-1)
 {
 	return x;
 }
    x=s->S[s->top];
    s->top--;
    return x;
}


int isEmptyStack(struct Stack s)
{
	return (s.top==-1);
}



	
	

