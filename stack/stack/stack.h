#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _STACK_H_
#define _STACK_H_

#include "common.h"
typedef struct Stack
{
	DataType *base;
	size_t capacity;
	size_t top;
}Stack;


#define DEFAYLT_STACK_SIZE 8

void StackInit(Stack *pst, size_t sz);
void StackPush(Stack *pst, DataType x);
void StackPop(Stack *pst);
void StackClear(Stack *pst);
void StackDestroy(Stack *pst);
DataType StackTop(Stack *pst);
void StackShow(Stack *pst);

BOOL StackIsFull(Stack *pst)
{
	return pst->top >= pst->capacity;
}

BOOL StackIsEmpty(Stack *pst)
{
	return pst->top ==0;
}

void StackInit(Stack *pst, size_t sz)
{
	pst->capacity = sz > DEFAYLT_STACK_SIZE ? sz : DEFAYLT_STACK_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*(pst->capacity));
	assert(pst->base != NULL);
	pst->top = 0;

}
void StackPush(Stack *pst, DataType x)
{
	if (StackIsFull(pst))
	{
		printf("栈已满，&d不能再插入",x);
		return;
	}
	pst->base[pst->top++] = x;
}

void StackPop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("栈已空，不能进行删除操作");
		return;
	}
	pst->top--;

}

void StackClear(Stack *pst)
{
	pst->top = 0;
}

DataType StackTop(Stack *pst)
{
	if (StackIsEmpty(pst))
	{
		printf("栈已空，不能进行取栈顶操作");
		return;
	}
	return pst->base[pst->top-1];
}

void StackDestroy(Stack *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->top = pst->capacity = 0;

}

void StackShow(Stack *pst)
{
	for (int i = pst->top - 1; i >= 0; --i)
	{
		printf("%d\n", pst->base[i]);
	}
}


#endif  /*_STACK_H*/_