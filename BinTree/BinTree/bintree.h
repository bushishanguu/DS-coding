#ifndef _BINTREE_H_
#define _BINTREE_H_

#include "common.h"
typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;



void BinTreeInit(BinTree *pbt);
void CreateBinTree(BinTree *pbt);
void CreateBinTree_1(BinTreeNode **t);

void PreOrder(BinTree *pbt);
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *pbt);
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *pbt);
void PostOrder_1(BinTreeNode *t);
//void LevelOrder(BinTree *pbt);
//void LevelOrder_1(BinTreeNode *t);

void PreOreder(BinTree *pbt)
{
	pbt->root = NULL;
}
void CreateBinTree(BinTree *pbt)
{
	CreateBinTree_1(&pbt->root);
}

void CreateBinTree_1(BinTreeNode **t)
{
	DataType item;
	scanf("%c", &item);
	if (item=="#")
	
		*t = NULL;
	
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		CreateBinTree_1(&(*t)->leftChild);
		CreateBinTree_1(&(*t)->rightChild);
	}
}
void PreOrder(BinTree *pbt)
{
	PreOrder_1(pbt->root);
}
void PreOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}

}
void InOrder(BinTree *pbt)
{
	InOrder_1(pbt->root);
}
void InOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c ", t->data);
		InOrder_1(t->rightChild);
	}
}

void PostOrder(BinTree *pbt)
{
	PostOrder_1(pbt->root);
}
void PostOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c ", t->data);
	}
}

#endif /*_BINTREE_H_*/