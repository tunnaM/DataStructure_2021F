#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include "Status.h"

#define MAXSTRLEN 255//�û�Ԥ������󴮳�
typedef unsigned char SString[MAXSTRLEN + 1];//0�ŵ�Ԫ��Ŵ��ĳ���


Status StrAssign(SString T, char* chars);//���ݴ�����chars���ɴ�T
Status SubString(SString Sub, SString S, int pos, int len);//���Ӵ�
void DestroyString(SString S);//���ٴ�S
Status ClearString(SString S);//��մ�S
Status StrCopy(SString T, SString S);//�Ѵ�S�����ݿ�������T
int Index(SString S, SString T, int pos);//�Ӵ���λ
int StrLength(SString S);//�󴮳�
Status Replace(SString S, SString T, SString V);//�Ѵ�S�з���T���Ӵ��滻
int StrCompare(SString S, SString T);//�Ƚϴ�S��T
Status StrInsert(SString S, int pos, SString T);//�����Ӵ�
Status Concat(SString T, SString S1, SString S2);//���Ӵ�
Status StrEmpty(SString S);//�жϴ��Ƿ��
void StrPrint(SString T);//��ӡ��

#endif