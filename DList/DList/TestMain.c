#define _CRT_SECURE_NO_WARNINGS 1
#include "common.h"
#include "dlist.h"

int main(int argc, char *argv[])
{
	DListNode *p = NULL;
	DList mylist;
	DListInit(&mylist);

	DataType item;
	int select = 1;
	while (select)
	{
		printf("************************************\n");
		printf("* [1] push_back     [2] push_front *\n");
		printf("* [3] show_list     [0] quit_system*\n");
		printf("* [4] pop_back      [5] pop_front  *\n");
		printf("* [6] find_pos      [7] find_val   *\n");
		printf("* [8] insert_val    [9] delete_val *\n");
		printf("* [10] delete_pos   [11]length     *\n");
		printf("* [12] remove_all   [13] reverse   *\n");
		printf("* [14] sort         [15] clear     *\n");
		printf("************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				//DListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据(以-1结束):>");
			while (scanf("%d", &item), item != -1)
			{
				//DListPushFront(&mylist, item);
			}
			break;
		case 3:
			//DListShow(&mylist);
			break;
		case 13:
			//DListReverse(&mylist);
			break;
		case 14:
			//DListSort(&mylist);
			break;
		case 15:
			//DListClear(&mylist);
			break;
		}
	}
	//DListDestroy(&mylist);
	return 0;

}