#ifndef STRINGINDEX_H
#define STRINGINDEX_H

#include <stdlib.h>
#include "Status.h"

#define MAXSTRLEN 255//用户预定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1];//0号单元存放串的长度

int Index(SString S, SString T, int pos);
void get_next(SString T, int *next[]);
int Index_KMP(SString S, SString T, int pos);
Status StrAssign(SString T, char* chars);
void StrPrint(SString T);


#endif