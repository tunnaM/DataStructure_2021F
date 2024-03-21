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
	for (j = 0; j < G.vexnum; ++j)//���������ʼ��
		if (j != k)
		{
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj;
		}//if
	closedge[k].lowcost = 0;//��ʼ��U={u}
	printf("��С�����������ĸ�����Ϊ:\n");
	for (int i = 1; i < G.vexnum; ++i)
	{
		//ѡ������G.vexnum-1������
		k = minimum(closedge,G);//���T����һ����㣺��k����
		//��ʱclosegde[k].lowcost=MIN{closedge[vi].lowcost|closedge[vi].lowcost>0}
		printf("%d %d\n",closedge[k].adjvex, G.vexs[k]);//�����
		closedge[k].lowcost = 0;//��k���㲢��U��
		for(int j=0;j<G.vexnum;++j)
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{
				//�¶��㲢��U������ѡ����С��
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j].adj;
			}//if
	}//for
}//MiniSpanTree

int minimum(Edge SZ, MGraph G)
{ 
	//��closedge.lowcost����С��ֵ
	int i = 0;
	int j, k, min;
	while (!SZ[i].lowcost)
		i++;
	min = SZ[i].lowcost; //��һ����Ϊ0��ֵ
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
