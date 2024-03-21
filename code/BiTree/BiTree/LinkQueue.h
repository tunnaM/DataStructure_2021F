#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdlib.h>
#include "Status.h"

typedef int Status;
typedef int QElemType;
/*链队列结点实现*/
typedef struct	QNode
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;
/*链队列数据类型实现*/
typedef struct//链队列类型
{
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

Status InitQueue(LinkQueue* Q);//初始化队列
Status DestroyQueue(LinkQueue* Q);//销毁队列
Status QueueEmpty(LinkQueue Q);//判队列是否空
int QueueLength(LinkQueue Q);//求队列长度
Status GetHead(LinkQueue Q, QElemType* e);//取队头元素
Status ClearQueue(LinkQueue* Q);//清空队列
Status EnQueue(LinkQueue* Q, QElemType e);//入队列
Status DeQueue(LinkQueue* Q, QElemType* e);//出队列
Status visit(QElemType e);
Status QueueTraverse(LinkQueue* Q, Status(*visit)(QElemType* e));//遍历队列


#endif