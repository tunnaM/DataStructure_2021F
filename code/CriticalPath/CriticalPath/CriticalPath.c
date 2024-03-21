#define _CRT_SECURE_NO_WARNINGS
#include "CriticalPath.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>


Status CriticalPath(ALGraph G)
{
	//G为有向网，输出G的关键活动
	SqStack T;
	int a, j, k, el, ee, dut;
	char tag;
	ArcNode* p;
	int vl[MAX_VERTEX_NUM];
	if (!TopologicalOrder(G, &T))//产生有向环
		return ERROR;
	//j=ve[0];
	for (a = 1; a <= G.vexnum; a++)
		vl[a] = ve[G.vexnum];
	while (!StackEmpty(T))//按拓扑逆序求各顶点的vl值
		for (Pop(&T, &j), p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = *(p->info);//dut<j,k>
			if (vl[k] - dut < vl[j])
				vl[j] = vl[k] - dut;
		}//for
		for (j = 1; j <= G.vexnum; ++j)//求ee,el的关键活动
			for (p = G.vertices[j].firstarc; p; p = p->nextarc)
			{
				k = p->adjvex;
				dut = *(p->info);
				ee = ve[j];
				el = vl[k] - dut;
				tag = (ee == el) ? '*' : ' ';
				printf("%d %d %d %d %d %c\n", j, k, dut, ee, el, tag);//输出关键活动
			}//for
	return OK;
}