#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <stdlib.h>
#include "Status.h"

#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef int VertexType;
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
}VNode, AdjList[MAX_VERTEX_NUM];
//ͼ���ڽӱ�洢����
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;//ͼ�������־
}ALGraph;

int LocateVex(ALGraph G, VertexType u);
Status CreateUDG(ALGraph* G);

#endif

