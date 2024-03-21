#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdlib.h>
#include "Status.h"

typedef int TElemType;
typedef struct 
{
	unsigned char ch;//叶子结点字符（根据应用需要添加此项）
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;//动态分配数组存储赫夫曼树

typedef char** HuffmanCode;//动态分配数组存储赫夫曼编码表

void Select(HuffmanTree HT, int n, int* s1, int* s2);
void HuffmanCoding(HuffmanTree* HT, HuffmanCode* HC, int* w, int n, char* str);
void Output_HuffmanCode(HuffmanCode HC, int n);
void Decoding(HuffmanTree HT, int m, char* buff);
void ShowHuffmanTree(HuffmanTree HT, int n);
void ShowHuffmanCode(HuffmanTree HT, HuffmanCode* HC, int n);




#endif