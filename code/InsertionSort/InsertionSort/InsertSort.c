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
	(*H).length = 0;                    //�ձ���Ϊ0
	return OK;
}

Status ListTraverse_Sq(HeapType H, void(Visit)(KeyType))
{
	int i;
	for (i = 1; i <= H.length; i++)
		Visit(H.r[i].key);
	return OK;
}

void HeapSort(HeapType* H)//��˳���H���ж�����
{
	int i;
	RcdType	swap;
	for (i = (*H).length / 2; i > 0; --i)
		HeapAdjust(&(*H), i, (*H).length);
	for (i = (*H).length; i > 1; --i)
	{
		swap = (*H).r[1];
		(*H).r[1] = (*H).r[i];
		(*H).r[i] = swap;//���Ѷ���¼�͵�ǰδ������������H.r[1..r-1]���µ�����
		HeapAdjust(&(*H), 1, i - 1);//��H.r[1..i-1]���µ�����
	}
}//HeapSort

void HeapAdjust(HeapType* H, int s, int m)
{
	//��֪H.r[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������ѵĶ��壬
	//����������H.r[s]�Ĺؼ��֣�ʹH.r[s..m]��Ϊһ���󶥶�
	int j;
	RcdType rc = (*H).r[s];//�ݴ�H.r[s]
	for (j = 2 * s; j <= m; j *= 2)//��key�ϴ���ӽ������ɸѡ
	{
		if (j < m && (*H).r[j].key < (*H).r[j + 1].key)
			++j;//jΪkey�ϴ�ļ�¼���±�
		if (rc.key >= (*H).r[j].key)
			break;//�ҵ�rc����λ��s������������µ���
		(*H).r[s] = (*H).r[j];
		s = j;//�����¼���ƣ�����������µ���
	}
	(*H).r[s] = rc;//������ǰ�ĶѶ���¼���뵽sλ��
}//HeapAdjust