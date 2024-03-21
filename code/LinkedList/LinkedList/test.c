#include <stdio.h>
#include "LinkList.h"

int main()
{
	LinkList L;
	InitList_L(&L);

	ElemType b[] = { 1,4,5,6,10 };
	L->data = b;

	//ListInsert test
	for (int i = 1; i <= 5; i++)
	{
		ListInsert_L(&L, i, 100 + i);
	}

	if (!LocateElem_L(L, 102))
		printf("ListInsert unsucess!\n");
	else
		printf("ListInsert sucess!\n");
	printf("�������ֺ�����Ϊ��");
	ListTraverse_L(L);

	//GetElem test
	ElemType* e = 0;
	GetElem_L(L, 3, &e);
	printf("���ҵ�3λ����Ϊ��");
	printf("%d\n", e);

	//ListDelete test
	ElemType* e1 = 0;
	ListDelete_L(&L, 4, &e1);
	printf("ɾ����Ԫ��ֵΪ��%d\n", e1);

	//CreateList test
	LinkList T;
	InitList_L(&T);
	CreateList_L(&T, 5);
	printf("ͷ�巨������Ϊ��");
	ListTraverse_L(T);

	//CreateList_tail test
	LinkList D;
	InitList_L(&D);
	CreateList_L_tail(&D, 5);
	printf("β�巨������Ϊ��");
	ListTraverse_L(D);

	return 0;
}