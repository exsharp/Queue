#ifndef _QUEUE_H_
#define _QUEUE_H_

#define ElemType int
typedef void(*traverse)(ElemType &e);

//#define ARRAY_QUEUE
#define LINK_QUEUE

#ifdef ARRAY_QUEUE
	#define MAXSIZE 100
	struct Queue{
		ElemType *data;
		int front;
		int rear;
	};
#endif

#ifdef LINK_QUEUE
	struct QNode{
		ElemType data;
		struct QNode *next;
	};

	struct Queue{
		QNode *front;
		QNode *rear;
	};
#endif

bool InitQueue(Queue &Q);
bool DestroyQueue(Queue &Q);
bool ClearQueue(Queue &Q);
bool QueueEmpty(Queue Q);
int QueueLength(Queue Q);
bool GetHead(Queue Q, ElemType &e);
bool EnQueue(Queue &Q, ElemType e);
bool DeQueue(Queue &Q, ElemType &e);
void QueueTraverse(Queue &Q, void(*traverse)(ElemType &e));

#endif