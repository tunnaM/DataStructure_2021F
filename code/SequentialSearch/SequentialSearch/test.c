#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "SequentialSearch.h"
#include <time.h>

int main()
{
	SSTable ST;
	CreateST(&ST);
	int search_num;

	clock_t tic, toc;
	int nn = 10000000;
	
	printf("������Ҫ���ҵ�����");
	scanf("%d", &search_num);
	
	/*
	printf("�޼�����test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq1(ST, search_num);
	}
	toc = clock();
    if (Search_Seq1(ST, search_num))
		printf("��������λ�ڵ�%dλ\n", Search_Seq1(ST, search_num));
	else
		printf("û�ҵ�����\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");

	printf("�м�����test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq2(ST, search_num);
	}
	toc = clock();
	if (Search_Seq2(ST, search_num))
		printf("��������λ�ڵ�%dλ\n", Search_Seq1(ST, search_num));
	else
		printf("û�ҵ�����\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");
	*/

	printf("�۰���ҷǵݹ�test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq1(ST, search_num);
	}
	toc = clock();
	if (Search_Bin1(ST, search_num))
		printf("��������λ�ڵ�%dλ\n", Search_Bin1(ST, search_num));
	else
		printf("û�ҵ�����\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");

	printf("�۰���ҵݹ�test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq1(ST, search_num);
	}
	toc = clock();
	if (Search_Bin2(ST, 1, ST.length-1, search_num))
		printf("��������λ�ڵ�%dλ\n", Search_Bin2(ST, 1, ST.length - 1, search_num));
	else
		printf("û�ҵ�����\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");


	system("pause");
	return 0;
}