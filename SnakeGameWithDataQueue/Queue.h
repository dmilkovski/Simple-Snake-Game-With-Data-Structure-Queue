#include<Windows.h>

#ifndef _QUEUEH_
#define _QUEUEH_
	#define DataType COORD

	typedef struct _node
	{
		DataType data;
		struct _node *next;
	}Node;

	typedef struct _queue {
		Node *front;
		Node *rear;
		int size;
	}Queue;

	Queue* Queue_Init();
	void Queue_Push(Queue *q, DataType element);
	DataType Queue_Pop(Queue *q);
	DataType Queue_Front(Queue *q);
	DataType Queue_Back(Queue *q);
	int Queue_Size(Queue *q);
	int Queue_Contains(Queue *q, DataType element);
#endif