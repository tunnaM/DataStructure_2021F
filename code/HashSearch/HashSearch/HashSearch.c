#define _CRT_SECURE_NO_WARNINGS
#include "HashSearch.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

int m = 0;
int hashsize[] =
{ 11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997 };
//��ϣ������������һ�����ʵ���������

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
}//��ʼ����ϣ�� 

void DestroyHash(HashTable* H)
{
	free((*H).elem);
	(*H).elem = NULL;
	(*H).count = 0;
	(*H).sizeindex = 0;
}//���ٹ�ϣ�� 

unsigned Hash(KeyType K)
{
	return K % m;
}

void collision(int* p, int d)
{
	*p = (*p + d) % m;
}//�����ͻ���� 

Status SearchHash(HashTable H, KeyType K, int* p, int* c)
{
	//�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ�أ������ҳɹ�����pָʾ��������Ԫ���ڱ��е�λ�ã�
	//������pָʾ����λ�á�c���ԼƳ�ͻ�����������ֵ�㣬���������ʱ�ο�
	*p = Hash(K);//��ù�ϣ��ַ
	while (H.elem[*p].key != NULL && !(K == H.elem[*p].key))
	{
		(*c)++;
		if (*c < m)
			collision(p, *c);//�����һ̽���ַp
		else
			break;
	}
	if (K == H.elem[*p].key)
		return SUCCESS;//���ҳɹ������ش�������Ԫ��λ��p
	else
		return UNSUCCESS;//���Ҳ��ɹ�
}//SearchHash


Status InsertHash(HashTable* H, ElemType e)
{
	//���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�����ͻ�����������ؽ���ϣ��
	int c = 0;
	int p;
	if (SearchHash(*H, e.key, &p, &c))
		return DUPLICATE;//����������e�йؼ��ֵ�Ԫ��
	else if (c < hashsize[(*H).sizeindex] / 2)
	{
		//��ͻ����cδ�ﵽ���ޣ���ֵc�ɵ���
		(*H).elem[p] = e;
		++(*H).count;
		return OK;//����e
	}
	else
	{
		RecreateHashTable(H);//�ؽ���ϣ��
		return UNSUCCESS;
	}
}//InsertHash

void RecreateHashTable(HashTable* H) //�ؽ���ϣ��
{
	int i = (*H).count;
	int count = (*H).count;
	ElemType* p = (ElemType*)malloc(count * sizeof(ElemType));
	ElemType* elem = (ElemType*)malloc(count * sizeof(ElemType));
	p = elem;
	printf("�ؽ���ϣ��\n");
	for (i = 0; i < m; i++)
		if (((*H).elem + i)->key != NULLKEY)
			*p++ = *((*H).elem + i);
	(*H).count = 0;
	(*H).sizeindex++;//����洢����
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


void TraverseHash(HashTable H, void(*Vi)(int, ElemType)) //��������
{
	int i;
	printf("��ϣ��ַ0~%d\n", m - 1);
	for (i = 0; i < m; i++)
		if (H.elem[i].key != NULLKEY)
			Vi(i, H.elem[i]);
}//TraverseHash

int Find(HashTable H, KeyType K, int* p)
{
	int c = 0;
	*p = Hash(K);//��ù�ϣ��ַ
	while (H.elem[*p].key != NULLKEY && !(K == H.elem[*p].key))
	{ //��λ�������м�¼�����ҹؼ��ֲ����
		c++;
		if (c < m)
			collision(p, c);//�����һ̽���ַp
		else
			return UNSUCCESS; //���Ҳ��ɹ�(H.elem[p].key==NULLKEY)
	}
	if (K == H.elem[*p].key)
		return SUCCESS; //���ҳɹ���p���ش�������Ԫ��λ��
	else
		return UNSUCCESS; //���Ҳ��ɹ�(H.elem[p].key==NULLKEY)
}

void print(int p, ElemType r)//��ӡ����
{
	printf("%d %d\n", r.key, p);
}
