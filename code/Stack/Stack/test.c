#include <stdio.h>
#include "Stack.h"


int main()
{

	SqStack S;
	//InitStack test
	if (InitStack(&S))
		printf("InitStack sucess!\n");
	else
		printf("InitStack unsucess!\n");

	//DestroyStack test
	if (DestroyStack(&S))
		printf("DestroyStack sucess!\n");
	else
		printf("DestroyStack unsucess!\n");

	//ClearStack test
	if (ClearStack(&S))
		printf("ClearStack sucess!\n");
	else
		printf("ClearStack unsucess!\n");

	//Push test
	InitStack(&S);
	for (int i = 1; i <= 5; i++)
	{
		Push(&S, 100 + i);
	}
	printf("push��ջΪ��");
	StackTravers(&S);
	printf("push��ջ����Ϊ:%d\n", StackLength(S));

	//Pop test
	SElemType* a = 0;
	Pop(&S, &a);
	printf("������ջ��Ԫ��Ϊ:%d\n", a);
	printf("pop��ջΪ��");
	StackTravers(&S);
	printf("push��ջ����Ϊ:%d\n", StackLength(S));

	//GetTop test
	GetTop(S, &a);
	printf("����ջ��Ԫ��Ϊ:%d\n", a);
	printf("gettop��ջΪ��");
	StackTravers(&S);
	printf("push��ջ����Ϊ:%d\n", StackLength(S));

	return 0;
}
