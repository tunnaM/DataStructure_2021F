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

Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}

int StackLength(SqStack S)
{
	return S.top - S.base;
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

Status GetTop(SqStack S, SElemType* e)
{
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}

Status visit(SElemType e)
{
	printf("%d ", e);
	return OK;
}

Status StackTravers(SqStack* S)
{
	if (!(*S).base)
		exit(OVERFLOW);
	if ((*S).top == (*S).base)
		printf("ջΪ��");
	SElemType* p = (*S).base;
	while (p < (*S).top)
	{
		visit(*p);
		p++;
	}
	printf("\n");
	return OK;
}
