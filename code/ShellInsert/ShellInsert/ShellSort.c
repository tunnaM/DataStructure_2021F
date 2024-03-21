#define _CRT_SECURE_NO_WARNINGS
#include "ShellSort.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status InitList_Sq(SqList* L)
{
	int i;
	for (i = 0; i <= MAXSIZE + 1; i++)
	{
		(*L).r[i].key = 0;
		(*L).r[i].otherinfo = 0;
	}
	(*L).length = 0;                    //空表长度为0
	return OK;
}

Status ListTraverse_Sq(SqList L, void(Visit)(ElemType))
{
	int i;
	for (i = 1; i <= L.length; i++)
		Visit(L.r[i].key);
	return OK;
}

void MergeSort(SqList* L)
{
	//对顺序表L作归并排序
	MSort((*L).r, &((*L).r), 1, (*L).length);
}//MergeSort

void MSort(RcdType SR[], RcdType TR1[], int s, int t)
{
	//将SR[s..t]归并排序为TR1[s..t]
	int m;
	RcdType TR2[MAXSIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;//将SR[s..t]平分为SR[s..m]和SR[m+1..t]
		MSort(SR, &TR2, s, m);//将SR[s..m]归并为TR2[s.m]
		MSort(SR, &TR2, m+1, t);//将SR[m+1..t]归并为TR2[m+1..t]
		Merge(TR2, &TR1, s, m, t);//将TR2[s..m]和SR[m+1..t]归并到TR1[s..t]
	}
}//MSort

void Merge(RcdType SR[], RcdType* TR[], int i, int m, int n)
{
	//将有序的子序列SR[i..m]和SR[m+1..n]归并为一个有序序列TR[i..n]
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)//将SR中记录由小到大地并入TR
	{
		if (SR[i].key <= SR[j].key)
			(*TR)[k] = SR[i++];
		else
			(*TR)[k] = SR[j++];
	}
	while (i <= m) 
		(*TR)[k++] = SR[i++];
	while (j <= n) 
		(*TR)[k++] = SR[j++];

}//Merge