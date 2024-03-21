#pragma once
#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include <stdlib.h>
#include "Status.h"

#define INFINITY INT_MAX//���ֵ
#define MAX_VERTEX_NUM 20 //��󶥵����

typedef int VRType;
typedef int InfoType;
typedef int VertexType;
typedef enum{ DG,DN,UDG,UDN } GraphKind;
//{DG����ͼ��DN��������UDG����ͼ��UDN������}
typedef struct ArcCell
{
	VRType adj;//VRType�Ƕ����ϵ����
	//����Ȩͼ����1��0��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ����
	InfoType* info;//�û������Ϣ��ָ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct//ͼ�����Ͷ���
{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;//ͼ�������־
}MGraph;

int LocateVex(MGraph G, VRType point);
Status CreateUDN(MGraph* G);


#endif
