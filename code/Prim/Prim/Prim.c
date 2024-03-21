#define _CRT_SECURE_NO_WARNINGS
#include "Prim.h"
#include "AdjacencyMatrix.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

void MiniSpanTree_PRIM(MGraph G, VertexType u)
{
	int j = 0;
	int k = LocateVex(G, u);
	Edge closedge;
	for (j = 0; j < G.vexnum; ++j)//辅助数组初始化
		if (j != k)
		{
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj;
		}//if
	closedge[k].lowcost = 0;//初始，U={u}
	printf("最小代价生成树的各条边为:\n");
	for (int i = 1; i < G.vexnum; ++i)
	{
		//选择其余G.vexnum-1个顶点
		k = minimum(closedge,G);//求出T的下一个结点：第k顶点
		//此时closegde[k].lowcost=MIN{closedge[vi].lowcost|closedge[vi].lowcost>0}
		printf("%d %d\n",closedge[k].adjvex, G.vexs[k]);//输出边
		closedge[k].lowcost = 0;//第k顶点并入U集
		for(int j=0;j<G.vexnum;++j)
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{
				//新顶点并入U后重新选择最小边
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j].adj;
			}//if
	}//for
}//MiniSpanTree

int minimum(Edge SZ, MGraph G)
{ 
	//求closedge.lowcost的最小正值
	int i = 0;
	int j, k, min;
	while (!SZ[i].lowcost)
		i++;
	min = SZ[i].lowcost; //第一个不为0的值
	k = i;
	for (j = i + 1; j < G.vexnum; j++)
		if (SZ[j].lowcost > 0)
			if (min > SZ[j].lowcost)
			{
				min = SZ[j].lowcost;
				k = j;
			}
	return k;
}
