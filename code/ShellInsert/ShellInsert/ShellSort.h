#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <stdlib.h>
#include "Status.h"

#define MAXSIZE 20//����˳�����󳤶�
typedef int KeyType;//�ؼ�������Ϊ��������
typedef int InfoType;
typedef struct
{
	KeyType key;//�ؼ�����
	InfoType otherinfo;//����������
}RcdType;//��¼����
typedef struct
{
	RcdType r[MAXSIZE + 1];//R[0]���û������ڱ���Ԫ
	int length;//˳�����
}SqList;//˳�������

Status InitList_Sq(SqList* L);
Status ListTraverse_Sq(SqList L, void(Visit)(KeyType));
void MergeSort(SqList* L);
void MSort(RcdType SR[], RcdType* TR1[], int s, int t);
void Merge(RcdType SR[], RcdType* TR[], int i, int m, int n);

#endif