#include <stdio.h>
#include "LinkQueue.h"

int main()
{
	LinkQueue Q;
	//InitQueue test
	if (InitQueue(&Q))
		printf("InitQueue success!\n");
	else
		printf("InitQueue unsuccess!\n");

	//DestroyQueue test
	if (DestroyQueue(&Q))
		printf("DestroyQueue sucess!\n");
	else
		printf("DestroyQueue unsucess!\n");

	//EnQueue test
	InitQueue(&Q);
	for (int i = 1; i <= 5; i++)
	{
		EnQueue(&Q, 100 + i);
	}
	printf("EnQueue后队列为：");
	QueueTraverse(&Q, visit);

	//QueueLength test
	printf("队列长度为：%d\n", QueueLength(Q));

	//GetHead test
	QElemType* e = 0;
	GetHead(Q, &e);
	printf("队头元素为：%d\n", e);

	//DeQueue test
	QElemType* f = 0;
	DeQueue(&Q, &f);
	printf("删除元素为：%d\n", f);
	printf("DeQueue后队列为：");
	QueueTraverse(&Q, visit);

	//ClearQueue test
	ClearQueue(&Q);
	printf("ClearQueue后\n");

	//QueueEmpty test
	if (QueueEmpty(Q))
		printf("队列为空\n");
	else
		printf("队列非空\n");

	system("pause");
	return 0;
}