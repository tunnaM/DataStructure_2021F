//
//  SequenceStack.h
//  Ex02_Stack
//
//  Created by WangGang on 2019/spring.
//  Copyright © 2019 WangGang. All rights reserved.
//

#ifndef SequenceStack_h
#define SequenceStack_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define STACK_INIT_SIZE    100   //顺序栈存储空间初始分配量
#define STACKINCREMENT    10     //顺序栈存储空间分配增量

/* 顺序栈类型定义 */
//#ifndef SELEMTYPE_SQ
//#define SELEMTYPE_SQ
typedef int SElemType_Sq;
//#endif
typedef struct
{
    SElemType_Sq* base; //SElemType_Sq *base;    //在栈构造之前和销毁之后,base的值为NULL
    SElemType_Sq* top;  //SElemType_Sq *top;     //栈顶指针
    int stacksize;         //当前已分配的存储空间,以元素为单位
}SqStack;

/* 顺序栈函数列表 */
Status InitStack_Sq(SqStack* S); //构造空栈S
Status DestroyStack_Sq(SqStack* S); //销毁S
Status ClearStack_Sq(SqStack* S); //置空S
Status StackEmpty_Sq(SqStack S); //判断S是否为空
int StackLength_Sq(SqStack S); //返回S元素个数
Status GetTop_Sq(SqStack S, SElemType_Sq* e); //用e获取栈顶元素
Status Push_Sq(SqStack* S, SElemType_Sq e); //元素e入栈
Status Pop_Sq(SqStack* S, SElemType_Sq* e); //元素e出栈
Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq)); //遍历访问栈

#endif /* SequenceStack_h */
