#pragma once
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <stdlib.h>
#include "Status.h"

#define INFINITY INT_MAX//最大值
#define MAX_VERTEX_NUM 20 //最大顶点个数

typedef int VRType;
typedef int InfoType;
typedef int VertexType;
typedef enum{ DG,DN,UDG,UDN } GraphKind;
//{DG有向图，DN有向网，UDG无向图，UDN无向网}
typedef struct ArcCell
{
	VRType adj;//VRType是顶点关系类型
	//对无权图，用1或0表示相邻否；对带权图，则为权值类型
	InfoType* info;//该弧相关信息的指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct//图的类型定义
{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum, arcnum;//图的当前顶点数和弧数
	GraphKind kind;//图的种类标志
}MGraph;

int LocateVex(MGraph G, VRType point);
Status CreateUDN(MGraph* G);


#endif
