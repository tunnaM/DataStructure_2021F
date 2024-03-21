#define _CRT_SECURE_NO_WARNINGS
#include "TopologicalOrder.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

Status TopologicalOrder(ALGraph G, SqStack* T)
{
	//有向图采用邻接表存储结构,求各事件的最早发生时间ve（全局变量）。
	//T为拓扑序列顶点栈，S为零入度顶点栈
	SqStack S;
	int count = 0;
	int k, j;
	int indegree[40];
	ArcNode* p;
	InitStack(&S);
	FindInDegree(G, indegree);//对各顶点求入度indegree
	for (j = 1; j <= G.vexnum; ++j)//零入度顶点入栈S
		if (!indegree[j])//入度为0者进栈
			Push(&S, j);
	InitStack(&(*T));//建拓扑序列顶点栈T
	count = 0;//对输出顶点计数
	for (int i = 1; i <= G.vexnum; i++)
		ve[i] = 0;//初始化
	while (!StackEmpty(S))
	{
		Pop(&S, &j);
		Push(&(*T), j);
		++count;//顶点入栈并计数
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;//对j号顶点的每个邻接点的入度减1
			if (--indegree[k]==0)
				Push(&S, k);//入度为0,入栈
			if (ve[j] + *(p->info) > ve[k])
				ve[k] = ve[j] + *(p->info);
		}//*(p->info)=dut(<j,k>)
	}//while
	if (count < G.vexnum)
		return ERROR;//该有向图有回路
	else
		return OK;
}//TopologicalOrder

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
