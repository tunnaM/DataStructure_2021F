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
	ElemType* elem;//数据元素空间基址
	int length;//表的长度
}SSTable;

Status CreateST(SSTable* ST);
int Search_Seq1(SSTable ST, KeyType key);//无监视哨
int Search_Seq2(SSTable ST, KeyType key);//有监视哨



#endif