#ifndef INSERTSORT_H
#define INSERTSORT_H

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
typedef SqList HeapType;//定义堆类型：采用顺序表表示

Status InitList_Sq(HeapType* H);
Status ListTraverse_Sq(HeapType H, void(Visit)(KeyType));
void HeapSort(HeapType* H);//对顺序表H进行堆排序
void HeapAdjust(HeapType* H, int s, int m);

#endif