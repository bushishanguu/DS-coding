#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"
#include "queue.h"

int main()
{
	CircleQueue Q;
	CircleQueueInit(&Q, 8);

	CircleQueuePush(&Q, 1);
	CircleQueuePush(&Q, 2);
	CircleQueuePush(&Q, 3);
	CircleQueuePush(&Q, 4);
	CircleQueuePush(&Q, 5);
	CircleQueuePush(&Q, 6);
	CircleQueuePush(&Q, 7);
	CircleQueuePush(&Q, 8);
	CircleQueueShow(&Q);
	CircleQueuePop(&Q);
	CircleQueueShow(&Q);

	CircleQueuePush(&Q, 8);
	CircleQueueShow(&Q);

	CircleQueuePop(&Q);
	CircleQueueShow(&Q);

	CircleQueuePush(&Q, 9);
	CircleQueueShow(&Q);

	system("pause");
	return 0;
}




//int main()
//{
//	ListQueue Q;
//	ListQueueInit(&Q);
//	ListQueuePush(&Q, 1);
//	ListQueuePush(&Q, 2);
//	ListQueuePush(&Q, 3);
//	ListQueuePush(&Q, 14);
//	ListQueuePush(&Q, 5);
//
//	ListQueueShow(&Q);
//
//	ListQueuePop(&Q);
//
//	ListQueueShow(&Q);
//	system("pause");
//	return 0;
//}

//int main()
//{
//		Queue Q;
//		QueueInit(&Q, 10);
//		QueuePush(&Q, 1);
//		QueuePush(&Q, 2);
//		QueuePush(&Q, 3);
//		QueuePush(&Q, 4);
//		QueuePush(&Q, 5);
//		QueuePush(&Q, 6);
//
//		QueueShow(&Q);
//		QueuePop(&Q);
//		QueuePop(&Q);
//		QueuePop(&Q);
//		QueueShow(&Q);
//
//
//		QueuePush(&Q, 10);
//		QueuePush(&Q, 20);
//		QueuePush(&Q, 30);
//		QueuePush(&Q, 40);
//		QueuePush(&Q, 50);
//		QueuePush(&Q, 60);
//
//		QueueShow(&Q);
//		system("pause");
//		return 0;
//	}






