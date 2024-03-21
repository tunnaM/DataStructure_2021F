#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "BinarySortTree.h"

int main()
{
	BiTree T, f, p;
	int num = 0;
	KeyType key;
	ElemType e;
	
	InitBiTree(&T);
	printf("请输入关键字个数：");
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; ++i)
	{
		printf("请输入第%d个关键字：", i + 1);
		scanf("%d", &key);
		getchar();
		e.key = key;
		InsertBST(&T, e);
	}

	//InOrderTraverse test
	printf("中序遍历结果为：");
	InOrderTraverse(T, Visit);
	printf("\n");

	printf("请输入要删除的关键字：");
	scanf("%d", &key);
	getchar();
	DeleteBST(&T, key);

	//InOrderTraverse test
	printf("中序遍历结果为：");
	InOrderTraverse(T, Visit);
	printf("\n");


	system("pause");
	return 0;
}