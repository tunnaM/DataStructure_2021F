#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

int LocateVex(ALGraph G, VertexType u)//返回顶点u在vertices数组中的位置
{
	for (int i = 0; i <= G.vexnum; i++)
	{
		if (G.vertices[i].data == u)
			return i;
	}
	return ERROR;
}

Status CreateUDG(ALGraph* G)
{
	ArcNode* p, * q;
	int i, j, k;
	VertexType v1, v2;
	ArcNode* r[MAX_VERTEX_NUM + 1];
	printf("输入图的顶点数 边数:");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum));//顶点和边个数
	getchar();
	printf("输入每个顶点的信息：\n");
	for (i = 1; i <= (*G).vexnum; i++)
	{
		printf("输入第%d个顶点的信息：", i);
		scanf("%c", &((*G).vertices[i].data));//顶点信息
		getchar();
		(*G).vertices[i].firstarc = NULL;
		r[i] = NULL;
	}

	for (k = 1; k <= (*G).arcnum; k++)
	{
		//依次输入每个边信息
		printf("输入一条边的起点和终点的编号：");
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(*G, v1);//需查找顶点编号
		j = LocateVex(*G, v2);

		p = (ArcNode*)malloc(sizeof(ArcNode));
		if (!p)
			exit(OVERFLOW);
		p->adjvex = j;
		p->nextarc = NULL;
		if (r[i] == NULL)//邻接表中第一个结点
			(*G).vertices[i].firstarc = p;//加入到邻接表
		else
			r[i]->nextarc = p;
		r[i] = p;
	}
	return OK;
}//CreateUDG
