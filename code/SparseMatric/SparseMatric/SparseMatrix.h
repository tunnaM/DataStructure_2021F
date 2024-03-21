#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include<string.h>
#include<malloc.h> // malloc()等
#include<stdio.h> // EOF(=^Z或F6),NULL
#include<stdlib.h> // atoi()
#include<math.h> // floor(),ceil(),abs()

#define MAXSIZE 10000

//三元组类型
typedef int Status;
typedef int ElemType;
typedef struct
{
	int i;
	int j;//该非零元的行下标和列下标
	ElemType e;//该非零元的值
}Triple;

//稀疏矩阵类型
typedef struct
{
	Triple data[MAXSIZE + 1];//data[0]未用 非零元三元组表
	int mu, nu, tu;//矩阵行数mu，列数nu，非零元个数tu
}TSMatrix;

Status CreateSMatrix(TSMatrix* M);//创建稀疏矩阵M
Status DestroySMatrix(TSMatrix* M);//销毁稀疏矩阵M
Status PrintSMatrix(TSMatrix M);//输出稀疏矩阵M
Status CopySMatrix(TSMatrix M, TSMatrix* T);//由稀疏矩阵M复制得到T
int comp(int c1, int c2);
Status AddSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);//求稀疏矩阵的和Q=M+N
Status SubSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);//求稀疏矩阵的差Q=M-N
Status MultSMatrix(TSMatrix M, TSMatrix N, TSMatrix* Q);//求稀疏矩阵的乘积Q=M*N
Status TransposeSMatrix(TSMatrix M, TSMatrix* T);//求稀疏矩阵M的转置矩阵T
Status FastTransposeSMatrix(TSMatrix M, TSMatrix* T);

#endif