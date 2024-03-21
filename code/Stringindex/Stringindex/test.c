#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stringindex.h"
#include <windows.h>
#include <time.h>

int main()
{
	int i, j, * p;
	SString S1, S2, T;
	StrAssign(S1, "acabaabaabcacaabc\0");
	printf("S1串为: ");
	StrPrint(S1);
	StrAssign(S2, "abaabcac\0");
	printf("S2串为: ");
	StrPrint(S2);

	int pos = 1;
	//Index test
	long op, ed;//定义开始时间和结束时间
	op = clock();//开始计时
	for (int i = 0; i < 10000; i++)
	{
		Index(S1, S2, pos);
	}
	Sleep(1000);//静态方法，控制当前正在运行的线程
	ed = clock();//结束计时
	printf("运行时间为%ldms\n", ed - op);//运行时间 

	printf("子串S2在主串S1中第%d个字符之后的位置\n", Index(S1, S2, pos));


	pos = 1;
	//Index_KMP test
	op = clock();//开始计时
	for (int i = 0; i < 10000; i++)
	{
		Index_KMP(S1, S2, pos);
	}
	Sleep(1000);//静态方法，控制当前正在运行的线程
	ed = clock();//结束计时
	printf("KMP运行时间为%ldms\n", ed - op);//运行时间 
	printf("子串S2在主串S1中第%d个字符之后的位置\n", Index_KMP(S1, S2, pos));




	system("pause");
	return 0;
}

