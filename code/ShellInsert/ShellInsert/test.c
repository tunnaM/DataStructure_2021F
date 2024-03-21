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
	//直接插入法排序
	SqList L;
	int i, n, m;
	InitList_Sq(&L);
	printf("请输入关键字数目：");
	scanf("%d", &n);
	L.length = n;
	getchar();
	for (i = 1; i <= n; i++)
	{
		printf("请输入第%d个关键字:", i);
		scanf("%d", &m);
		getchar();
		L.r[i].key = m;
	}
	
	MergeSort(&L);
	ListTraverse_Sq(L, visit_user);

	system("pause");
	return 0;
}
