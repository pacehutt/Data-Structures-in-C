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
	q->front = q->rear = 0;
	q->Q = (int*) malloc(q->size* sizeof(int));
}

void enqueue(struct Queue *q, int item)
{
	if ((q->rear + 1) % q->size == q->front)
	{
		printf("\nQueue Overflow\n");
	}
	else
	{
		q->rear = (q->rear + 1) % q->size;	// in this way rear will move circularly

		q->Q[q->rear] = item;	//here in the 'q' Queue's 'Q' array we are assigning the item
	}
}

int dequeue(struct Queue *q)
{
	int x = -9999;
	if (q->front == q->rear)
	{
		printf("\nQueue Underflow\n");
	}
	else
	{
		q->front = (q->front + 1) % q->size;
		x = q->Q[q->front];
	}

	return x;
}

int isEmptyQueue(struct Queue q)
{
	return q.front == q.rear;
}

void display(struct Queue q)
{
	int i;
	printf("\nCONTENTS OF QUEUE\n*********\n");
	if (isEmptyQueue(q))
	{
		return;
	}

	i = (q.front + 1) % q.size;
	do {
		printf("%d\t", q.Q[i]);
		i = (i + 1) % q.size;
	}
	
	while (i != (q.rear + 1) % q.size);

	printf("\n*********\n");

}

int main()
{
	struct Queue q1;
	createQueue(&q1, 5);
	enqueue(&q1, 10);
	enqueue(&q1, 20);
	enqueue(&q1, 30);
	enqueue(&q1, 40);
	display(q1);
	printf("\n%d deleted\n", dequeue(&q1));
	//	  printf("\n%d deleted\n",dequeue(&q1));
	//	   printf("\n%d deleted\n",dequeue(&q1));
	//	    printf("\n%d deleted\n",dequeue(&q1));
	//	     printf("\n%d deleted\n",dequeue(&q1));
	return 0;
}