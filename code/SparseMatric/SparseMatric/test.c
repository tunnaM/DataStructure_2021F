#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SparseMatrix.h"
#include <windows.h>
#include <time.h>


int main()
{
	TSMatrix A, B, C;
	//CreateSMatrix test
	printf("创建矩阵A: ");
	CreateSMatrix(&A);
	//PrintSMatrix test
	printf("A矩阵为:");
	PrintSMatrix(A);

	//TransposeSMatrix test
	printf("TransposeSMatrix矩阵B(A的转置): ");
	long op, ed;//定义开始时间和结束时间
	op = clock();//开始计时
	for (int i = 0; i < 10000; i++)
	{
		TransposeSMatrix(A, &B);
	}
	Sleep(1000);//静态方法，控制当前正在运行的线程
	ed = clock();//结束计时
	printf("运行时间为%ldms\n", ed - op);//运行时间 
	PrintSMatrix(B);

	//FastTransposeSMatrix test
	printf("FastTransposeSMatrix test矩阵C(A的转置): ");

	op = clock();//开始计时
	for (int i = 0; i < 10000; i++)
	{
		FastTransposeSMatrix(A, &C);
	}
	Sleep(1000);//静态方法，控制当前正在运行的线程
	ed = clock();//结束计时
	printf("运行时间为%ldms\n", ed - op);//运行时间 

	PrintSMatrix(C);

	
	DestroySMatrix(&A);
	DestroySMatrix(&B);
	DestroySMatrix(&C);
	
	system("pause");
	return 0;
}