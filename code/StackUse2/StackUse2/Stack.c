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
		//栈满，追加存储空间
		(*S).base = (SElemType*)realloc((*S).base, ((*S).stacksize + STACK_INIT_SIZE) * sizeof(SElemType));
		if (!(*S).base)
			exit(OVERFLOW);//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;//修改top
	}
	*(*S).top++ = e;
	return OK;
}

Status Pop(SqStack* S, SElemType* e)
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *(--(*S).top);
	return OK;
}
