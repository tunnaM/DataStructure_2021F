#include "Stringindex.h"
#include "Status.h"
#include <stdio.h>
#include <malloc.h>


int Index(SString S, SString T, int pos)
{
	//�����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,����ֵΪ0
	//����,T�ǿ�,1��pos��StrLength(S)
	int i, j;
	if (1 <= pos && pos <= S[0])
	{
		i = pos;
		j = 1;
		while (i <= S[0] && j <= T[0])
			if (S[i] == T[j]) //�����ȽϺ���ַ�
			{
				++i;
				++j;
			}
			else //ָ��������¿�ʼƥ��
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
	//�����㷨ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1<=pos<=StrLength(S)
	int next[255] = { "0"};
	int i = pos;
	int j = 1;//j�����Ӵ�T�е�ǰλ���±�ֵ
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
	//����һ����ֵ����chars�Ĵ�T
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
	//����ַ���T
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}

