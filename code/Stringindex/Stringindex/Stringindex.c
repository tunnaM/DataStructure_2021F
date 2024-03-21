#include "Stringindex.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>


int Index(SString S, SString T, int pos)
{
	//返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数值为0
	//其中,T非空,1≤pos≤StrLength(S)
	int i, j;
	if (1 <= pos && pos <= S[0])
	{
		i = pos;
		j = 1;
		while (i <= S[0] && j <= T[0])
			if (S[i] == T[j]) //继续比较后继字符
			{
				++i;
				++j;
			}
			else //指针后退重新开始匹配
			{
				i = i - j + 2;
				j = 1;
			}
		if (j > T[0])
			return i - T[0];
		else
			return 0;
	}
	else
		return 0;
}

void get_next(SString T, int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int Index_KMP(SString S, SString T, int pos)
{
	//利用算法模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1<=pos<=StrLength(S)
	int next[255] = { "0"};
	int i = pos;
	int j = 1;//j用于子串T中当前位置下标值
	get_next(T, next);
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

Status StrAssign(SString T, char* chars)
{
	//生成一个其值等于chars的串T
	int i = 0;
	if (strlen(chars) > MAXSTRLEN)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

void StrPrint(SString T)
{
	//输出字符串T
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

