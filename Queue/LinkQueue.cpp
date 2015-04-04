#include "queue.h"
#include <iostream>

#ifdef LINK_QUEUE

bool InitQueue(Queue &Q)
{
	Q.front = NULL;
	Q.rear = NULL;
	return true;
}

bool DestroyQueue(Queue &Q)
{
	QNode *del;
	while (Q.front){
		del = Q.front;
		delete del;
		Q.front = Q.front->next;
	}
	Q.front = NULL;
	Q.rear = NULL;
	return true;
}

bool ClearQueue(Queue &Q)
{
	QNode *del;
	while (Q.front){
		del = Q.front;
		delete del;
		Q.front = Q.front->next;
	}
	Q.front = NULL;
	Q.rear = NULL;
	return true;
}

bool QueueEmpty(Queue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

int QueueLength(Queue Q)
{
	if (NULL == Q.front)
		return 0;
	else{
		int i = 1;
		while (Q.front!=Q.rear)
		{
			Q.front = Q.front->next;
			i++;
		}
		return i;
	}
}

bool GetHead(Queue Q, ElemType &e)
{
	if (NULL == Q.front)
		return false;

	e = Q.front->data;
	return true;
}

bool EnQueue(Queue &Q, ElemType e)
{
	QNode *temp = new QNode;
	if (!temp)
		return false;
	temp->data = e;
	temp->next = NULL;

	Q.rear->next = temp;
	Q.rear = temp; 

	return true;
}

bool DeQueue(Queue &Q, ElemType &e)
{
	if (!Q.front)
		return false;

	QNode *temp = Q.front;
	Q.front = Q.front->next;

	e = temp->data;
	delete temp;

	return true;
}

void QueueTraverse(Queue &Q, void(*traverse)(ElemType &e))
{
	QNode *p;
	p = Q.front;
	while (p){
		traverse(p->data);
		p = p->next;
	}
}

#endif