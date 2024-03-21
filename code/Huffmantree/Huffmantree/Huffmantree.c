#include "Huffmantree.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>

void Select(HuffmanTree HT, int n, int* s1, int* s2)
{
	//�Һշ�����HT��1~n��parentΪ0����С������Ȩֵ���±꣨HT���±��1��ʼ��
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
			//i!=s1�����ų�s1��������ҳ���Сֵ��ĵڶ�����Сֵ
			min2 = HT[i].weight;
			*s2 = i;
		}//if
	}//for
}

void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n, char* str)
{
	//w���n���ַ�Ȩֵ������շ�����HT�����n���ַ��ı���HC
	if (n <= 1)
		return;
	int m = 2 * n - 1;//���н�����
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	int i;
	for (i = 1; i <= n; i++)
	{
		//��ʼҶ�ӣ���1�Ŵ洢
		(*HT)[i].weight = w[i - 1];
		(*HT)[i].parent = (*HT)[i].lchild = (*HT)[i].rchild = 0;
		(*HT)[i].ch = str[i - 1];
	}//for
	for (; i <= m; i++)
	{
		//��ʼ����Ҷ�ӣ�m=2*n-1
		(*HT)[i].ch = '\0';
		(*HT)[i].parent = (*HT)[i].lchild = (*HT)[i].rchild = 0;
	}//for
	//���˺շ�������ɳ�ʼ��
	int s1, s2;
	for (i = n + 1; i <= m; i++)
	{
		//����շ�����
		//��HT[1..i-1]��ѡ��parentΪ0��weight��С��������㣬����ż�Ϊs1��s2
		Select((*HT), i - 1, &s1, &s2);
		//���ɴ洢�ڵ�i��λ�õ��½��
		(*HT)[s1].parent = i;
		(*HT)[s2].parent = i;
		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}//for
	
	//��Ҷ�ӽ�㵽��������ÿ���ַ��ĺն�������
	*HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
	//����n���ַ������ͷָ������
	char* cd;
	cd = (char*)malloc(n * sizeof(char));
	//���������Ĺ����ռ�
	cd[n - 1] = '\0';//���������
	int c, f, start;
	for (i = 1; i <= n; i++)
	{
		//����ַ�����
		start = n - 1;//���뵱ǰ����0/1��λ��
		//��Ҷ�ӵ������������
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

void Output_HuffmanCode(HuffmanCode HC, int n)//HC�±��1��ʼ
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
	//�������Ʊ���buff�������Ϣԭ�ģ�m�������ı��
	int p = m;
	while (*buff != '\0' && p != 0) 
	{
		if ((*buff) == '0')
			p = HT[p].lchild; //�������֧
		else
			p = HT[p].rchild; //�����ҷ�֧
		buff++;
		if (!HT[p].lchild && !HT[p].rchild) 
		{
			//����Ҷ�ӽ��
			printf("%c", HT[p].ch);
			p = m; //���´�����������������
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