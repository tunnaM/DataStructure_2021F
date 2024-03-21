#pragma once
#pragma warning(disable:4996)
#include "CircleQueue.h"
#include <stdio.h>

Status InitQueue(SqQueue* Q)
{
	(*Q).base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!(*Q).base)
		exit(OVERFLOW);//�洢����ʧ��
	(*Q).front = (*Q).rear = MAXQSIZE - 1;
	return OK;
}

Status EnQueue(SqQueue* Q, QElemType e)
{
	//����Ԫ��eΪQ���µĶ�βԪ��
	if (((*Q).rear + 1) % MAXQSIZE == (*Q).front)
	{
		printf("����\n");
		return ERROR;//������
	}
	(*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
	(*Q).base[(*Q).rear] = e;
	printf("�����ֵΪ%d\n", e);
	return OK;
}

Status DeQueue(SqQueue* Q, QElemType* e)
{
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*Q).front == (*Q).rear)
		return ERROR;
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MAXQSIZE;
	return OK;
}

