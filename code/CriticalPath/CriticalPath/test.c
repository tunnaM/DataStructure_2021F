#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CriticalPath.h"

int main()
{
	ALGraph G;
	CreateUDG(&G);
	CriticalPath(G);

	system("pause");
	return 0;
}