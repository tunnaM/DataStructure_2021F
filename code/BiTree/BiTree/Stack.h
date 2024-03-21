#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "Status.h"

#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量

typedef int SElemType;
typedef struct
{
	SElemType* base;//栈底指针
	SElemType* top;//栈顶指针
	int stacksize;//当前可使用最大容量，不是栈中元素个数
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
