#pragma once
#pragma warning(disable:4996)
#include "LinkQueue.h"
#include <stdio.h>

Status InitQueue(LinkQueue* Q)
{
	//构造一个带头节点的空队列
	(*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
	if (!(*Q).front)
		exit(OVERFLOW);//存储分配失败
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
	// 若Q为空队列,则返回TRUE,否则返回FALSE
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{
	//求队列的长度
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
	//若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	*e = p->data;
	return OK;
}

Status ClearQueue(LinkQueue* Q)
{
	// 将Q清为空队列
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
	//插入元素e为Q的新的队尾元素
	QueuePtr p = 0;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);//存储分配失败
	p->data = e;
	p->next = NULL;
	(*Q).rear->next = p;
	(*Q).rear = p;
	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType *e)
{
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
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
	//从对头到队尾依次对队列Q中的每个元素调用函数visit()，返回OK，一旦visit失败则操作失败
	//是空队列则返回ERROR
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
