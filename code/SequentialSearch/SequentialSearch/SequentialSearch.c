#define _CRT_SECURE_NO_WARNINGS
#include "SequentialSearch.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status CreateST(SSTable *ST)
{
	int i, n;
	printf("����˳����ұ�ĳ���:");
	scanf("%d", &n);
	getchar();
	(*ST).length = n + 1;
	(*ST).elem = (ElemType*)malloc((n+1)*sizeof(ElemType));
	printf("����ÿ���ؼ��ֵ���Ϣ��\n");
	for (i = 1; i < (*ST).length; i++)
	{
		printf("�����%d���ؼ��ֵ���Ϣ��", i);
		scanf("%d", &(*ST).elem[i].key);//�ؼ�����Ϣ
		getchar();
	}
	return OK;
}//CreateST

int Search_Seq1(SSTable ST, KeyType key)//�޼�����
{
	int i = ST.length;
	while (i > 0 && ST.elem[i].key != key)
		i--;
	return i;
}

int Search_Seq2(SSTable ST, KeyType key)//�м�����
{
	int i = ST.length;
	ST.elem[0].key = key;//������
	while (ST.elem[i].key != key)
		i--;
	return i;
}

int Search_Bin1(SSTable ST, KeyType key)//�۰���ҵķǵݹ��㷨
{
	//�������ST���۰������ؼ��ֵ���key������Ԫ��
	//���ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	int low, high, mid;
	low = 1;
	high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ST.elem[mid].key == key)
			return mid;//�ҵ�����Ԫ��
		else if (ST.elem[mid].key > key)
			high = mid - 1;//������ǰ��������в���
		else
			low = mid + 1;//�����ں��������в���
	}
	return 0;
}//Search_Bin
//ʱ�临�Ӷ�O��log n)

int Search_Bin2(SSTable ST, int low, int high, KeyType key)
{
	//�ݹ�ʵ��
	int mid = 0;
	if (low > high)
		return 0;
	else
	{
		mid = (low + high) / 2;
		if (ST.elem[mid].key > key)
			return Search_Bin2(ST, low, mid - 1, key);
		else if (ST.elem[mid].key < key)
			return Search_Bin2(ST, mid + 1, high, key);
		else
			return mid;
	}
}//Search_Bin2
//ʱ�临�Ӷ�O��log n)
