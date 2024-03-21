#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
#include "LinkQueue.h"
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
		printf("输入第%d个顶点的信息：",i);
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

		q = (ArcNode*)malloc(sizeof(ArcNode));
		if (!q)
			exit(OVERFLOW);
		q->adjvex = i;
		q->nextarc = NULL;
		if (r[j] == NULL)//邻接表中第一个结点
			(*G).vertices[j].firstarc = q;//加入到邻接表
		else
			r[j]->nextarc = q;
		r[j] = q;
	}
	return OK;
}//CreateUDG

Boolean visited[MAX_VERTEX_NUM+1];
void DFSTraverse(ALGraph G)
{
	//对图G作深度优先遍历
	int v = 0;
	printf("DFSGraph:\n");
	for (v = 1; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;//访问标志数组初始化
	}
	for (v = 1; v < G.vexnum; ++v)
	{
		if (!visited[v])//对尚未访问的顶点调用DFS
			DFS(G, v);
	}
}

void DFS(ALGraph G, int v)
{
	//从顶点v出发，深度优先搜索遍历连通图G
	visited[v] = TRUE;
	Visit(G, v);//访问v
	int w;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])//对v的尚未访问的邻接顶点w
			DFS(G, w);//递归调用DFS
	}
}//DFS

void Visit(ALGraph G, int v)
{
	printf("%c ", G.vertices[v].data);
}

int FirstAdjVex(ALGraph G, int v)
{
	if (G.vertices[v].firstarc != NULL)
		return G.vertices[v].firstarc->adjvex;
	return OVERFLOW;
}

int NextAdjVex(ALGraph G, int v, int w)
{
	ArcNode* p;
	p = G.vertices[v].firstarc;
	while (p->adjvex != w)
		p = p->nextarc;
	if (p->nextarc != NULL)
		return p->nextarc->adjvex;
	return OVERFLOW;
}

void BFSTraverse(ALGraph G)
{
	LinkQueue Q;
	int v, w;
	QElemType u = 0;

	for (v = 0; v <= G.vexnum; ++v)
		visited[v] = FALSE;//初始化标志
	InitQueue(&Q);//置空的辅助队列Q
	for (v = 1; v <= G.vexnum; ++v)
		if (!visited[v])
		{
			//v未被访问
			visited[v] = TRUE;
			Visit(G, v);//访问v
			EnQueue(&Q, v);//v入队列
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &u);//队头元素出队并置为u
				for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
					if (!visited[w])
					{
						//w为u的尚未被访问的邻接顶点
						visited[w] = TRUE;
						Visit(G, w);//访问w
						EnQueue(&Q, w);//访问的顶点w入队列
					}//if
			}//while
		}//if
}//BFSTraverse