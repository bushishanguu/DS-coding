#define _CRT_SECURE_NO_WARNINGS 1

#include"common.h"
#include"bintree.h"

//ABC##DE##F##G#H##
int main()
{
	BinTree bt;
	BinTreeInit(&bt);
	CreateBinTree(&bt);

	printf("VLR : "); //A B C D E F G H
	PreOrder(&bt);
	printf("\n");
	printf("LVR : "); // C B E D F A G H
	InOrder(&bt);
	printf("\n");
	printf("LRV : "); // C E F D B H G A
	PostOrder(&bt);
	printf("\n");

	system("pause");
	return 0;
}