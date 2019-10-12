#ifndef _SLIST_H_
#define _SLIST_H_

#include"common.h"

typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t    size;
}SList;

SListNode* _Buynode(DataType x)
{
	SListNode *s = (SListNode *)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
void SListInit(SList* plist);
void SListPushBack(SList *plist, DataType x);
void SListPushFront(SList *plist, DataType x);
void SListShow(SList *plist);
SListNode* SListFindByVal(SList *plist, DataType key);
BOOL SListEraseByVal(SList* plist, DataType key);

size_t SListLength(SList *plist);
BOOL SListInsertByVal(SList *plist, DataType x);

void SListClear(SList *plist);
void SListReverse(SList *plist);
void SListDestroy(SList *plist);


void SListInit(SList* plist)   //初始化
{
	SListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

void SListPushBack(SList* plist, DataType x)   //尾插法
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	plist->last->next = s;
	plist->last = s;
	plist->size++;
}

void SListPushFront(SList* plist, DataType x)   //头插法
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);
	s->next = plist->first->next;
	plist->first->next = s;

	if (plist->size == 0)
		plist->last = s;
	plist->size++;

}

void SListShow(SList *plist)     //链表打印
{
	SListNode *p = plist->first->next;
	while (p != NULL)
	{
		printf("%d--", p->data);
		p = p->next;
	}
	printf("over.\n");
}


SListNode* SListFindByVal(SList* plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p = plist->first->next;
	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

BOOL SListEraseByVal(SList* plist, DataType key)
{
	assert(plist != NULL);
	SListNode *p, *q;
	p = SListFindByVal(plist, key);
	if (p == NULL)
		return FALSE;
	q = plist->first;
	while (q->next != p)
		q = q->next;
	
	if (p == plist->last)
		plist->last = q;
	q->next = p->next;
	free(p);

	plist->size--;
	return TRUE;
}


size_t SListLength(SList *plist)
{
	return plist->size;
}

BOOL SListInsertByVal(SList *plist, DataType x)  //插入数值（有序链表）
{
	assert(plist);
	SListNode *s = _Buynode(x);
	SListNode *p = plist->first;
	while (p->next != NULL && p->next->data < x)
		p = p->next;
	if (p->next == NULL)
		plist->last = s;
	else
		s->next = p->next;
	p->next = s;

	plist->size++;
	return TRUE;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;


	if (plist->size == 0)
		return;
	while (p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;

	}
	plist->last = plist->first;
	plist->size = 0;
}

void SListReverse(SList *plist)
{
	SListNode *p, *q;
	p = plist->first->next;
	q = p->next;

	plist->last = p;
	plist->last->next = NULL;
	
	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = plist->first->next;
		plist->first->next = p;
	}
}
void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
	plist->size = 0;
}


#endif



