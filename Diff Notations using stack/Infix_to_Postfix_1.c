#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct Node
{
	char data;
	struct Node *next;
};
struct Node *top = NULL;

void push(char item)
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
char pop()
{
	char x = -1;
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

void display()
{
	struct Node *i;
	printf("\n");
	if(top == NULL)
	{
		printf("EMPTY STACK");
	}
	else
	{
		 for(i = top ; i!=NULL ; i=i->next)
		 {
		 	printf("%c\n",i->data);
		 }
	}
}
int outer_pre(char oper)
{
	if(oper == '*' || oper == '/')
	   return 3;
	else if(oper == '+' || oper == '-')
	   return 1;
	else if(oper=='^') 
	   return 6;   
	else if(oper=='(')
	   return 7; 
	else     
	return 0;
}

int inner_pre(char oper)
{
	if(oper == '*' || oper == '/')
	   return 4;
	else if(oper == '+' || oper == '-')
	   return 2;
	else if(oper=='^') // for power inner-precedence is 5
	   return 5;      
	
	else if(oper=='#')
	return -1;
	   
	else      
	return 0;
	
}
int isOperand(char x)
{
	if(x == '+' || x == '-' || x == '*' || x =='/' || x=='(' || x==')' || x=='^')
	    return 0;
	else
	    return 1;
}
char* InToPos(char *inf)
{
	char *postfix;
	int i,j;
	i=0;
	j=0;
	     int len=strlen(inf);
	     postfix= (char*) malloc((len+2)*sizeof(char));

	    
	     while(inf[i] != '\0')
	     {

	     	if(isOperand(inf[i]))
	     	{
	     		postfix[j++] = inf[i++];
			 } 
			 else
			 {
			 	 if(outer_pre(inf[i]) > inner_pre(top->data))
			 	 {
                    
                  
			 	 	  
			 	 	  if(top->data=='#' && inf[i]==')')
			 	 	  i++;
			 	 	  else
					  push(inf[i++]);
				  }
				  else
				  {
				  	char temp = pop();
					if(temp!='(')      
                    postfix[j++]=temp;
		          }
				  
			}
			
	}
//		All the operators left in the stack are now added to the postfix string
		 while(top!=NULL)
		 {
		 	char temp = pop();
			if(temp != '#')
			postfix[j++] = temp;
		 }
		 
         

	     postfix[j]='\0';
	     return postfix;

}








int main()
{
	char *infix ="((a+b)*c)-d^e^f";
	printf("INFIX :: %s\n",infix);
//	As top cannot be NULL for the checking of operators so we are pushing it to return 0 for the very first time
	push('#');
	printf("POSTFIX :: %s",InToPos(infix));
	
}