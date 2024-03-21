#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SparseMatrix.h"
#include <windows.h>
#include <time.h>


int main()
{
	TSMatrix A, B, C;
	//CreateSMatrix test
	printf("��������A: ");
	CreateSMatrix(&A);
	//PrintSMatrix test
	printf("A����Ϊ:");
	PrintSMatrix(A);

	//TransposeSMatrix test
	printf("TransposeSMatrix����B(A��ת��): ");
	long op, ed;//���忪ʼʱ��ͽ���ʱ��
	op = clock();//��ʼ��ʱ
	for (int i = 0; i < 10000; i++)
	{
		TransposeSMatrix(A, &B);
	}
	Sleep(1000);//��̬���������Ƶ�ǰ�������е��߳�
	ed = clock();//������ʱ
	printf("����ʱ��Ϊ%ldms\n", ed - op);//����ʱ�� 
	PrintSMatrix(B);

	//FastTransposeSMatrix test
	printf("FastTransposeSMatrix test����C(A��ת��): ");

	op = clock();//��ʼ��ʱ
	for (int i = 0; i < 10000; i++)
	{
		FastTransposeSMatrix(A, &C);
	}
	Sleep(1000);//��̬���������Ƶ�ǰ�������е��߳�
	ed = clock();//������ʱ
	printf("����ʱ��Ϊ%ldms\n", ed - op);//����ʱ�� 

	PrintSMatrix(C);

	
	DestroySMatrix(&A);
	DestroySMatrix(&B);
	DestroySMatrix(&C);
	
	system("pause");
	return 0;
}