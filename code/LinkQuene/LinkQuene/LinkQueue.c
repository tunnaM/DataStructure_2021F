#pragma once
#pragma warning(disable:4996)
#include "LinkQueue.h"
#include <stdio.h>

Status InitQueue(LinkQueue* Q)
{
	//����һ����ͷ�ڵ�Ŀն���
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);//�洢����ʧ��
	(*Q).front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue* Q)
{
	while ((*Q).front) 
	{
		(*Q).rear = (*Q).front->next;
		free((*Q).front);
		(*Q).front = (*Q).rear;
	}
	(*Q).front = NULL;
	(*Q).rear = NULL;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
	// ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{
	//����еĳ���
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue Q, QElemType* e)
{
	//�����в���,����e����Q�Ķ�ͷԪ��,������OK,���򷵻�ERROR
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

Status ClearQueue(LinkQueue* Q)
{
	// ��Q��Ϊ�ն���
	QueuePtr p, q;
	(*Q).rear = (*Q).front;
	p = (*Q).front->next;
	(*Q).front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
}

Status EnQueue(LinkQueue* Q, QElemType e)
{
	//����Ԫ��eΪQ���µĶ�βԪ��
	QueuePtr p = 0;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);//�洢����ʧ��
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType *e)
{
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*Q).front == (*Q).rear)
		return ERROR;
	QueuePtr p = 0;
	p = (*Q).front->next;
	*e = p->data;
	(*Q).front->next = p->next;
	if ((*Q).rear == p)
		(*Q).rear = (*Q).front;
	free(p);
	return OK;
}

Status visit(QElemType e)
{
	printf("%d ", e);
	return OK;
}

Status QueueTraverse(LinkQueue *Q, Status(*visit)(QElemType*))
{
	//�Ӷ�ͷ����β���ζԶ���Q�е�ÿ��Ԫ�ص��ú���visit()������OK��һ��visitʧ�������ʧ��
	//�ǿն����򷵻�ERROR
	if ((*Q).front == (*Q).rear)
		return ERROR;
	QueuePtr p = 0;
	p = (*Q).front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
