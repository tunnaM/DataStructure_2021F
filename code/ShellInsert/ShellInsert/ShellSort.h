#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <stdlib.h>
#include "Status.h"

#define MAXSIZE 20//待排顺序表最大长度
typedef int KeyType;//关键字类型为整数类型
typedef int InfoType;
typedef struct
{
	KeyType key;//关键字项
	InfoType otherinfo;//其他数据项
}RcdType;//记录类型
typedef struct
{
	RcdType r[MAXSIZE + 1];//R[0]闲置或用作哨兵单元
	int length;//顺序表长度
}SqList;//顺序表类型

Status InitList_Sq(SqList* L);
Status ListTraverse_Sq(SqList L, void(Visit)(KeyType));
void MergeSort(SqList* L);
void MSort(RcdType SR[], RcdType* TR1[], int s, int t);
void Merge(RcdType SR[], RcdType* TR[], int i, int m, int n);

#endif