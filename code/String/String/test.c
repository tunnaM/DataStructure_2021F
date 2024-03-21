#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "String.h"

int main()
{
	int i, j, * p;
	SString S1, S2, T;
	//StrAssign & StrPrint test
	StrAssign(S1, "acabaabaabcacaabc\0");
	printf("S1串为: ");
	StrPrint(S1);
	StrAssign(S2, "abaabcac\0");
	printf("S2串为: ");
	StrPrint(S2);
	//SubString test
	SString Sub;
	SubString(&Sub, S1, 3, 5);
	printf("串S1的第3个字符起长度为5的子串为:");
	StrPrint(Sub);
	//StrCopy test
	SString A;
	StrCopy(&A, S2);//把串S的内容拷贝到串T
	printf("拷贝S2后A串为：");
	StrPrint(A);
	//Index test
	int pos = 1;
	printf("子串S2在主串S1中第%d个字符之后的位置\n", Index(S1, S2, pos));
	//StrLength test
	printf("子串S2长度为：%d\n", StrLength(S2));
	//Replace test(含StrDelete & StrInsert)
	SString V;
	StrAssign(T, "cac");
	StrAssign(V, "ded");
	Replace(&S1, T, V);
	printf("替换后S1串为:");
	StrPrint(S1);
	//StrCompare test
	if (StrCompare(S1, S2) > 0)
		printf("S1更长\n");
	else if (StrCompare(S1, S2) == 0)
		printf("S1S2一样长\n");
	else
		printf("S2更长\n");
	//Concat test
	Concat(&T, S1, S2);
	printf("concat后T串为: ");
	StrPrint(T);

	system("pause");
	return 0;
}

