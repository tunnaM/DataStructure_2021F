#ifndef INSERTSORT_H
#define INSERTSORT_H

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
typedef SqList HeapType;//��������ͣ�����˳����ʾ

Status InitList_Sq(HeapType* H);
Status ListTraverse_Sq(HeapType H, void(Visit)(KeyType));
void HeapSort(HeapType* H);//��˳���H���ж�����
void HeapAdjust(HeapType* H, int s, int m);

#endif