#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "TopologicalSort.h"

int main()
{
	ALGraph G;
	CreateUDG(&G);
	printf("����������Ϊ��\n");
	TopologicalSort(G);

	system("pause");
	return 0;
}