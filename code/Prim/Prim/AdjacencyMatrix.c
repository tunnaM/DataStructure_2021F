#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyMatrix.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

int LocateVex(MGraph G, VRType point)	//确定某个顶点在图G中的位置
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == point)
			return i;
}//LocateVex

Status CreateUDN(MGraph* G)
{
	int i, j, k;
	VRType v1, v2, w;
	printf("输入图的顶点数 弧数:");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum));
	for (i = 0; i < (*G).vexnum; i++)
	{
		printf("输入顶点值：");
		scanf("%d", &((*G).vexs[i]));
	}
	for (i = 0; i < (*G).vexnum; i++)
	{
		//初始化邻接矩阵
		for (j = 0; j < (*G).vexnum; j++)
		{
			(*G).arcs[i][j].adj = INFINITY;
			(*G).arcs[i][j].info = NULL;
		}
	}
	for (k = 0; k < (*G).arcnum; k++)
	{
		printf("输入一条边的两端以及权值");
		scanf("%d %d %d", &v1, &v2, &w);
		i = LocateVex(*G, v1);//查找v1在数组vexs中的序号i
		j = LocateVex(*G, v2);//查找v1在数组vexs中的序号i
		(*G).arcs[i][j].adj = w;
		(*G).arcs[j][i].adj = w;
		(*G).arcs[i][j].info = (InfoType*)malloc(sizeof(InfoType));
		(*G).arcs[j][i].info = (InfoType*)malloc(sizeof(InfoType));
		*((*G).arcs[i][j].info) = w;
		*((*G).arcs[j][i].info) = w;
	}
	return OK;
}//CreateUDN
