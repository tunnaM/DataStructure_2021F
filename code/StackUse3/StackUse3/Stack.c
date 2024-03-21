#include "Stack.h"
#include <stdio.h>
#include <malloc.h>

Status InitStack_OPTR(SqStack_OPTR* S)
{
	(*S).base = (SElemType1*)malloc(STACK_INIT_SIZE * sizeof(SElemType1));
	if (!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

Status InitStack_OPND(SqStack_OPND* S)
{
	(*S).base = (SElemType2*)malloc(STACK_INIT_SIZE * sizeof(SElemType2));
	if (!(*S).base)
		exit(OVERFLOW);
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

Status Push_OPTR(SqStack_OPTR* S, SElemType1 e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		//栈满，追加存储空间
		(*S).base = (SElemType1*)realloc((*S).base, ((*S).stacksize + STACK_INIT_SIZE) * sizeof(SElemType1));
		if (!(*S).base)
			exit(OVERFLOW);//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;//修改top
	}
	*(*S).top++ = e;
	return OK;
}

Status Push_OPND(SqStack_OPND* S, SElemType2 e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		//栈满，追加存储空间
		(*S).base = (SElemType2*)realloc((*S).base, ((*S).stacksize + STACK_INIT_SIZE) * sizeof(SElemType2));
		if (!(*S).base)
			exit(OVERFLOW);//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;//修改top
	}
	*(*S).top++ = e;
	return OK;
}

Status Pop_OPTR(SqStack_OPTR* S, SElemType1* e)
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *(--(*S).top);
	return OK;
}

Status Pop_OPND(SqStack_OPND* S, SElemType2* e)
{
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *(--(*S).top);
	return OK;
}

Status GetTop_OPTR(SqStack_OPTR S, SElemType1* e)
{
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}

Status GetTop_OPND(SqStack_OPND S, SElemType2* e)
{
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}