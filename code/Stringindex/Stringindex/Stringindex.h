#ifndef STRINGINDEX_H
#define STRINGINDEX_H

#include <stdlib.h>
#include "Status.h"

#define MAXSTRLEN 255//�û�Ԥ������󴮳�
typedef unsigned char SString[MAXSTRLEN + 1];//0�ŵ�Ԫ��Ŵ��ĳ���

int Index(SString S, SString T, int pos);
void get_next(SString T, int *next[]);
int Index_KMP(SString S, SString T, int pos);
Status StrAssign(SString T, char* chars);
void StrPrint(SString T);


#endif