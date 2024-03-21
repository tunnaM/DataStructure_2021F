#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "TopologicalSort.h"

int main()
{
	ALGraph G;
	CreateUDG(&G);
	printf("ÍØÆËÅÅÐò½á¹ûÎª£º\n");
	TopologicalSort(G);

	system("pause");
	return 0;
}