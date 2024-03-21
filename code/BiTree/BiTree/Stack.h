#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "Status.h"

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������

typedef int SElemType;
typedef struct
{
	SElemType* base;//ջ��ָ��
	SElemType* top;//ջ��ָ��
	int stacksize;//��ǰ��ʹ���������������ջ��Ԫ�ظ���
}SqStack;

Status InitStack(SqStack* S);
Status DestroyStack(SqStack* S);
Status ClearStack(SqStack* S);
Status StackEmpty(SqStack S);
Status Push(SqStack* S, SElemType e);
int StackLength(SqStack S);
Status Pop(SqStack* S, SElemType* e);
Status GetTop(SqStack S, SElemType* e);
Status visitStack(SElemType e);
Status StackTravers(SqStack* S);
#endif
