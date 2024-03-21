#include <stdio.h>
#include "CircleQueue.h"
int main()
{
	SqQueue Q;
	//InitQueue test
	if (InitQueue(&Q))
		printf("InitQueue success!\n");
	else
		printf("InitQueue unsuccess!\n");
	//EnQueue test & DeQueue test
	for (int i = 1; i <= 100; i++)
	{
		EnQueue(&Q, 100 + i);
  	}
	QElemType* x = 0;
	DeQueue(&Q, &x);
	if(x==101)
		printf("EnQueue & DeQueue success\n");
	else
		printf("EnQueue & DeQueue unsuccess\n");

	system("pause");
	return 0;
}