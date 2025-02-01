#include"Queue.h"
int main()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	printf("%d ", QueueSize(&pq));

	while (!QueueEmpty(&pq))
	{
		printf("%d ", QueueFront(&pq));
		QueuePop(&pq);
	}
	QueueSize(&pq);
	return 0;
}