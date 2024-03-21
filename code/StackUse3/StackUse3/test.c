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
	//算术表达式求值的算符优先算法，设OPTR和OPND分别为运算符栈和操作数栈。如输入4+2*3-9/3#
	SqStack_OPTR OPTR;//寄存运算符
	SqStack_OPND OPND;//寄存操作符

	SElemType1 e = 0;//接收GetTop和Pop
	SElemType1 f = 0;
	SElemType1 x = 0;//接收退栈后的值
	SElemType1 theta = 0;//在Precede函数判出>后,存放OPTR出栈的运算符
	SElemType2 a = 0;//操作符左值
	SElemType2 b = 0;//操作符右值
	SElemType2 d = 0;

	InitStack_OPTR(&OPTR);//OPTR元素类型char
	Push_OPTR(&OPTR, '#');
	InitStack_OPND(&OPND);//OPND元素类型float
	char c = getchar();

	GetTop_OPTR(OPTR, &e);
	while (c != '#' ||e != '#')
	{
		if (!In(c,OP))//不是运算符则进栈
		{
			Push_OPND(&OPND, c-48);
			c = getchar();
		}
		else
		{
			GetTop_OPTR(OPTR, &f);
			switch (Precede(f, c))//优先级比较
			{
			case '<'://栈顶元素优先级低
				Push_OPTR(&OPTR, c);
				c = getchar();
				break;
			case '='://脱括号并接收下一字符
				Pop_OPTR(&OPTR, &x);
				c = getchar();
				break;
			case '>':
				Pop_OPTR(&OPTR, &theta);
				Pop_OPND(&OPND, &b);
				Pop_OPND(&OPND, &a);
				Push_OPND(&OPND, Operate(a, theta, b));
				break;
			}//switch语句结束
		}
 		GetTop_OPTR(OPTR, &e);
	}//while语句结束
	GetTop_OPND(OPND, &d);
	return d;
}

int main()
{
	printf("输入表达式,得出运算结果,输入以#结束\n");
	printf("表达式结果为:%d\n", EvaluateExpression());
	return 0;
}
