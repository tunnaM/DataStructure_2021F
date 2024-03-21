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
	printf("������ؼ��ָ�����");
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; ++i)
	{
		printf("�������%d���ؼ��֣�", i + 1);
		scanf("%d", &key);
		getchar();
		e.key = key;
		InsertBST(&T, e);
	}

	//InOrderTraverse test
	printf("����������Ϊ��");
	InOrderTraverse(T, Visit);
	printf("\n");

	printf("������Ҫɾ���Ĺؼ��֣�");
	scanf("%d", &key);
	getchar();
	DeleteBST(&T, key);

	//InOrderTraverse test
	printf("����������Ϊ��");
	InOrderTraverse(T, Visit);
	printf("\n");


	system("pause");
	return 0;
}