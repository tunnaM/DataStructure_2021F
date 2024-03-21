#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "AdjacencyMatrix.h"

int main()
{
	//InitList test
	MGraph G;
	if (CreateUDN(&G))
		printf("CreateUDN sucess!\n");
	else
		printf("CreateUDN unsucess!\n");
	system("pause");
	return 0;
}
