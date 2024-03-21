#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "Status.h"

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ��������

typedef char SElemType1;
typedef float SElemType2;
typedef int Status;

typedef struct {
	SElemType1* base;//�ڹ���ջǰ������ջ��,base��ֵΪNULL
	SElemType1* top;//ջ��ָ��
	int stacksize;//��ǰ�����Ԫ�ؿռ���Ԫ��Ϊ��λ
} SqStack_OPTR;

typedef struct {
	SElemType2* base;//�ڹ���ջǰ������ջ��,base��ֵΪNULL
	SElemType2* top;//ջ��ָ��
	int stacksize;//��ǰ�����Ԫ�ؿռ���Ԫ��Ϊ��λ
} SqStack_OPND;


Status InitStack_OPTR(SqStack_OPTR* S);
Status InitStack_OPND(SqStack_OPND* S);
Status Push_OPTR(SqStack_OPTR* S, SElemType1 e);
Status Push_OPND(SqStack_OPND* S, SElemType2 e);
Status Pop_OPTR(SqStack_OPTR* S, SElemType1* e);
Status Pop_OPND(SqStack_OPND* S, SElemType2* e);
Status GetTop_OPTR(SqStack_OPTR S, SElemType1* e);
Status GetTop_OPND(SqStack_OPND S, SElemType2* e);
Status In(char e, char OP[]);
Status Precede(char m, char n);
Status Operate(SElemType2 a, char theta, SElemType2 b);

#endif
