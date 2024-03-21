#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyMatrix.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

int LocateVex(MGraph G, VRType point)	//ȷ��ĳ��������ͼG�е�λ��
{
	int i, j;
	for (i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == point)
			return i;
}//LocateVex

Status CreateUDN(MGraph* G)
{
	int i, j, k;
	VRType v1, v2, w;
	printf("����ͼ�Ķ����� ����:");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum));
	printf("���붥��ֵ��");
	for (i = 0; i < (*G).vexnum; i++)
	{
		scanf("%d", &((*G).vexs[i]));
	}
	for (i = 0; i < (*G).vexnum; i++)
	{
		//��ʼ���ڽӾ���
		for (j = 0; j < (*G).vexnum; j++)
		{
			(*G).arcs[i][j].adj = INFINITY;
			(*G).arcs[i][j].info = NULL;
		}
	}
	for (k = 0; k < (*G).arcnum; k++)
	{
		printf("����һ���ߵ������Լ�Ȩֵ");
		scanf("%d %d %d", &v1, &v2, &w);
		i = LocateVex(*G, v1);//����v1������vexs�е����i
		j = LocateVex(*G, v2);//����v1������vexs�е����i
		(*G).arcs[i][j].adj = w;
		(*G).arcs[j][i].adj = w;
		(*G).arcs[i][j].info = (InfoType*)malloc(sizeof(InfoType));
		(*G).arcs[j][i].info = (InfoType*)malloc(sizeof(InfoType));
		*((*G).arcs[i][j].info) = w;
		*((*G).arcs[j][i].info) = w;
	}
	return OK;
}//CreateUDN

int visited[MAX_VERTEX_NUM] = { 0 };
void DFSTraverse(MGraph G)
{
	//��ͼG��������ȱ���
	int v = 0;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;//���ʱ�־�����ʼ��
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])//����δ���ʵĶ������DFS
			DFS(G, v);
	}
}

void DFS(MGraph G, int v)
{
	//�Ӷ���v�����������������������ͨͼG
	visited[v] = TRUE;
	Visit(v);//����v
	int w;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])//��v����δ���ʵ��ڽӶ���w
			DFS(G, w);//�ݹ����DFS
	}
}//DFS