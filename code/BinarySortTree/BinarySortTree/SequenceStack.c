//
//  SequenceStack.c
//  Ex02_Stack
//
//  Created by WangGang on 2019/spring.
//  Copyright © 2019 WangGang. All rights reserved.
//

#include "SequenceStack.h"

/* 构造空栈S */
//Status InitStack_Sq(SqStack *S)
//{
//    (*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
//    if(!(*S).base)
//        exit(OVERFLOW);
//    (*S).top = (*S).base;
//    (*S).stacksize = STACK_INIT_SIZE;
//    return OK;
//}
// or
Status InitStack_Sq(SqStack* S)
{
    S->base = (SElemType_Sq*)malloc(STACK_INIT_SIZE * sizeof(SElemType_Sq));
    if (!S->base)
        exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

/* 销毁S */
Status DestroyStack_Sq(SqStack* S)
{
    free((*S).base);
    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stacksize = 0;
    return OK;
}

/* 置空S */
Status ClearStack_Sq(SqStack* S)
{
    (*S).top = (*S).base;
    return OK;
}

/* 判断S是否为空 */
Status StackEmpty_Sq(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

/* 返回S元素个数 */
int StackLength_Sq(SqStack S)
{
    return S.top - S.base;
}

/* 用e获取栈顶元素 */
Status GetTop_Sq(SqStack S, SElemType_Sq* e)
{
    if (S.top == S.base)
        return ERROR;
    *e = *(S.top - 1);
    return OK;
}

/* 元素e入栈 */
Status Push_Sq(SqStack* S, SElemType_Sq e)
{
    if ((*S).top - (*S).base >= (*S).stacksize)  //栈满,追加空间
    {
        (*S).base = (SElemType_Sq*)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType_Sq));
        if (!(*S).base)
            exit(OVERFLOW);  //存储分配失败
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    *S->top = e;   //进栈先赋值，栈顶指针再自增
    (S->top)++;     // *(S->top) = e; (S->top)++;  <===> *S->top++ = e;
    return OK;
}

/* 元素e出栈 */
Status Pop_Sq(SqStack* S, SElemType_Sq* e)
{
    if ((*S).top == (*S).base)
        return ERROR;
    (*S).top--;    //出栈栈顶指针先递减,再赋值
    *e = *((*S).top);
    return OK;
}

/* 遍历访问栈 */
Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq))
{
    SElemType_Sq* p = S.base;
    while (p < S.top)
        Visit(*p++);
    return OK;
}

