//Linear Queue using Arrays
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};
void createQueue(struct Queue *q, int sz)
{
	q->size = sz;
	q->front = q->rear = -1;
	q->Q = (int*) malloc(q->size* sizeof(int));
}

void enqueue(struct Queue *q, int item)
{
	if (q->rear == q->size - 1)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	else if (q->front == -1)
		q->front = q->front + 1;

	q->rear = q->rear + 1;
	q->Q[q->rear] = item;	//here in the 'q' Queue's 'Q' array we are assigning the item

}

int dequeue(struct Queue *q)
{
	int x = -9999;

	if (q->front == q->rear)
	{
		x = q->Q[q->front];
		q->front = q->rear = -1;

	}
	else
	{
		x = q->Q[q->front];
		q->front = q->front + 1;
	}

	return x;
}

int isEmptyQueue(struct Queue q)
{
	return q.front == -1;
}

void display(struct Queue q)
{
	int i;
	printf("\nCONTENTS OF QUEUE\n*********\n");
	if (isEmptyQueue(q))
	{
		return;
	}

	i = q.front;
	do {
		printf("%d\t", q.Q[i]);
		i = i + 1;
	}

	while (i != q.size);

	printf("\n*********\n");

}

// Driver Code

int main()
{
	struct Queue q1;
	createQueue(&q1, 4);
	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);
	enqueue(&q1, 40);
	display(q1);

	printf("\n%d deleted\n", dequeue(&q1));
	//    Now it will show Queue OverFlow
	//	enqueue(&q1,30);
	//	enqueue(&q1,40);
	//	  printf("\n%d deleted\n",dequeue(&q1));
	//	   printf("\n%d deleted\n",dequeue(&q1));
	//	    printf("\n%d deleted\n",dequeue(&q1));
	//	     printf("\n%d deleted\n",dequeue(&q1));
	return 0;
}