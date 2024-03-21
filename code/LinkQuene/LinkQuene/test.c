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
	printf("EnQueue�����Ϊ��");
	QueueTraverse(&Q, visit);

	//QueueLength test
	printf("���г���Ϊ��%d\n", QueueLength(Q));

	//GetHead test
	QElemType* e = 0;
	GetHead(Q, &e);
	printf("��ͷԪ��Ϊ��%d\n", e);

	//DeQueue test
	QElemType* f = 0;
	DeQueue(&Q, &f);
	printf("ɾ��Ԫ��Ϊ��%d\n", f);
	printf("DeQueue�����Ϊ��");
	QueueTraverse(&Q, visit);

	//ClearQueue test
	ClearQueue(&Q);
	printf("ClearQueue��\n");

	//QueueEmpty test
	if (QueueEmpty(Q))
		printf("����Ϊ��\n");
	else
		printf("���зǿ�\n");

	system("pause");
	return 0;
}