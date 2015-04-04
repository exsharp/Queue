#include "queue.h"
#include <iostream>

#ifdef ARRAY_QUEUE

bool InitQueue(Queue &Q)
{
	Q.data = new ElemType[MAXSIZE];
	Q.front = 0;
	Q.rear = 0;
	if (!Q.data)
		return false;
	else
		return true;
}

bool DestroyQueue(Queue &Q)
{
	if (!Q.data)
		return false;
	else
	{
		delete Q.data;
		Q.front = 0;
		Q.rear = 0;
		return true;
	}
}

bool ClearQueue(Queue &Q)
{
	Q.front = 0;
	Q.rear = 0;
	return true;
}

bool QueueEmpty(Queue Q)
{
	return (Q.front == Q.rear ? true : false);
}

int QueueLength(Queue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

bool GetHead(Queue Q, ElemType &e)
{
	e = Q.data[Q.front];
	return true;
}

bool EnQueue(Queue &Q, ElemType e)
{
	if (Q.front == ((Q.rear + 1) % MAXSIZE))
		return false;
	
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}

bool DeQueue(Queue &Q, ElemType &e)
{
	if (Q.front == Q.rear)
		return false;
	
	e = Q.data[Q.front];
	Q.front = (Q.front + 1)%MAXSIZE;
	return true;
}

void QueueTraverse(Queue &Q, void(*traverse)(ElemType &e))
{
	int count = Q.front;
	while (count != Q.rear){
		traverse(Q.data[count]);
		count = (count + 1) % MAXSIZE;
	}
}

#endif