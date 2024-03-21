#define _CRT_SECURE_NO_WARNINGS
#include "InsertSort.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status InitList_Sq(HeapType *H)
{
	int i;
	for (i = 0; i <= MAXSIZE + 1; i++)
	{
		(*H).r[i].key = 0;
		(*H).r[i].otherinfo = 0;
	}
	(*H).length = 0;                    //空表长度为0
	return OK;
}

Status ListTraverse_Sq(HeapType H, void(Visit)(KeyType))
{
	int i;
	for (i = 1; i <= H.length; i++)
		Visit(H.r[i].key);
	return OK;
}

void HeapSort(HeapType* H)//对顺序表H进行堆排序
{
	int i;
	RcdType	swap;
	for (i = (*H).length / 2; i > 0; --i)
		HeapAdjust(&(*H), i, (*H).length);
	for (i = (*H).length; i > 1; --i)
	{
		swap = (*H).r[1];
		(*H).r[1] = (*H).r[i];
		(*H).r[i] = swap;//将堆顶记录和当前未经排序子序列H.r[1..r-1]重新调整堆
		HeapAdjust(&(*H), 1, i - 1);//对H.r[1..i-1]重新调整堆
	}
}//HeapSort

void HeapAdjust(HeapType* H, int s, int m)
{
	//已知H.r[s..m]中记录的关键字除H.r[s].key之外均满足堆的定义，
	//本函数调整H.r[s]的关键字，使H.r[s..m]成为一个大顶堆
	int j;
	RcdType rc = (*H).r[s];//暂存H.r[s]
	for (j = 2 * s; j <= m; j *= 2)//沿key较大的子结点向下筛选
	{
		if (j < m && (*H).r[j].key < (*H).r[j + 1].key)
			++j;//j为key较大的记录的下标
		if (rc.key >= (*H).r[j].key)
			break;//找到rc插入位置s，不需继续往下调整
		(*H).r[s] = (*H).r[j];
		s = j;//否则记录上移，尚需继续往下调整
	}
	(*H).r[s] = rc;//将调整前的堆顶记录插入到s位置
}//HeapAdjust