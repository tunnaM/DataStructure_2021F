#define _CRT_SECURE_NO_WARNINGS
#include "SequentialSearch.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status CreateST(SSTable *ST)
{
	int i, n;
	printf("输入顺序查找表的长度:");
	scanf("%d", &n);
	getchar();
	(*ST).length = n + 1;
	(*ST).elem = (ElemType*)malloc((n+1)*sizeof(ElemType));
	printf("输入每个关键字的信息：\n");
	for (i = 1; i < (*ST).length; i++)
	{
		printf("输入第%d个关键字的信息：", i);
		scanf("%d", &(*ST).elem[i].key);//关键字信息
		getchar();
	}
	return OK;
}//CreateST

int Search_Seq1(SSTable ST, KeyType key)//无监视哨
{
	int i = ST.length;
	while (i > 0 && ST.elem[i].key != key)
		i--;
	return i;
}

int Search_Seq2(SSTable ST, KeyType key)//有监视哨
{
	int i = ST.length;
	ST.elem[0].key = key;//监视哨
	while (ST.elem[i].key != key)
		i--;
	return i;
}

int Search_Bin1(SSTable ST, KeyType key)//折半查找的非递归算法
{
	//在有序表ST中折半查找其关键字等于key的数据元素
	//若找到，则函数值为该元素在表中的位置，否则为0
	int low, high, mid;
	low = 1;
	high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ST.elem[mid].key == key)
			return mid;//找到待查元素
		else if (ST.elem[mid].key > key)
			high = mid - 1;//继续在前半区间进行查找
		else
			low = mid + 1;//继续在后半区间进行查找
	}
	return 0;
}//Search_Bin
//时间复杂度O（log n)

int Search_Bin2(SSTable ST, int low, int high, KeyType key)
{
	//递归实现
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
//时间复杂度O（log n)
