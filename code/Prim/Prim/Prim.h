#pragma once
#ifndef PRIM_H
#define PRIM_H

#include <stdlib.h>
#include "Status.h"
#include "AdjacencyMatrix.h"

typedef struct{
	VertexType adjvex;//U���еĶ������
	VRType lowcost;//�ߵ�Ȩֵ
}Edge[MAX_VERTEX_NUM];

void MiniSpanTree_PRIM(MGraph G, VertexType u);

#endif
