#include "Huffmantree.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

void Select(HuffmanTree HT, int n, int* s1, int* s2)
{
	//找赫夫曼树HT中1~n的parent为0的最小的两个权值的下标（HT的下标从1开始）
	int min1 = 1000, min2 = 1000;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && HT[i].weight < min1)
		{
			min1 = HT[i].weight;
			*s1 = i;
		}//if
	}//for
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].parent == 0 && i != *s1 && HT[i].weight < min2)
		{
			//i!=s1用来排除s1的情况，找除最小值外的第二个最小值
			min2 = HT[i].weight;
			*s2 = i;
		}//if
	}//for
}

void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n, char* str)
{
	//w存放n个字符权值，构造赫夫曼树HT，求出n个字符的编码HC
	if (n <= 1)
		return;
	int m = 2 * n - 1;//树中结点个数
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	int i;
	for (i = 1; i <= n; i++)
	{
		//初始叶子，从1号存储
		(*HT)[i].weight = w[i - 1];
		(*HT)[i].parent = (*HT)[i].lchild = (*HT)[i].rchild = 0;
		(*HT)[i].ch = str[i - 1];
	}//for
	for (; i <= m; i++)
	{
		//初始化非叶子，m=2*n-1
		(*HT)[i].ch = '\0';
		(*HT)[i].parent = (*HT)[i].lchild = (*HT)[i].rchild = 0;
	}//for
	//至此赫夫曼树完成初始化
	int s1, s2;
	for (i = n + 1; i <= m; i++)
	{
		//构造赫夫曼树
		//从HT[1..i-1]中选择parent为0且weight最小的两个结点，其序号记为s1和s2
		Select((*HT), i - 1, &s1, &s2);
		//生成存储在第i个位置的新结点
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}//for
	
	//从叶子结点到根逆向求每个字符的赫尔曼编码
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	//分配n个字符编码的头指针向量
	char* cd;
	cd = (char*)malloc(n * sizeof(char));
	//分配求编码的工作空间
	cd[n - 1] = '\0';//编码结束符
	int c, f, start;
	for (i = 1; i <= n; i++)
	{
		//逐个字符编码
		start = n - 1;//编码当前编制0/1的位置
		//从叶子到根逆向求编码
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)
			if ((*HT)[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy((*HC)[i], &cd[start]);
	}//for
	free(cd);
}

void Output_HuffmanCode(HuffmanCode HC, int n)//HC下标从1开始
{
	printf("----\n");
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 0; HC[i][j] != '\0'; j++)
			printf("%d", HC[i][j]-48);
		printf("\n");
	}
	printf("----\n");
}

void Decoding(HuffmanTree HT, int m, char* buff)
{
	//将二进制编码buff翻译回信息原文，m是树根的编号
	int p = m;
	while (*buff != '\0' && p != 0) 
	{
		if ((*buff) == '0')
			p = HT[p].lchild; //进入左分支
		else
			p = HT[p].rchild; //进入右分支
		buff++;
		if (!HT[p].lchild && !HT[p].rchild) 
		{
			//进入叶子结点
			printf("%c", HT[p].ch);
			p = m; //重新从树根出发进行译码
		}//if
	}//while
}

void ShowHuffmanTree(HuffmanTree HT, int n)
{
	int i;
	printf("   ch    order   weight  parent  lchild  rchild \n");
	for (i = 1; i <= n; i++)
		printf("   %c       %2d      %3d     %2d      %2d      %2d   \n",
			HT[i].ch, i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	printf("\n");

}

void ShowHuffmanCode(HuffmanTree HT, HuffmanCode* HC, int n)
{
	int i;
	printf("   ch    order   weight           Code  \n");
	for (i = 1; i <= n; i++)
		printf("   %c       %2d      %2d     ---->  %-8s\n",
			HT[i].ch, i, HT[i].weight, HC[i]);
	printf("\n");
}