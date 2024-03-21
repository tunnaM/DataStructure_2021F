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
	printf("push后栈为：");
	StackTravers(&S);
	printf("push后栈长度为:%d\n", StackLength(S));

	//Pop test
	SElemType* a = 0;
	Pop(&S, &a);
	printf("弹出的栈顶元素为:%d\n", a);
	printf("pop后栈为：");
	StackTravers(&S);
	printf("push后栈长度为:%d\n", StackLength(S));

	//GetTop test
	GetTop(S, &a);
	printf("现在栈顶元素为:%d\n", a);
	printf("gettop后栈为：");
	StackTravers(&S);
	printf("push后栈长度为:%d\n", StackLength(S));

	return 0;
}
