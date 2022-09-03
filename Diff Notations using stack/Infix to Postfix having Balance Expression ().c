#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct Node {
  char data;
  struct Node * next;
};


struct Node * top = NULL;

void push(char item) {
  struct Node * newNode;
  newNode = (struct Node * ) malloc(sizeof(struct Node));
  if (newNode == NULL) {
    printf("Overflow");
  } else {
    newNode -> data = item;
    newNode -> next = top;
    top = newNode;
  }
}
char pop() {
  char x = -1;
  struct Node * t;
  if (top == NULL) {
    printf("Underflow");
  } else {
    t = top;
    top = top -> next;
    x = t -> data;
    t -> next = NULL;
    free(t);
  }
  return x;
}

void display() {
  struct Node * i;
  printf("\n");
  if (top == NULL) {
    printf("EMPTY STACK");
  } else {
    for (i = top; i != NULL; i = i -> next) {
      printf("%c\n", i -> data);
    }
  }
}
int pre(char oper) {
  if (oper == '*' || oper == '/')
    return 2;
  if (oper == '+' || oper == '-')
    return 1;
  return 0;
}
int isOperand(char x) {
  if (x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
  else
    return 1;
}
char * InToPos(char * inf) {
  char * postfix;
  int i, j;
  i = 0;
  j = 0;
  int len = strlen(inf);
  postfix = (char * ) malloc((len + 2) * sizeof(char));

  while (inf[i] != '\0') {
    if (isOperand(inf[i])) {
      postfix[j++] = inf[i++];
    } else {
      if (pre(inf[i]) > pre(top -> data)) {
        push(inf[i++]);
      } else {
        postfix[j++] = pop();
      }
    }
  }
  while (top != NULL) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
  return postfix;
}
int isBalanced(char * exp) {
  int i;
  for (i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(') {
      push(exp[i]);
    }
    if (exp[i] == ')') {
      if (top == NULL)
        return 0;

      pop();
    }
  }

  return top == NULL ? 1 : 0;
}
int main() {
  //char *infix ="A+B/C*D-E+F";
  //	printf("INFIX :: %s\n",infix);
  //push('#');
  //printf("POSTFIX :: %s",InToPos(infix));

  char infix = "(A+B/C)(D-E)+F)";
  int x = isBalanced(infix);
  printf(" return waha se kya hua hai :: %d", x);

}