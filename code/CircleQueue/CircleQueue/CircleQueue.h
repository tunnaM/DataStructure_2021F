#pragma once
#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H

#include <stdlib.h>
#include "Status.h"

#define MAXQSIZE 100//�����г���

typedef int Status;
typedef int QElemType;
typedef struct
{
	QElemType* base;//��̬����洢�ռ�
	int front;//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;


Status InitQueue(SqQueue* Q);//��ʼ��ѭ������
Status EnQueue(SqQueue* Q, QElemType e);//�����
Status DeQueue(SqQueue* Q, QElemType* e);//������


/*Status DestroyQueue(LinkQueue* Q);//���ٶ���
Status QueueEmpty(LinkQueue Q);//�ж����Ƿ��
int QueueLength(LinkQueue Q);//����г���
Status GetHead(LinkQueue Q, QElemType* e);//ȡ��ͷԪ��
Status ClearQueue(LinkQueue* Q);//��ն���
Status EnQueue(LinkQueue* Q, QElemType e);//�����
Status DeQueue(LinkQueue* Q, QElemType* e);//������
Status visit(QElemType e);
Status QueueTraverse(LinkQueue* Q, Status(*visit)(QElemType* e));//��������*/


#endif