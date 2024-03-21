#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdlib.h>
#include "Status.h"

typedef int TElemType;
typedef struct 
{
	unsigned char ch;//Ҷ�ӽ���ַ�������Ӧ����Ҫ��Ӵ��
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;//��̬��������洢�շ�����

typedef char** HuffmanCode;//��̬��������洢�շ��������

void Select(HuffmanTree HT, int n, int* s1, int* s2);
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n, char* str);
void Output_HuffmanCode(HuffmanCode HC, int n);
void Decoding(HuffmanTree HT, int m, char* buff);
void ShowHuffmanTree(HuffmanTree HT, int n);
void ShowHuffmanCode(HuffmanTree HT, HuffmanCode* HC, int n);




#endif