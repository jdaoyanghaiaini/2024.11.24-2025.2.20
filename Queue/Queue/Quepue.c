#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
	
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->tail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDateType x)
{
	assert(pq);
	if (pq->head == NULL)
	{
		pq->tail = pq->head = (QNode*)malloc(sizeof(QNode));
		assert(pq->tail && pq->head);
		pq->head->date = x;
		pq->head->next = NULL;
	}
	else
	{
		pq->tail = pq->tail->next = (QNode*)malloc(sizeof(QNode));
		assert(pq->tail && pq->tail->next);
		pq->tail->next = NULL;
		pq->tail->date = x;
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
QDateType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->date;
}
QDateType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->date;
}