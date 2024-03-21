#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdlib.h>
#include "Status.h"

typedef int Status;
typedef int QElemType;
/*�����н��ʵ��*/
typedef struct	QNode
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
/*��������������ʵ��*/
typedef struct//����������
{
	QueuePtr front;//��ͷָ��
	QueuePtr rear;//��βָ��
}LinkQueue;

Status InitQueue(LinkQueue* Q);//��ʼ������
Status DestroyQueue(LinkQueue* Q);//���ٶ���
Status QueueEmpty(LinkQueue Q);//�ж����Ƿ��
int QueueLength(LinkQueue Q);//����г���
Status GetHead(LinkQueue Q, QElemType* e);//ȡ��ͷԪ��
Status ClearQueue(LinkQueue* Q);//��ն���
Status EnQueue(LinkQueue* Q, QElemType e);//�����
Status DeQueue(LinkQueue* Q, QElemType* e);//������
Status visit(QElemType e);
Status QueueTraverse(LinkQueue* Q, Status(*visit)(QElemType* e));//��������


#endif