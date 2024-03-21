#pragma once
#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H

#include <stdlib.h>
#include "Status.h"

#define MAXQSIZE 100//最大队列长度

typedef int Status;
typedef int QElemType;
typedef struct
{
	QElemType* base;//动态分配存储空间
	int front;//头指针，若队列不空，指向队列头元素
	int rear;//尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;


Status InitQueue(SqQueue* Q);//初始化循环队列
Status EnQueue(SqQueue* Q, QElemType e);//入队列
Status DeQueue(SqQueue* Q, QElemType* e);//出队列


/*Status DestroyQueue(LinkQueue* Q);//销毁队列
Status QueueEmpty(LinkQueue Q);//判队列是否空
int QueueLength(LinkQueue Q);//求队列长度
Status GetHead(LinkQueue Q, QElemType* e);//取队头元素
Status ClearQueue(LinkQueue* Q);//清空队列
Status EnQueue(LinkQueue* Q, QElemType e);//入队列
Status DeQueue(LinkQueue* Q, QElemType* e);//出队列
Status visit(QElemType e);
Status QueueTraverse(LinkQueue* Q, Status(*visit)(QElemType* e));//遍历队列*/


#endif