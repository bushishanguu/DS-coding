#define _CRT_SECURE_NO_WARNINGS 1


//������һ���������������Hash��Hash��Ĵ洢��λ��ΪͰ��
//ÿ��Ͱ�ܷ�3����������һ��Ͱ��Ҫ�ŵ�Ԫ�س���3��ʱ��
//��Ҫ���µ�Ԫ�ش�������Ͱ�У�ÿ�����ͰҲ�ܷ�3��Ԫ�أ�
//������Ͱʹ������������
//��Hash��Ļ�Ͱ��ĿΪ����P��Hash���hash������Pȡģ��
//���붨�����£�
#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node *next;
};

//���ڼ���hash_table�Ѿ���ʼ�����ˣ�
//insert_new_element()����Ŀ���ǰ�һ���µ�ֵ����hash_table�У�
//Ԫ�ز���ɹ�ʱ����������0�����򷵻�-1����ɺ�����

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
	//���
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