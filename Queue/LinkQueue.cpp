#include "queue.h"
#include <iostream>

#ifdef LINK_QUEUE

bool InitQueue(Queue &Q)
{
	QNode *head = new QNode;
	head->data = 0;
	head->next = NULL;
	Q.front = head;
	Q.rear = head;
	return true;
}

bool DestroyQueue(Queue &Q)
{
	QNode *del;
	while (Q.front){
		del = Q.front;
		Q.front = Q.front->next;
		delete del;
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
		Q.front = Q.front->next;
		delete del;
	}

	QNode *head = new QNode;
	head->data = 0;
	head->next = NULL;
	Q.front = head;
	Q.rear = head;

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
	return Q.front->data;
}

bool GetHead(Queue Q, ElemType &e)
{
	if (Q.rear == Q.front)
		return false;

	e = Q.front->next->data;
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

	Q.front->data++;

	return true;
}

bool DeQueue(Queue &Q, ElemType &e)
{
	if (!Q.front->next)
		return false;

	if (Q.front->next == Q.rear){
		Q.rear = Q.front;
	}

	QNode *temp = Q.front->next;
	Q.front->next = temp->next;

	e = temp->data;
	delete temp;

	Q.front->data--;

	return true;
}

void QueueTraverse(Queue &Q, void(*traverse)(ElemType &e))
{
	QNode *p;
	p = Q.front->next;
	while (p){
		traverse(p->data);
		p = p->next;
	}
}

#endif