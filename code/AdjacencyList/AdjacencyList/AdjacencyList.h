#pragma once
#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <stdlib.h>
#include "Status.h"

typedef int InfoType;
typedef int VertexType;
typedef int Boolean;
#define MAX_VERTEX_NUM 20
//�߱�Ĵ洢����
typedef struct ArcNode
{
	int adjvex;//�û���ָ��Ķ����λ��
	struct ArcNode* nextarc;//ָ����һ������ָ��
	InfoType* info;//�û������Ϣ��ָ��
}ArcNode;
//�����Ĵ洢����
typedef struct VNode
{
	VertexType data;//������Ϣ
	ArcNode* firstarc;//ָ���һ�������ö���Ļ�
}VNode,AdjList[MAX_VERTEX_NUM];
//ͼ���ڽӱ�洢����
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;//ͼ�������־
}ALGraph;

int LocateVex(ALGraph G, VertexType u);
Status CreateUDG(ALGraph* G);
void DFSTraverse(ALGraph G);
void DFS(ALGraph G, int v);
void Visit(ALGraph G, int v);
int FirstAdjVex(ALGraph G, int v);
int NextAdjVex(ALGraph G, int v, int w);
void BFSTraverse(ALGraph G);

#endif

