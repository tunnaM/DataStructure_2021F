#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
#include "TopologicalSort.h"
#include "Stack.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status TopologicalSort(ALGraph G)
{
	//有向图采用邻接表存储结构
	SqStack S;
	int count, k, i;
	ArcNode* p;
	int indegree[MAX_VERTEX_NUM];
	FindInDegree(G, indegree);//对各顶点求入度indegree[0..vernum-1]
	InitStack(&S);
	for (i = 1; i < G.vexnum; ++i)//零入度顶点入栈S
		if (!indegree[i])//入度为0者进栈
			Push(&S, i);
	count = 0;//对输出顶点计数
	while (!StackEmpty(S))
	{
		Pop(&S, &i);
		printf("%c\n",G.vertices[i].data);
		++count;//输出i号顶点并计数
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;//对i号顶点的每个邻接点的入度减1
			if (!(--indegree[k]))
				Push(&S, k);//入度减为0入栈
		}//for
	}//while
	if (count < G.vexnum)
		return ERROR;//该有向图有回路
	else
		return OK;
}//TopologicalSort

void FindInDegree(ALGraph G, int indegree[])
{ 
	//求顶点的入度
	int i;
	ArcNode* p;
	for (i = 1; i <= G.vexnum; i++)
		indegree[i] = 0; //赋初值
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
