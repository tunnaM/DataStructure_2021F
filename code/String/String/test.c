#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "String.h"

int main()
{
	int i, j, * p;
	SString S1, S2, T;
	//StrAssign & StrPrint test
	StrAssign(S1, "acabaabaabcacaabc\0");
	printf("S1��Ϊ: ");
	StrPrint(S1);
	StrAssign(S2, "abaabcac\0");
	printf("S2��Ϊ: ");
	StrPrint(S2);
	//SubString test
	SString Sub;
	SubString(&Sub, S1, 3, 5);
	printf("��S1�ĵ�3���ַ��𳤶�Ϊ5���Ӵ�Ϊ:");
	StrPrint(Sub);
	//StrCopy test
	SString A;
	StrCopy(&A, S2);//�Ѵ�S�����ݿ�������T
	printf("����S2��A��Ϊ��");
	StrPrint(A);
	//Index test
	int pos = 1;
	printf("�Ӵ�S2������S1�е�%d���ַ�֮���λ��\n", Index(S1, S2, pos));
	//StrLength test
	printf("�Ӵ�S2����Ϊ��%d\n", StrLength(S2));
	//Replace test(��StrDelete & StrInsert)
	SString V;
	StrAssign(T, "cac");
	StrAssign(V, "ded");
	Replace(&S1, T, V);
	printf("�滻��S1��Ϊ:");
	StrPrint(S1);
	//StrCompare test
	if (StrCompare(S1, S2) > 0)
		printf("S1����\n");
	else if (StrCompare(S1, S2) == 0)
		printf("S1S2һ����\n");
	else
		printf("S2����\n");
	//Concat test
	Concat(&T, S1, S2);
	printf("concat��T��Ϊ: ");
	StrPrint(T);

	system("pause");
	return 0;
}

