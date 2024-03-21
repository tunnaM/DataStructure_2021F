#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Huffmantree.h"

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n = 8;
    int a[8] = { 5,29,7,8,14,23,3,11 };//8个字符的权值
    char str[8] = "abcdefgh";
    //char str[30] = "a   b   c   d   e   f   g   h";

    HuffmanCoding(&HT, &HC, a, n, str);
    Output_HuffmanCode(HC, n);

    printf("打印哈夫曼树：\n");
    ShowHuffmanTree(HT, 2 * n - 1);
    printf("\n打印叶子结点的哈夫曼编码：\n");
    ShowHuffmanCode(HT, HC, n);

    printf("请输入一串哈夫曼编码：\n");
    char buff[50];
    scanf("%s", buff);
    printf("解码为：\n");
    Decoding(HT, 2 * n - 1, buff);
    printf("\n");
    
	system("pause");
	return 0;
}

