#ifndef HASHSEARCH_H
#define HASHSEARCH_H

#include <stdlib.h>
#include "Status.h"

#define N 10

typedef int KeyType;
typedef struct{
	KeyType key;
}ElemType;
typedef struct{
	ElemType* elem;//����Ԫ�ش洢��ַ����̬��������
	int count;//��ǰ����Ԫ�ظ���
	int sizeindex;//hashsize[sizeindex]Ϊ��ǰ����
}HashTable;

Status InitHash(HashTable* H);
void DestroyHash(HashTable* H);
void collision(int* p, int d);
Status SearchHash(HashTable H, KeyType K, int* p, int* c);
Status InsertHash(HashTable* H, ElemType e);
void RecreateHashTable(HashTable* H);
void TraverseHash(HashTable H, void(*Vi)(int, ElemType));
void print(int p, ElemType r);







#endif