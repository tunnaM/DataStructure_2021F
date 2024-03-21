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
		//ջ����׷�Ӵ洢�ռ�
		(*S).base = (SElemType1*)realloc((*S).base, ((*S).stacksize + STACK_INIT_SIZE) * sizeof(SElemType1));
		if (!(*S).base)
			exit(OVERFLOW);//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;//�޸�top
	}
	*(*S).top++ = e;
	return OK;
}

Status Push_OPND(SqStack_OPND* S, SElemType2 e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		//ջ����׷�Ӵ洢�ռ�
		(*S).base = (SElemType2*)realloc((*S).base, ((*S).stacksize + STACK_INIT_SIZE) * sizeof(SElemType2));
		if (!(*S).base)
			exit(OVERFLOW);//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;//�޸�top
	}
	*(*S).top++ = e;
	return OK;
}

Status Pop_OPTR(SqStack_OPTR* S, SElemType1* e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *(--(*S).top);
	return OK;
}

Status Pop_OPND(SqStack_OPND* S, SElemType2* e)
{
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*S).top == (*S).base)
		return ERROR;
	*e = *(--(*S).top);
	return OK;
}

Status GetTop_OPTR(SqStack_OPTR S, SElemType1* e)
{
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}

Status GetTop_OPND(SqStack_OPND S, SElemType2* e)
{
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base)
		return ERROR;
	*e = *(S.top - 1);
	return OK;
}