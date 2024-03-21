#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "AdjacencyList.h"

int main()
{
	//InitList test
	ALGraph G;
	if (CreateUDG(&G))
		printf("CreateUDG sucess!\n");
	else
		printf("CreateUDG unsucess!\n");
	
	//DFSTraverse test
	DFSTraverse(G);
	printf("\n");

	//BFSTraverse test
	BFSTraverse(G);
	printf("\n");

	system("pause");
	return 0;
}
