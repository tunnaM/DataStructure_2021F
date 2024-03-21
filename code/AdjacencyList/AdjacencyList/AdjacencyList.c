#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
#include "LinkQueue.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

int LocateVex(ALGraph G, VertexType u)//���ض���u��vertices�����е�λ��
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
	printf("����ͼ�Ķ����� ����:");
	scanf("%d %d", &((*G).vexnum), &((*G).arcnum));//����ͱ߸���
	getchar();
	printf("����ÿ���������Ϣ��\n");
	for (i = 1; i <= (*G).vexnum; i++)
	{
		printf("�����%d���������Ϣ��",i);
		scanf("%c", &((*G).vertices[i].data));//������Ϣ
		getchar();
		(*G).vertices[i].firstarc = NULL;
		r[i] = NULL;
	}
	
	for (k = 1; k <= (*G).arcnum; k++)
	{
		//��������ÿ������Ϣ
		printf("����һ���ߵ������յ�ı�ţ�");
		scanf("%c %c", &v1, &v2);
		getchar();
		i = LocateVex(*G, v1);//����Ҷ�����
		j = LocateVex(*G, v2);

		p = (ArcNode*)malloc(sizeof(ArcNode));
		if (!p)
			exit(OVERFLOW);
		p->adjvex = j;
		p->nextarc = NULL;
		if (r[i] == NULL)//�ڽӱ��е�һ�����
			(*G).vertices[i].firstarc = p;//���뵽�ڽӱ�
		else
			r[i]->nextarc = p;
		r[i] = p;

		q = (ArcNode*)malloc(sizeof(ArcNode));
		if (!q)
			exit(OVERFLOW);
		q->adjvex = i;
		q->nextarc = NULL;
		if (r[j] == NULL)//�ڽӱ��е�һ�����
			(*G).vertices[j].firstarc = q;//���뵽�ڽӱ�
		else
			r[j]->nextarc = q;
		r[j] = q;
	}
	return OK;
}//CreateUDG

Boolean visited[MAX_VERTEX_NUM+1];
void DFSTraverse(ALGraph G)
{
	//��ͼG��������ȱ���
	int v = 0;
	printf("DFSGraph:\n");
	for (v = 1; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;//���ʱ�־�����ʼ��
	}
	for (v = 1; v < G.vexnum; ++v)
	{
		if (!visited[v])//����δ���ʵĶ������DFS
			DFS(G, v);
	}
}

void DFS(ALGraph G, int v)
{
	//�Ӷ���v�����������������������ͨͼG
	visited[v] = TRUE;
	Visit(G, v);//����v
	int w;
	for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
	{
		if (!visited[w])//��v����δ���ʵ��ڽӶ���w
			DFS(G, w);//�ݹ����DFS
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
		visited[v] = FALSE;//��ʼ����־
	InitQueue(&Q);//�ÿյĸ�������Q
	for (v = 1; v <= G.vexnum; ++v)
		if (!visited[v])
		{
			//vδ������
			visited[v] = TRUE;
			Visit(G, v);//����v
			EnQueue(&Q, v);//v�����
			while (!QueueEmpty(Q))
			{
				DeQueue(&Q, &u);//��ͷԪ�س��Ӳ���Ϊu
				for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
					if (!visited[w])
					{
						//wΪu����δ�����ʵ��ڽӶ���
						visited[w] = TRUE;
						Visit(G, w);//����w
						EnQueue(&Q, w);//���ʵĶ���w�����
					}//if
			}//while
		}//if
}//BFSTraverse