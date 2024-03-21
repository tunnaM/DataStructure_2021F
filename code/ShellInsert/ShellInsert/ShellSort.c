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
	(*L).length = 0;                    //�ձ���Ϊ0
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
	//��˳���L���鲢����
	MSort((*L).r, &((*L).r), 1, (*L).length);
}//MergeSort

void MSort(RcdType SR[], RcdType TR1[], int s, int t)
{
	//��SR[s..t]�鲢����ΪTR1[s..t]
	int m;
	RcdType TR2[MAXSIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		m = (s + t) / 2;//��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]
		MSort(SR, &TR2, s, m);//��SR[s..m]�鲢ΪTR2[s.m]
		MSort(SR, &TR2, m+1, t);//��SR[m+1..t]�鲢ΪTR2[m+1..t]
		Merge(TR2, &TR1, s, m, t);//��TR2[s..m]��SR[m+1..t]�鲢��TR1[s..t]
	}
}//MSort

void Merge(RcdType SR[], RcdType* TR[], int i, int m, int n)
{
	//�������������SR[i..m]��SR[m+1..n]�鲢Ϊһ����������TR[i..n]
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)//��SR�м�¼��С����ز���TR
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