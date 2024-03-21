#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
#include "TopologicalSort.h"
#include "Stack.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status TopologicalSort(ALGraph G)
{
	//����ͼ�����ڽӱ�洢�ṹ
	SqStack S;
	int count, k, i;
	ArcNode* p;
	int indegree[MAX_VERTEX_NUM];
	FindInDegree(G, indegree);//�Ը����������indegree[0..vernum-1]
	InitStack(&S);
	for (i = 1; i < G.vexnum; ++i)//����ȶ�����ջS
		if (!indegree[i])//���Ϊ0�߽�ջ
			Push(&S, i);
	count = 0;//������������
	while (!StackEmpty(S))
	{
		Pop(&S, &i);
		printf("%c\n",G.vertices[i].data);
		++count;//���i�Ŷ��㲢����
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;//��i�Ŷ����ÿ���ڽӵ����ȼ�1
			if (!(--indegree[k]))
				Push(&S, k);//��ȼ�Ϊ0��ջ
		}//for
	}//while
	if (count < G.vexnum)
		return ERROR;//������ͼ�л�·
	else
		return OK;
}//TopologicalSort

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
