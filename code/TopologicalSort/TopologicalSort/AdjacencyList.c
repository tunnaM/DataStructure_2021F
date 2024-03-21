#define _CRT_SECURE_NO_WARNINGS
#include "AdjacencyList.h"
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
		printf("�����%d���������Ϣ��", i);
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
	}
	return OK;
}//CreateUDG
