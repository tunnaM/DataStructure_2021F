#pragma once
#pragma warning(disable:4996)
#include "CircleQueue.h"
#include <stdio.h>

Status InitQueue(SqQueue* Q)
{
	(*Q).base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!(*Q).base)
		exit(OVERFLOW);//存储分配失败
	(*Q).front = (*Q).rear = MAXQSIZE - 1;
	return OK;
}

Status EnQueue(SqQueue* Q, QElemType e)
{
	//插入元素e为Q的新的队尾元素
	if (((*Q).rear + 1) % MAXQSIZE == (*Q).front)
	{
		printf("队满\n");
		return ERROR;//队列满
	}
	(*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
	(*Q).base[(*Q).rear] = e;
	printf("插入的值为%d\n", e);
	return OK;
}

Status DeQueue(SqQueue* Q, QElemType* e)
{
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
	if ((*Q).front == (*Q).rear)
		return ERROR;
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MAXQSIZE;
	return OK;
}

