#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { 
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType * q, element item)
{
	if (is_full(q))
		error("Queue Full");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("Queue Empty");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d)= ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
int main(void)
{
	QueueType q;
	init_queue(&q);
	int element, choice;

	do {
	printf("==== NENU ==== \n");
	printf("1. Input data and Enqueue \n");
	printf("2. Dequeue and Print data \n");
	printf("3. Print Queue \n");
	printf("4. Exit \n");
	printf("Enter your choice: ");
	scanf_s("%d", &choice);

	if (choice == 1) {
		if (is_full(&q)) {
			printf("Queue Full\n");
		}
		else {
		printf("Enter the element to insert: ");
		scanf_s("%d", &element);
		enqueue(&q, element);
		}
	}
	else if (choice == 2) {
		if (q.rear == -1) {
			printf("Queue Empty\n");
		}
		else {
			element = dequeue(&q);
			printf("Deleted element is: %d\n", element);
		}
	}
	else if (choice == 3) {
		if (q.rear == -1) {
			printf("Queue Empty\n");
		} else 
		queue_print(&q);
	}
	else if (choice == 4) {
		printf("Exiting from program\n");
		break;
	}
	else {
		printf("Invalid choice\n");
	}
	} while (1);
	return 0;
}