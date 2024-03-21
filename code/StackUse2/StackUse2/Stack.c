#include "Stack.h"
#include <stdio.h>
#include <malloc.h>

Status InitStack(SqStack* S)
{
	(*S).base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack* S)
{
	if ((*S).base)
	{
		free((*S).base);
		(*S).base = NULL;
		(*S).top = NULL;
		(*S).stacksize = 0;
	}
	return OK;
}

Status ClearStack(SqStack* S)
{
	if ((*S).base)
		(*S).top = (*S).base;
	return OK;
}

Status Push(SqStack* S, SElemType e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		//ջ����׷�Ӵ洢�ռ�
		(*S).base = (SElemType*)realloc((*S).base, ((*S).stacksize + STACK_INIT_SIZE) * sizeof(SElemType));
		if (!(*S).base)
			exit(OVERFLOW);//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;//�޸�top
	}
	*(*S).top++ = e;
	return OK;
}

Status Pop(SqStack* S, SElemType* e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *(--(*S).top);
	return OK;
}
