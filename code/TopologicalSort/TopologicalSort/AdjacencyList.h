#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <stdlib.h>
#include "Status.h"

#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef int VertexType;
//边表的存储类型
typedef struct ArcNode
{
	int adjvex;//该弧所指向的顶点的位置
	struct ArcNode* nextarc;//指向下一条弧的指针
	InfoType* info;//该弧相关信息的指针
}ArcNode;
//顶点表的存储类型
typedef struct VNode
{
	VertexType data;//顶点信息
	ArcNode* firstarc;//指向第一条依附该顶点的弧
}VNode, AdjList[MAX_VERTEX_NUM];
//图的邻接表存储类型
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;//图的种类标志
}ALGraph;

int LocateVex(ALGraph G, VertexType u);
Status CreateUDG(ALGraph* G);

#endif

