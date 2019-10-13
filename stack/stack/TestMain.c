#define _CRT_SECURE_NO_WARNINGS 1

#include"common.h"
#include"stack.h"

int main(int argc, char *argv[])
{
	Stack st;
	
	StackInit(&st, 10);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);

	StackShow(&st);
	printf("----------------\n");
	
	StackPop(&st);
	StackPop(&st);

	StackShow(&st);

	StackDestroy(&st);
	system("pause");
	return  0;
}