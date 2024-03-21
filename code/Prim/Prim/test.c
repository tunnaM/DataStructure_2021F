#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Prim.h"

int main()
{
	MGraph G;
	CreateUDN(&G);
	VertexType u = 1;
	MiniSpanTree_PRIM(G, u);

	system("pause");
	return 0;
}