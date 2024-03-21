#include <stdio.h>
#include "Stack.h"

char OP[7] = { '+','-','*','/','(',')','#' };
char SymbolPriority[8][8] =
{ ' ','+','-','*','/','(',')','#',
  '+','>','>','<','<','<','>','>',
  '-','>','>','<','<','<','>','>',
  '*','>','>','>','>','<','>','>',
  '/','>','>','>','>','<','>','>',
  '(','<','<','<','<','<','=',' ',
  ')','>','>','>','>',' ','>','>',
  '#','<','<','<','<','<',' ','='
};

Status In(char e, char OP[])
{
	int flag = 0;
	for (int i = 0; i < 7; i++)
	{
		if (e == OP[i])flag = 1;
	}
	if (flag)return 1;
	else return 0;
}

Status Precede(char m, char n)
{
	int mdata = 0;
	int ndata = 0;
	switch (m) 
	{
	case '+':
		mdata = 1;
		break;
	case '-':
		mdata = 2;
		break;
	case '*':
		mdata = 3;
		break;
	case '/':
		mdata = 4;
		break;
	case '(':
		mdata = 5;
		break;
	case ')':
		mdata = 6;
		break;
	case '#':
		mdata = 7;
		break;
	}
	switch (n) 
	{
	case '+':
		ndata = 1;
		break;
	case '-':
		ndata = 2;
		break;
	case '*':
		ndata = 3;
		break;
	case '/':
		ndata = 4;
		break;
	case '(':
		ndata = 5;
		break;
	case ')':
		ndata = 6;
		break;
	case '#':
		ndata = 7;
		break;
	}
	return SymbolPriority[mdata][ndata];
}

Status Operate(SElemType2 a, char theta, SElemType2 b)
{
	SElemType2 result = 0;
	switch (theta) 
	{
	case '+':
		result = a + b;
		break; 
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}
	return result;
}


Status EvaluateExpression();
Status EvaluateExpression()
{
	//�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ�Ͳ�����ջ��������4+2*3-9/3#
	SqStack_OPTR OPTR;//�Ĵ������
	SqStack_OPND OPND;//�Ĵ������

	SElemType1 e = 0;//����GetTop��Pop
	SElemType1 f = 0;
	SElemType1 x = 0;//������ջ���ֵ
	SElemType1 theta = 0;//��Precede�����г�>��,���OPTR��ջ�������
	SElemType2 a = 0;//��������ֵ
	SElemType2 b = 0;//��������ֵ
	SElemType2 d = 0;

	InitStack_OPTR(&OPTR);//OPTRԪ������char
	Push_OPTR(&OPTR, '#');
	InitStack_OPND(&OPND);//OPNDԪ������float
	char c = getchar();

	GetTop_OPTR(OPTR, &e);
	while (c != '#' ||e != '#')
	{
		if (!In(c,OP))//������������ջ
		{
			Push_OPND(&OPND, c-48);
			c = getchar();
		}
		else
		{
			GetTop_OPTR(OPTR, &f);
			switch (Precede(f, c))//���ȼ��Ƚ�
			{
			case '<'://ջ��Ԫ�����ȼ���
				Push_OPTR(&OPTR, c);
				c = getchar();
				break;
			case '='://�����Ų�������һ�ַ�
				Pop_OPTR(&OPTR, &x);
				c = getchar();
				break;
			case '>':
				Pop_OPTR(&OPTR, &theta);
				Pop_OPND(&OPND, &b);
				Pop_OPND(&OPND, &a);
				Push_OPND(&OPND, Operate(a, theta, b));
				break;
			}//switch������
		}
 		GetTop_OPTR(OPTR, &e);
	}//while������
	GetTop_OPND(OPND, &d);
	return d;
}

int main()
{
	printf("������ʽ,�ó�������,������#����\n");
	printf("���ʽ���Ϊ:%d\n", EvaluateExpression());
	return 0;
}
