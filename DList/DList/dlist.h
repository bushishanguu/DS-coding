#ifndef _DLIST_T_
#define _DLIST_T_


#include "common.h"
typedef struct DListNode 
{
	DataType data;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	size_t size;
}DList;

DListNode* _Buynode(DataType x)
{
	DListNode *s = (DListNode *)malloc(sizeof(DListNode));
	assert(s != NULL);
	s->data = x;
	s->prev = NULL;
	s->next = NULL;
	return s;
}

void DListInit(DList* plist);



void DListInit(DList* plist)
{
	plist->first = plist->last = _Buynode(0);
	plist->size = 0;
}



#endif