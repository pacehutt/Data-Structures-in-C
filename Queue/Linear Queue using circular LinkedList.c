// Linear Queue Type using Circular LinkedList
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};
struct Queue
{
	struct Node * last;

};

void enqueue(struct Queue *q, int key)
{
	struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = key;
	newNode->next = NULL;

	if (q->last == NULL)
	{
		newNode->next = newNode;
		q->last = newNode;
	}
	else
	{
		newNode->next = q->last->next;
		q->last->next = newNode;
		q->last = newNode;
	}
}

int dequeue(struct Queue *q)
{
	int x = -9999;

	if (q->last == NULL)
		return x;
	else if (q->last->next == q->last)
	{
		x = q->last->data;
		q->last = NULL;
	}
	else
	{
		x = q->last->next->data;
		q->last->next = q->last->next->next;
	}

	return x;
}

void display(struct Queue q)
{
	if (q.last == NULL)
	{
		printf("Queue is Empty");
		return;
	}

	struct Node *i = q.last->next;
	printf("\nfirst node address :: %u \n", q.last->next);
	do {
		printf("|%d|%u|-->", i->data, i->next);
		i = i->next;
	} while (i != q.last->next);
}

// Driver Code

int main()
{
	//	Now we can create multiple Queue for different purposes
	struct Queue q1;
	q1.last = NULL;
	enqueue(&q1, 10);
	//	printf("%d",q1.last->data);
	enqueue(&q1, 20);
	enqueue(&q1, 30);
	display(q1);
	printf("\n%d Deleted\n", dequeue(&q1));
	printf("\n%d Deleted\n", dequeue(&q1));
	printf("\n%d Deleted\n", dequeue(&q1));
	display(q1);
}