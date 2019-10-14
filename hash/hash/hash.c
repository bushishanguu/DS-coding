#define _CRT_SECURE_NO_WARNINGS 1


//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，
//每个桶能放3个整数，当一个桶中要放的元素超过3个时，
//则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。
//此Hash表的基桶数目为素数P，Hash表的hash函数对P取模。
//代码定义如下：
#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};

//现在假设hash_table已经初始化好了，
//insert_new_element()函数目的是把一个新的值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

struct bucket_node hash_table[P];

int hash(int new_element)
{
	return new_element % P;
}
int insert_new_element(int new_element)
{
	int index = hash(new_element);
	for (int i = 0; i<3; ++i)
	{
		if (hash_table[index].data[i] == NULL_DATA)
		{
			hash_table[index].data[i] = new_element;
			return 0;
		}
	}
	//溢出
	struct bucket_node *p = &hash_table[index];
	while (p->next != NULL_DATA)
	{
		p = p->next;
		for (int i = 0; i<3; ++i)
		{
			if (p->data[i] == NULL_DATA)
			{
				p->data[i] = new_element;
				return 0;
			}
		}
	}
	struct bucket_node *node = (struct bucket_node*)malloc(sizeof(struct bucket_node));
	if (node == NULL_DATA)
		return -1;
	for (int i = 0; i<3; ++i)
	{
		node->data[i] = NULL_DATA;
	}
	node->next = NULL_DATA;
	node->data[0] = new_element;
	p->next = node;
	return 0;
}

void hash_init()
{
	for (int i = 0; i<P; ++i)
	{
		for (int j = 0; j<3; ++j)
		{
			hash_table[i].data[j] = NULL_DATA;
		}
		hash_table[i].next = NULL_DATA;
	}
}

int main()
{
	int array[] = { 15, 14, 21, 87, 96, 293, 35, 24, 149, 19, 63, 16, 103, 77, 5, 153, 145, 356, 51, 68, 705, 453 };
	int n = sizeof(array) / sizeof(int);
	hash_init();
	for (int i = 0; i<n; ++i)
	{
		insert_new_element(array[i]);
	}
	system("pause");
	return 0;
}