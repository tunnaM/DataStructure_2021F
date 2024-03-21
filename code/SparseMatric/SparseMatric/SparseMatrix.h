#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<string.h>
#include<malloc.h> // malloc()��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
#include<math.h> // floor(),ceil(),abs()

#define MAXSIZE 10000

//��Ԫ������
typedef int Status;
typedef int ElemType;
typedef struct
{
	int i;
	int j;//�÷���Ԫ�����±�����±�
	ElemType e;//�÷���Ԫ��ֵ
}Triple;

//ϡ���������
typedef struct
{
	Triple data[MAXSIZE + 1];//data[0]δ�� ����Ԫ��Ԫ���
	int mu, nu, tu;//��������mu������nu������Ԫ����tu
}TSMatrix;

Status CreateSMatrix(TSMatrix* M);//����ϡ�����M
Status DestroySMatrix(TSMatrix* M);//����ϡ�����M
Status PrintSMatrix(TSMatrix M);//���ϡ�����M
Status CopySMatrix(TSMatrix M, TSMatrix* T);//��ϡ�����M���Ƶõ�T
int comp(int c1, int c2);
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);//��ϡ�����ĺ�Q=M+N
Status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);//��ϡ�����Ĳ�Q=M-N
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);//��ϡ�����ĳ˻�Q=M*N
Status TransposeSMatrix(TSMatrix M, TSMatrix* T);//��ϡ�����M��ת�þ���T
Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T);

#endif