#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include "Status.h"

#define MAXSTRLEN 255//用户预定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1];//0号单元存放串的长度


Status StrAssign(SString T, char* chars);//根据串常量chars生成串T
Status SubString(SString Sub, SString S, int pos, int len);//求子串
void DestroyString(SString S);//销毁串S
Status ClearString(SString S);//清空串S
Status StrCopy(SString T, SString S);//把串S的内容拷贝到串T
int Index(SString S, SString T, int pos);//子串定位
int StrLength(SString S);//求串长
Status Replace(SString S, SString T, SString V);//把串S中符合T的子串替换
int StrCompare(SString S, SString T);//比较串S和T
Status StrInsert(SString S, int pos, SString T);//插入子串
Status Concat(SString T, SString S1, SString S2);//联接串
Status StrEmpty(SString S);//判断串是否空
void StrPrint(SString T);//打印串

#endif