#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ShellSort.h"
void visit_user(KeyType e);
void visit_user(KeyType e)
{
	printf("%d ", e);
}

int main()
{
	//ֱ�Ӳ��뷨����
	SqList L;
	int i, n, m;
	InitList_Sq(&L);
	printf("������ؼ�����Ŀ��");
	scanf("%d", &n);
	L.length = n;
	getchar();
	for (i = 1; i <= n; i++)
	{
		printf("�������%d���ؼ���:", i);
		scanf("%d", &m);
		getchar();
		L.r[i].key = m;
	}
	
	MergeSort(&L);
	ListTraverse_Sq(L, visit_user);

	system("pause");
	return 0;
}
