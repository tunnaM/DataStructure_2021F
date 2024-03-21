#define _CRT_SECURE_NO_WARNINGS
#include "HashSearch.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

int m = 0;
int hashsize[] =
{ 11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997 };
//哈希表容量递增表，一个合适的素数序列

Status InitHash(HashTable* H)
{
	(*H).count = 0;
	(*H).sizeindex = 0;
	m = hashsize[0];
	(*H).elem = (ElemType*)malloc(m * sizeof(ElemType));
	if (!(*H).elem)
		return OVERFLOW;
	for (int i = 0; i < m; i++)
	{
		(*H).elem[i].key = NULLKEY;
	}
	return OK;
}//初始化哈希表 

void DestroyHash(HashTable* H)
{
	free((*H).elem);
	(*H).elem = NULL;
	(*H).count = 0;
	(*H).sizeindex = 0;
}//销毁哈希表 

unsigned Hash(KeyType K)
{
	return K % m;
}

void collision(int* p, int d)
{
	*p = (*p + d) % m;
}//处理冲突函数 

Status SearchHash(HashTable H, KeyType K, int* p, int* c)
{
	//在开放定址哈希表H中查找关键码为K的元素，若查找成功，以p指示待查数据元素在表中的位置；
	//否则，以p指示插入位置。c用以计冲突次数，其初置值零，供建表插入时参考
	*p = Hash(K);//求得哈希地址
	while (H.elem[*p].key != NULL && !(K == H.elem[*p].key))
	{
		(*c)++;
		if (*c < m)
			collision(p, *c);//求得下一探查地址p
		else
			break;
	}
	if (K == H.elem[*p].key)
		return SUCCESS;//查找成功，返回待查数据元素位置p
	else
		return UNSUCCESS;//查找不成功
}//SearchHash


Status InsertHash(HashTable* H, ElemType e)
{
	//查找不成功时插入数据元素e到开放定址哈希表H中；若冲突次数过大，则重建哈希表
	int c = 0;
	int p;
	if (SearchHash(*H, e.key, &p, &c))
		return DUPLICATE;//表中已有与e有关键字的元素
	else if (c < hashsize[(*H).sizeindex] / 2)
	{
		//冲突次数c未达到上限（阈值c可调）
		(*H).elem[p] = e;
		++(*H).count;
		return OK;//插入e
	}
	else
	{
		RecreateHashTable(H);//重建哈希表
		return UNSUCCESS;
	}
}//InsertHash

void RecreateHashTable(HashTable* H) //重建哈希表
{
	int i = (*H).count;
	int count = (*H).count;
	ElemType* p = (ElemType*)malloc(count * sizeof(ElemType));
	ElemType* elem = (ElemType*)malloc(count * sizeof(ElemType));
	p = elem;
	printf("重建哈希表\n");
	for (i = 0; i < m; i++)
		if (((*H).elem + i)->key != NULLKEY)
			*p++ = *((*H).elem + i);
	(*H).count = 0;
	(*H).sizeindex++;//增大存储容量
	m = hashsize[(*H).sizeindex];
	p = (ElemType*)realloc((*H).elem, m * sizeof(ElemType));
	if (!p)
		exit(0);
	(*H).elem = p;
	for (i = 0; i < m; i++)
		(*H).elem[i].key = NULLKEY;
	for (p = elem; p < elem + count; p++)
		InsertHash(H, *p);
}//RecreateHashTable


void TraverseHash(HashTable H, void(*Vi)(int, ElemType)) //遍历函数
{
	int i;
	printf("哈希地址0~%d\n", m - 1);
	for (i = 0; i < m; i++)
		if (H.elem[i].key != NULLKEY)
			Vi(i, H.elem[i]);
}//TraverseHash

int Find(HashTable H, KeyType K, int* p)
{
	int c = 0;
	*p = Hash(K);//求得哈希地址
	while (H.elem[*p].key != NULLKEY && !(K == H.elem[*p].key))
	{ //该位置中填有记录．并且关键字不相等
		c++;
		if (c < m)
			collision(p, c);//求得下一探查地址p
		else
			return UNSUCCESS; //查找不成功(H.elem[p].key==NULLKEY)
	}
	if (K == H.elem[*p].key)
		return SUCCESS; //查找成功，p返回待查数据元素位置
	else
		return UNSUCCESS; //查找不成功(H.elem[p].key==NULLKEY)
}

void print(int p, ElemType r)//打印函数
{
	printf("%d %d\n", r.key, p);
}
