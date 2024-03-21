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
	
	printf("请输入要查找的数：");
	scanf("%d", &search_num);
	
	/*
	printf("无监视哨test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq1(ST, search_num);
	}
	toc = clock();
    if (Search_Seq1(ST, search_num))
		printf("所查找数位于第%d位\n", Search_Seq1(ST, search_num));
	else
		printf("没找到该数\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");

	printf("有监视哨test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq2(ST, search_num);
	}
	toc = clock();
	if (Search_Seq2(ST, search_num))
		printf("所查找数位于第%d位\n", Search_Seq1(ST, search_num));
	else
		printf("没找到该数\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");
	*/

	printf("折半查找非递归test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq1(ST, search_num);
	}
	toc = clock();
	if (Search_Bin1(ST, search_num))
		printf("所查找数位于第%d位\n", Search_Bin1(ST, search_num));
	else
		printf("没找到该数\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");

	printf("折半查找递归test\n");
	tic = clock();
	for (int i = 1; i <= nn; i++)
	{
		Search_Seq1(ST, search_num);
	}
	toc = clock();
	if (Search_Bin2(ST, 1, ST.length-1, search_num))
		printf("所查找数位于第%d位\n", Search_Bin2(ST, 1, ST.length - 1, search_num));
	else
		printf("没找到该数\n");
	printf("elapsed time is %fs\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\n");


	system("pause");
	return 0;
}