#pragma once
#ifndef PRIM_H
#define PRIM_H

#include <stdlib.h>
#include "Status.h"
#include "AdjacencyMatrix.h"

typedef struct{
	VertexType adjvex;//U集中的顶点序号
	VRType lowcost;//边的权值
}Edge[MAX_VERTEX_NUM];

void MiniSpanTree_PRIM(MGraph G, VertexType u);

#endif
