#ifndef SEQUENTIALSEARCH_H
#define SEQUENTIALSEARCH_H

#include <stdlib.h>
#include "Status.h"

#define MAX_SIZE 20

typedef int KeyType;
typedef struct {
	KeyType key;
	char name;
}ElemType;

typedef struct
{
	ElemType* elem;//����Ԫ�ؿռ��ַ
	int length;//��ĳ���
}SSTable;

Status CreateST(SSTable* ST);
int Search_Seq1(SSTable ST, KeyType key);//�޼�����
int Search_Seq2(SSTable ST, KeyType key);//�м�����



#endif