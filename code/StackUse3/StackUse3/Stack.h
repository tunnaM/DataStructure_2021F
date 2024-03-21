#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "Status.h"

#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量

typedef char SElemType1;
typedef float SElemType2;
typedef int Status;

typedef struct {
	SElemType1* base;//在构造栈前和销毁栈后,base的值为NULL
	SElemType1* top;//栈顶指针
	int stacksize;//当前分配的元素空间以元素为单位
} SqStack_OPTR;

typedef struct {
	SElemType2* base;//在构造栈前和销毁栈后,base的值为NULL
	SElemType2* top;//栈顶指针
	int stacksize;//当前分配的元素空间以元素为单位
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
