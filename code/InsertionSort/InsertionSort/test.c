#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "InsertSort.h"
void visit_user(KeyType e);
void visit_user(KeyType e)
{
	printf("%d ", e);
}

int main()
{
	//ֱ�Ӳ��뷨����
	HeapType H;
	int i, n, m;
	InitList_Sq(&H);
	printf("������ؼ�����Ŀ��");
	scanf("%d", &n);
	H.length = n;
	getchar();
	for (i = 1; i <= n; i++)
	{
		printf("�������%d���ؼ���:",i);
		scanf("%d", &m);
		getchar();
		H.r[i].key = m;
	}
	HeapSort(&H);
	ListTraverse_Sq(H, visit_user);

	system("pause");
	return 0;
}





