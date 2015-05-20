#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Queue.h"

Queue* Queue_Init ()
{
	Queue *initializedQ = (Queue*) malloc (sizeof(Queue));
	initializedQ->front = NULL;
	initializedQ->rear = NULL;
	initializedQ->size = 0;

	return initializedQ;
}

void Queue_Push (Queue *q, DataType element)
{
	Node* newElement = (Node*) malloc(sizeof(Node));
	newElement->data = element;
	newElement->next = NULL;

	if (q->front == NULL && q->rear == NULL)
	{
		q->front = q->rear = newElement;
		q->size++;
		return;
	}

	q->rear->next = newElement;
	q->rear = newElement;
	q->size++;
}

DataType Queue_Pop(Queue *q)
{
	Node* element = q->front;
	if (q->front == NULL) //Queue is empty return
		return;

	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;

	DataType returnedData = element->data;
	q->size--;
	free(element);
	return returnedData;
}

DataType Queue_Front (Queue *q)
{
	if (q->front != NULL)
		return q->front->data;
}

DataType Queue_Back(Queue *q)
{
	if (q->rear != NULL)
		return q->rear->data;
}

int Queue_Size (Queue *q)
{
	return q->size;
}

int Queue_Contains (Queue *q, DataType element)
{
	Node* tmp = q->front;
	while (tmp != NULL)
	{
		if (tmp->data.X == element.X && tmp->data.Y == element.Y)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}