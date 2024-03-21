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
	printf("输入顶点值：");
	for (i = 0; i < (*G).vexnum; i++)
	{
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

int visited[MAX_VERTEX_NUM] = { 0 };
void DFSTraverse(MGraph G)
{
	//对图G作深度优先遍历
	int v = 0;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;//访问标志数组初始化
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])//对尚未访问的顶点调用DFS
			DFS(G, v);
	}
}

void DFS(MGraph G, int v)
{
	//从顶点v出发，深度优先搜索遍历连通图G
	visited[v] = TRUE;
	Visit(v);//访问v
	int w;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])//对v的尚未访问的邻接顶点w
			DFS(G, w);//递归调用DFS
	}
}//DFS