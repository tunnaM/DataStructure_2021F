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
	ElemType* elem;//数据元素存储基址，动态分配数组
	int count;//当前数据元素个数
	int sizeindex;//hashsize[sizeindex]为当前容量
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