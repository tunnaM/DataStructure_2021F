#define _CRT_SECURE_NO_WARNINGS
#include "TopologicalOrder.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status TopologicalOrder(ALGraph G, SqStack* T)
{
	//����ͼ�����ڽӱ�洢�ṹ,����¼������緢��ʱ��ve��ȫ�ֱ�������
	//TΪ�������ж���ջ��SΪ����ȶ���ջ
	SqStack S;
	int count = 0;
	int k, j;
	int indegree[40];
	ArcNode* p;
	InitStack(&S);
	FindInDegree(G, indegree);//�Ը����������indegree
	for (j = 1; j <= G.vexnum; ++j)//����ȶ�����ջS
		if (!indegree[j])//���Ϊ0�߽�ջ
			Push(&S, j);
	InitStack(&(*T));//���������ж���ջT
	count = 0;//������������
	for (int i = 1; i <= G.vexnum; i++)
		ve[i] = 0;//��ʼ��
	while (!StackEmpty(S))
	{
		Pop(&S, &j);
		Push(&(*T), j);
		++count;//������ջ������
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;//��j�Ŷ����ÿ���ڽӵ����ȼ�1
			if (--indegree[k]==0)
				Push(&S, k);//���Ϊ0,��ջ
			if (ve[j] + *(p->info) > ve[k])
				ve[k] = ve[j] + *(p->info);
		}//*(p->info)=dut(<j,k>)
	}//while
	if (count < G.vexnum)
		return ERROR;//������ͼ�л�·
	else
		return OK;
}//TopologicalOrder

void FindInDegree(ALGraph G, int indegree[])
{
	//�󶥵�����
	int i;
	ArcNode* p;
	for (i = 1; i <= G.vexnum; i++)
		indegree[i] = 0; //����ֵ
	for (i = 1; i <= G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
}
