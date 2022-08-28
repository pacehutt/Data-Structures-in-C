//Disclaimer: This code is only valid when the evaluated result is less than 10


#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *top = NULL;


void push(int item)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
//		This case is very rare as we are using LinkedList so Heap is where the data are being stored
		printf("Overflow"); 
	}
	else
	{
		newNode->data = item;
		newNode->next = top;
		top=newNode;
	}
}


int pop()
{
	int x = -1;
	struct Node *t;
	if(top == NULL)
	{
		printf("Underflow");
	}
	else
	{
		t = top;
		top=top->next;
		x = t->data;
		t->next=NULL;
		free(t);
	}
	return x;
}


int isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x =='/' || x=='(' || x==')' || x=='^')
	    return 0;
	else
	    return 1;
}


int evalPostFix(char *posf)
{
	int res=0,i=0,x,y;
	
	while(posf[i] != '\0')
	{
	       if(isOperand(posf[i]))
		   {   
//		   printf("%d\n",posf[i]);
		   	   push(posf[i++]);
			   
			   }	
			   
			   else
			   {     
// here we are first converting the Ascii code of the digit to the digit itself in char type 
// and then converting it back to int digit by subtracting '0' from it 
			   	     x=((char)pop()) - '0';
			   	     y=((char)pop()) - '0';
			   	     
			   	    
			   	     switch(posf[i++])
			   	     {
			   	     	case '+' : res = x+y;
			   	     	break;
			   	     	case '-' : res = y-x;
			   	     	break;
			   	     	case '/' : res = y/x;
			   	     	break;
			   	     	case '*' : res =y*x;
			   	     	break;
			   	     	case '^' : res =pow(y,x);
						}
		
				    
//				    Here we are converting the integer and pushing it back to the stack as a character
				     char t= res + '0';
					 push(t);	
			   	     
			   }
			   
	}
	
	return res;
}





int main()
{
	char *postfix ="884*2*+5-2+";
	printf("POSTFIX :: %s\n",postfix);
//	As top cannot be NULL for the checking of operators so we are pushing it to return 0 for the very first time
	push('#');
	printf("Evaluated Result :: %d",evalPostFix(postfix));
	
}

