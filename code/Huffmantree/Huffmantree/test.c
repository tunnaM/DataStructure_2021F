#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Huffmantree.h"

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n = 8;
    int a[8] = { 5,29,7,8,14,23,3,11 };//8���ַ���Ȩֵ
    char str[8] = "abcdefgh";
    //char str[30] = "a   b   c   d   e   f   g   h";

    HuffmanCoding(&HT, &HC, a, n, str);
    Output_HuffmanCode(HC, n);

    printf("��ӡ����������\n");
    ShowHuffmanTree(HT, 2 * n - 1);
    printf("\n��ӡҶ�ӽ��Ĺ��������룺\n");
    ShowHuffmanCode(HT, HC, n);

    printf("������һ�����������룺\n");
    char buff[50];
    scanf("%s", buff);
    printf("����Ϊ��\n");
    Decoding(HT, 2 * n - 1, buff);
    printf("\n");
    
	system("pause");
	return 0;
}

